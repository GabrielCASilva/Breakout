#ifndef BALL_H
#define BALL_H
#include <cstdint>

#include "Brick.h"
#include "IEntity.h"
#include "raylib.h"

class Ball final : public IEntity {
    Vector2 position;
    Vector2 velocity;
    std::uint8_t radius;
    Color color;
    float speed;

    Vector2 init_position;
public:
    Ball();
    explicit Ball(Vector2 position);
    Ball(const Ball& other) = delete;
    Ball(Ball&& other) = default;
    Ball& operator=(const Ball& other) = delete;

    auto Update(float dt) -> void override;
    auto Draw() const -> void override;

    // collision detection
    [[nodiscard]] auto CheckCollisionWithBrick(const Brick& brick) const -> bool;
    auto DefineInitialPos(const Vector2& pos) -> void;
};

#endif //BALL_H
