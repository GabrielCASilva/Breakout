#include "Entities/Brick.h"

#include <iostream>

#include "Utils/Grid.h"
#include "Utils/TextureLoader.h"

Brick::Brick() : type{BrickTypes::Default}, size{1}, position{}, color{WHITE}{}

auto Brick::Update(float dt) -> void {}

auto Brick::Draw() const -> void {
    constexpr Rectangle src = { 0, 0, game::grid::SIZE, game::grid::SIZE };
    DrawTextureRec(TextureLoader::texture, src, position, WHITE);
}

auto Brick::Collider() -> void {
    std::cout << typeid(Brick).name() << std::endl;
}

auto Brick::SetPosition(const Vector2 &pos) -> void {
    position = pos;
}
