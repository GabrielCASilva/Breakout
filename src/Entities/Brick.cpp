#include "Entities/Brick.h"

#include <iostream>

#include "Utils/Grid.h"

Brick::Brick() : type{BrickTypes::Default}, size{1}, position{}, color{WHITE}{}

auto Brick::Update(float dt) -> void {}

auto Brick::Draw() const -> void {
    DrawRectangle(position.x, position.y, game::grid::SIZE, game::grid::SIZE, color);
}

auto Brick::Collider() -> void {
    std::cout << typeid(Brick).name() << std::endl;
}

auto Brick::SetPosition(const Vector2 &pos) -> void {
    position = pos;
}
