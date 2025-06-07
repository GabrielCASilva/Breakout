#ifndef PADDLE_H
#define PADDLE_H
#include "IEntity.h"
#include "raylib.h"

class Paddle final : public IEntity {
    Vector2 position;
    Vector2 size;
    Color color;
    float speed;

    auto Move(float dt) -> void;
    auto StayOnBounds() -> void;
public:
    Paddle();
    explicit Paddle(Vector2 position);
    Paddle(const Paddle& other) = delete;
    Paddle(Paddle&& other) = default;
    Paddle& operator=(const Paddle& other) = delete;

    auto Update(float dt) -> void override;
    auto Draw() const -> void override;

    auto OnCollision(const IEntity& entity) -> void override;

    // get set
    [[nodiscard]] auto GetPosition() const -> const Vector2&;
    [[nodiscard]] auto GetSize() const -> const Vector2&;
};
#endif //PADDLE_H
