#ifndef BALL_H
#define BALL_H
#include <cstdint>

#include "Brick.h"
#include "IEntity.h"
#include "raylib.h"

class Ball final : public IEntity {
public:
    Ball() = delete;

    explicit Ball(Vector2 position);

    Ball(const Ball &other) = delete;

    Ball(Ball &&other) = default;

    Ball &operator=(const Ball &other) = delete;

    auto Update(float dt) -> void override;

    auto Draw() const -> void override;

    auto DefineInitialPos(const Vector2 &pos) -> void;

    // collision detection
    [[nodiscard]] auto CheckCollisionWithBrick(const Brick &brick) -> bool;

    auto OnCollision(const IEntity &entity) -> void override;

    auto Bounce(bool in_x, bool in_y) -> void;

    auto Reset() -> void {
        m_start_move = false;
        m_position = m_init_position;
    }

private:
    Vector2 m_position;
    std::uint8_t m_radius{game::ball::RADIUS};
    Color m_color{GOLD};
    float m_speed{game::ball::SPEED};
    Vector2 m_direction{0, 0};

    bool m_start_move{false};
    Vector2 m_init_position{m_position};

    auto MakeItMove() -> void;

    auto Move(float dt) -> void;

    auto StayOnBounds() -> void;

    [[nodiscard]] auto ModifyAngle(float hit_pos, float normalized_hit) const -> float;
};

#endif //BALL_H
