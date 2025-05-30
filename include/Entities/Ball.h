#ifndef BALL_H
#define BALL_H
#include <cstdint>

#include "IEntity.h"
#include "raylib.h"

class Ball final : public IEntity {
private:
    Vector2 position;
    Vector2 velocity;
    std::uint8_t radius;
    Color color;
    float speed;
public:
    Ball();
    explicit Ball(Vector2 position);
    Ball(const Ball& other) = delete;
    Ball(Ball&& other) = default;
    Ball& operator=(const Ball& other) = delete;

    auto Update(float dt) -> void override;
    auto Draw() -> void override;
};

#endif //BALL_H
