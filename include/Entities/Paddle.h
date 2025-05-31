#ifndef PADDLE_H
#define PADDLE_H
#include "IEntity.h"
#include "raylib.h"

class Paddle final : public IEntity {
private:
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
    Color color;
    float speed;
public:
    Paddle();
    explicit Paddle(Vector2 position);
    Paddle(const Paddle& other) = delete;
    Paddle(Paddle&& other) = default;
    Paddle& operator=(const Paddle& other) = delete;

    auto Update(float dt) -> void override;
    auto Draw() const -> void override;
};
#endif //PADDLE_H
