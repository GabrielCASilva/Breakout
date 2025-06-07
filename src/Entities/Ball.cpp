#include "Entities/Ball.h"

#include <cmath>
#include <iostream>

#include "Entities/Paddle.h"
#include "Textures/TextureAtlas.h"

Ball::Ball(const Vector2 position): position{position},
                                    radius{game::ball::RADIUS},
                                    color{GOLD},
                                    speed{game::ball::SPEED},
                                    direction{0, 1},
                                    start_move{false},
                                    move_first_time{true},
                                    init_position{position} {
}

auto Ball::Update(const float dt) -> void {
    if (!start_move) {
        position = init_position;
        this->MakeItMove();
    } else {
        this->Move(dt);
        // do something...

        this->StayOnBounds();
    }
}

// TODO: remember to test the ball bigger
auto Ball::Draw() const -> void {
    const Rectangle &texture = TextureAtlas<TextureEntities>::GetTextureImage(TextureEntities::BALL);
    const Rectangle dest = {position.x, position.y, std::fabsf(texture.width*1.5), std::fabsf(texture.height*1.5)};
    const Vector2 origin = {texture.width / 2, texture.height / 2};
    TextureAtlas<TextureEntities>::DefineTexturePro(texture, dest, origin, 0, color);
}

auto Ball::CheckCollisionWithBrick(const Brick &brick) const -> bool {
    return CheckCollisionCircleRec(position, radius, brick.GetCollisionArea());
}

auto Ball::OnCollision(const IEntity &entity) -> void {
    if (const auto paddle = dynamic_cast<const Paddle *>(&entity)) {
        const auto &[p_x, p_y] = paddle->GetPosition();
        const auto &[s_x, s_y] = paddle->GetSize();
        if (CheckCollisionCircleRec(position, radius, {p_x, p_y, s_x, s_y})) {
            // TODO:
            std::cout << "Colisão raquete\n";
            if (move_first_time) {
                direction.x = 1;
                direction.y = -1;
                move_first_time = false;
            } else {
                this->Bounce(false, true);
            }
        }
    } else {
        std::cout << "Colisão qualquer\n";
    }
}

auto Ball::Bounce(const bool in_x, const bool in_y) -> void {
    if (in_x) direction.x *= -1;
    if (in_y) direction.y *= -1;
}


auto Ball::DefineInitialPos(const Vector2 &pos) -> void {
    init_position.x = pos.x + game::paddle::SIZE.x / 2;
}

auto Ball::MakeItMove() -> void {
    if (IsKeyPressed(KEY_SPACE)) {
        start_move = true;
    }
}

auto Ball::Move(const float dt) -> void {
    position.x += speed * dt * direction.x;
    position.y += speed * dt * direction.y;
}

auto Ball::StayOnBounds() -> void {
    if (position.x > game::WINDOW_WIDTH) {
        position.x = static_cast<float>(game::WINDOW_WIDTH) - static_cast<float>(radius);
        this->Bounce(true, false);
    }

    if (position.x < 0) {
        position.x = radius;
        this->Bounce(true, false);
    }

    // TODO: remove this collision part, the ball needs to pass throw the height of screen
    if (position.y > game::WINDOW_HEIGHT) {
        position.y = static_cast<float>(game::WINDOW_HEIGHT) - static_cast<float>(radius);
        this->Bounce(false, true);
    }

    if (position.y < 0) {
        position.y = radius;
        this->Bounce(false, true);
    }
}
