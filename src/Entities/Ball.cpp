#include "Entities/Ball.h"

Ball::Ball(): position{}, velocity{}, radius{5}, color{GOLD}, speed{} {
}

Ball::Ball(const Vector2 position): position{position}, velocity{}, radius{5}, color{GOLD}, speed{}  {
}

auto Ball::Update(float dt) -> void {

}

auto Ball::Draw() -> void {
    const auto pos_x {static_cast<int>(position.x)};
    const auto pos_y {static_cast<int>(position.y)};
    DrawCircle(pos_x, pos_y, radius, color);
}
