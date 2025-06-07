#ifndef BALL_H
#define BALL_H
#include <cstdint>

#include "Brick.h"
#include "IEntity.h"
#include "raylib.h"

class Ball final : public IEntity {
    Vector2 position;
    std::uint8_t radius;
    Color color;
    float speed;
    Vector2 direction;

    bool start_move;
    bool move_first_time;
    Vector2 init_position;

    auto MakeItMove() -> void;
    auto Move(float dt) -> void;

    auto StayOnBounds() -> void;
public:
    Ball() = delete;
    explicit Ball(Vector2 position);
    Ball(const Ball& other) = delete;
    Ball(Ball&& other) = default;
    Ball& operator=(const Ball& other) = delete;

    auto Update(float dt) -> void override;
    auto Draw() const -> void override;

    auto DefineInitialPos(const Vector2& pos) -> void;

    // collision detection
    [[nodiscard]] auto CheckCollisionWithBrick(const Brick& brick) const -> bool;

    auto OnCollision(const IEntity& entity) -> void override;
    auto Bounce(bool in_x, bool in_y) -> void;
};

#endif //BALL_H
