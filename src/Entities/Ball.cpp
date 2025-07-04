#include "Entities/Ball.h"

#include <algorithm>
#include <cmath>
#include <iostream>

#include "Entities/Paddle.h"
#include "GlobalStates/PlayerData.h"
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

auto Ball::Draw() const -> void {
    const Rectangle &texture = TextureAtlas<TextureEntities>::GetTextureImage(TextureEntities::BALL);
    TextureAtlas<TextureEntities>::DefineTexture2(texture, m_position, {texture.width/2, texture.height/2});
}

auto Ball::CheckCollisionWithBrick(const Brick &brick) -> bool {
    if (CheckCollisionCircleRec(m_position, m_radius, brick.GetCollisionArea())) {
        const auto &[p_x, p_y, p_width, p_height] = brick.GetCollisionArea();
        // Calcula os limites do bloco
        const float brick_left = p_x;
        const float brick_right = p_x + p_width;
        const float brick_top = p_y;
        const float brick_bottom = p_y + p_height;

        // Calcula a sobreposição em cada eixo
        const float overlap_left = m_position.x + m_radius - brick_left;
        const float overlap_right = brick_right - (m_position.x - m_radius);
        const float overlap_top = m_position.y + m_radius - brick_top;
        const float overlap_bottom = brick_bottom - (m_position.y - m_radius);

        // Verifica se há colisão (deveria ser verdadeiro já que estamos aqui)
        if (overlap_left > 0 && overlap_right > 0 && overlap_top > 0 && overlap_bottom > 0) {
            // Encontra a menor sobreposição
            const float min_overlap_x = std::min(overlap_left, overlap_right);
            const float min_overlap_y = std::min(overlap_top, overlap_bottom);

            const float bias = 1.0f; // ajuste conforme necessário
            if (std::abs(min_overlap_x - min_overlap_y) < bias) {
                // Quando muito próximo de um canto, rebate nos dois eixos
                this->Bounce(true, true);
            } else if (min_overlap_x < min_overlap_y) {
                this->Bounce(true, false);
            } else {
                this->Bounce(false, true);
            }
            return true;
        }
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

auto Ball::DefineInitialPos(const Vector2 &pos) -> void {
    m_init_position.x = pos.x + game::paddle::SIZE.x / 2;
}

auto Ball::MakeItMove() -> void {
    // Faz a bola se moder na direção que o mouse está
    const auto [x, y] = GetMousePosition();
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        const Vector2 new_position {x - m_position.x, y - m_position.y};
        const auto magnitude {std::sqrt(new_position.x * new_position.x + new_position.y * new_position.y)};
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