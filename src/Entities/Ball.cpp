#include "Entities/Ball.h"

#include <algorithm>
#include <cmath>
#include <iostream>

#include "Entities/Paddle.h"
#include "States/PlayerData.h"
#include "Textures/TextureAtlas.h"

Ball::Ball(const Vector2 position): m_position{position} {
}

auto Ball::Update(const float dt) -> void {
    if (!m_start_move) {
        m_position = m_init_position;
        this->MakeItMove();
    } else {
        this->Move(dt);
        this->StayOnBounds();
    }
}

// TODO: tirar isso da bola
Vector2 get_normal(const float x, const float y) {
    float mouse_x = GetMousePosition().x;
    float mouse_y = GetMousePosition().y;

    float dis_x = mouse_x - x;
    float dis_y = mouse_y - y;

    float len = std::sqrtf(dis_x * dis_x + dis_y * dis_y);
    float normal_x = dis_x / len;
    float normal_y = dis_y / len;
    normal_x *= 20;
    normal_y *= 20;
    return Vector2(normal_x, normal_y);
}

auto Ball::Draw() const -> void {
    const Rectangle &texture = TextureAtlas<TextureEntities>::GetTextureImage(TextureEntities::BALL);
    TextureAtlas<TextureEntities>::DefineTexture(texture, m_position, {texture.width / 2, texture.height / 2});
    if (!m_start_move) {
        float x = m_position.x;
        float y = m_position.y;
        Vector2 n1 = get_normal(x, y);
        Vector2 n2 = get_normal(x + n1.x, y + n1.y);
        DrawLineEx({x + n1.x, y + n1.y}, {x + n1.x + n2.x, y + n1.y + n2.y}, 2.0f, RED);
    }
}

auto Ball::CheckCollisionWithBrick(const Brick &brick) -> bool {
    if (CheckCollisionCircleRec(m_position, m_radius, brick.GetCollisionArea())) {
        const auto &[p_x, p_y, p_width, p_height] = brick.GetCollisionArea();
        // bordas do quadrado
        const float left_edge = p_x;
        const float right_edge = p_x + p_width;
        const float top_edge = p_y;
        const float bottom_edge = p_y + p_height;

        // "bordas" do circulo
        const float my_top = m_position.y - static_cast<float>(m_radius);
        const float my_bottom = m_position.y + static_cast<float>(m_radius);
        const float my_left = m_position.x - static_cast<float>(m_radius);
        const float my_right = m_position.x + static_cast<float>(m_radius);

        // calculando o momento de sobreposição das bordas
        const float overlap_left = std::fabs(my_right - left_edge);
        const float overlap_right = std::fabs(my_left - right_edge);
        const float overlap_top = std::fabs(my_bottom - top_edge);
        const float overlap_bottom = std::fabs(my_top - bottom_edge);

        // calculando qual a menor distancia entre cada borda
        const float min_overlap_x = std::min(overlap_left, overlap_right);
        const float min_overlap_y = std::min(overlap_top, overlap_bottom);

        if (std::abs(min_overlap_x - min_overlap_y) < 1.0f * game::SCALE) {
            Bounce(true,true);
        } else if (min_overlap_x < min_overlap_y) {
            // correção da posição da bola
            m_position.x = overlap_left < overlap_right
                               ? m_position.x - overlap_left - 1
                               : m_position.x + overlap_right + 1;
            Bounce(true, false);
        } else {
            // correção da posição da bola
            m_position.y = overlap_top < overlap_bottom
                               ? m_position.y - overlap_top - 1
                               : m_position.y + overlap_bottom + 1;
            Bounce(false, true);
        }

        return true;
    }
    return false;
}

auto Ball::OnCollision(const IEntity &entity) -> void {
    if (const auto paddle = dynamic_cast<const Paddle *>(&entity)) {
        const auto &[p_x, p_y] = paddle->GetPosition();
        const auto &[p_width, p_height] = paddle->GetSize();
        if (CheckCollisionCircleRec(m_position, m_radius, {p_x, p_y, p_width, p_height})) {
            const float pw_center{p_x + p_width / 2.0f};

            // distancia entre a bola e o centro do paddle dividido pela metade do comprimento do paddle
            // resultando na posição normalizada entre o paddle e a bola [-1 - 0 - 1]
            const float hit_pos{(m_position.x - pw_center) / (p_width / 2.0f)};

            const float normalized_hit = std::clamp(hit_pos, -1.0f, 1.0f);

            // fazer a bola rebater sempre para cima
            m_direction.y = -std::abs(m_direction.y);

            // calculando a direção no x a partir do ângulo
            m_direction.x = normalized_hit * std::abs(ModifyAngle(hit_pos, normalized_hit));

            // normalizando o vetor
            const float mag = std::sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y);
            m_direction.x /= mag;
            m_direction.y /= mag;
        }
    } else {
        std::cout << "Colisão qualquer\n";
    }
}

auto Ball::Bounce(const bool in_x, const bool in_y) -> void {
    if (in_x) m_direction.x *= -1;
    if (in_y) m_direction.y *= -1;
}

auto Ball::MakeItMove() -> void {
    // Faz a bola se moder na direção que o mouse está
    const auto [x, y] = GetMousePosition();
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        const Vector2 new_position{x - m_position.x, y - m_position.y};
        const auto magnitude{std::sqrt(new_position.x * new_position.x + new_position.y * new_position.y)};
        m_direction.x = new_position.x / magnitude;
        m_direction.y = new_position.y / magnitude;
        m_start_move = true;
    }
}

auto Ball::Move(const float dt) -> void {
    m_position.x += m_speed * dt * m_direction.x;
    m_position.y += m_speed * dt * m_direction.y;
}

auto Ball::StayOnBounds() -> void {
    if (m_position.x > (game::WINDOW_WIDTH - game::SCALE * 2)) {
        m_position.x = static_cast<float>(game::WINDOW_WIDTH - m_radius - game::SCALE);
        this->Bounce(true, false);
    }

    if (m_position.x < game::SCALE) {
        m_position.x = static_cast<float>(game::SCALE + m_radius);
        this->Bounce(true, false);
    }

    if (m_position.y > game::WINDOW_HEIGHT) {
        PlayerData::DecrementLives();
        Reset();
    }

    if (m_position.y < 0) {
        m_position.y = static_cast<float>(game::SCALE + m_radius);
        this->Bounce(false, true);
    }
}

auto Ball::ModifyAngle(const float hit_pos, const float normalized_hit) const -> float {
    const float dynamic = 0.3f * (1.0f - std::clamp(normalized_hit, 0.0f, 1.0f)); // dinâmico pela direção
    const float dir_preference = 0.1f * std::abs(hit_pos); // acentua a direção que a bola vai
    const float non_linear = std::pow(std::abs(hit_pos), 1.2f); // curva não linear
    return (0.6f + dynamic + dir_preference) * non_linear * normalized_hit;
}
