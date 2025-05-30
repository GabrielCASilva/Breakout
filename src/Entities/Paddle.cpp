#include "Entities/Paddle.h"

constexpr auto _size{Vector2{100.0f, 20.0f}};

Paddle::Paddle() : position{}, velocity{}, size{_size}, color{WHITE}, speed{}{}
Paddle::Paddle(const Vector2 position) : position {position},
    velocity{}, size{_size}, color{WHITE}, speed{}{}


auto Paddle::Update(float dt) -> void {
}

auto Paddle::Draw() -> void {
    const auto pos_x {static_cast<int>(position.x)};
    const auto pos_y {static_cast<int>(position.y)};
    const auto width {static_cast<int>(size.x)};
    const auto height {static_cast<int>(size.y)};
    DrawRectangle(pos_x, pos_y, width, height, color);
}
