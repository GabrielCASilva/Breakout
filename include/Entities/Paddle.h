#ifndef PADDLE_H
#define PADDLE_H
#include "IEntity.h"
#include "raylib.h"
#include "Utils/Constants.h"

class Paddle final : public IEntity {
    Vector2 position;
    Vector2 size{game::paddle::SIZE};
    Color color{WHITE};
    float speed{game::paddle::SPEED};

    auto Move(float dt) -> void;

    auto StayOnBounds() -> void;

public:
    Paddle() = delete;

    explicit Paddle(Vector2 position);

    Paddle(const Paddle &other) = delete;

    Paddle(Paddle &&other) = default;

    Paddle &operator=(const Paddle &other) = delete;

    auto Update(float dt) -> void override;

    auto Draw() const -> void override;

    auto OnCollision(const IEntity &entity) -> void override;

    // inlines
    [[nodiscard]] auto GetPosition() const -> const Vector2 & {
        return position;
    }

    [[nodiscard]] auto GetSize() const -> const Vector2 & {
        return size;
    }

};
#endif //PADDLE_H
