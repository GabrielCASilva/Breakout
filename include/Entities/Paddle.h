#ifndef PADDLE_H
#define PADDLE_H
#include "IEntity.h"
#include "raylib.h"
#include "Utils/Constants.h"

class Paddle final : public IEntity {
public:
    Paddle() = delete;

    explicit Paddle(Vector2 position);

    Paddle(const Paddle &other) = delete;

    Paddle(Paddle &&other) = default;

    Paddle &operator=(const Paddle &other) = delete;

    auto Update(float dt) -> void override;

    auto Draw() const -> void override;

    auto OnCollision(const IEntity &entity) -> void override;

    [[nodiscard]] auto GetPosition() const -> const Vector2 & { return m_position; }

    [[nodiscard]] auto GetSize() const -> const Vector2 & { return m_size; }

private:
    auto Move(float dt) -> void;

    auto StayOnBounds() -> void;

    Vector2 m_position;
    Vector2 m_size{game::paddle::SIZE};
    Color m_color{WHITE};
    float m_speed{game::paddle::SPEED};
};
#endif //PADDLE_H
