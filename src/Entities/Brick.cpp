#include "Entities/Brick.h"

#include <iostream>
#include <vector>

#include "Utils/Grid.h"
#include "Utils/TextureLoader.h"

Brick::Brick() : type{BrickTypes::Default}, length{}, size{1}, position{}, color{WHITE}, is_destroyed{false},
                 rect_area{} {
}

auto Brick::Update(float dt) -> void {}

auto Brick::Draw() const -> void {
    if (sprite_positions.size() == 1) {
        constexpr Rectangle src = { 0, 0, game::grid::SIZE, game::grid::SIZE };
        DrawTextureRec(TextureLoader::texture, src, position, color);
    }
    else if (sprite_positions.size() == 2) {
        constexpr Rectangle src = { 32, 0, game::grid::SIZE, game::grid::SIZE };
        DrawTextureRec(TextureLoader::texture, src, position, color);
        constexpr Rectangle src2 = { 95, 0, game::grid::SIZE-1, game::grid::SIZE };

        const Vector2 pos2 {position.x+32, position.y};
        DrawTextureRec(TextureLoader::texture, src2, pos2, color);
    }
    else if (sprite_positions.size() == 3) {
        constexpr Rectangle src = { 32, 0, game::grid::SIZE * 3, game::grid::SIZE };
        DrawTextureRec(TextureLoader::texture, src, position, color);
    }
}

auto Brick::Collider() -> void {
    std::cout << typeid(Brick).name() << std::endl;
}

auto Brick::SetPosition(const Vector2 &pos) -> void {
    position = pos;
}

auto Brick::GetPosition() const -> Vector2 {
    return position;
}

auto Brick::AddSize() -> void {
    size += 1;
}

auto Brick::GetSpritePositions() const -> std::vector<int> {
    return sprite_positions;
}

auto Brick::PushSpritePositions(int x) -> void {
    sprite_positions.push_back(x);
}

auto Brick::GetLength() const -> BrickLengths {
    return length;
}

auto Brick::SetLength(const BrickLengths l) -> void {
    length = l;
}

auto Brick::GetRectangle() const -> Rectangle {
    return rect_area;
}

auto Brick::SetRectangle(const Rectangle &r) -> void {
    rect_area = r;
}

auto Brick::IncreaseRectangle() -> void {
    rect_area.width += 32;
}

auto Brick::Destroy() -> void {
    is_destroyed = true;
}

auto Brick::IsDestroyed() const -> bool {
    return is_destroyed;
}


// Friends
std::ostream& operator<<(std::ostream& os, const Brick& brick) {
    os << "Position: [" << brick.GetPosition().x << brick.GetPosition().y << "]";
    return os;
}
