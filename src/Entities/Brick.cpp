#include "Entities/Brick.h"

#include <iostream>
#include <vector>

#include "Utils/Grid.h"
#include "Utils/TextureLoader.h"

Brick::Brick(const BrickTypes &type, const BrickLengths &length, const Vector2 &position): type{type},
    length{length},
    position{position},
    color{WHITE},
    is_destroyed{false},
    lives{1},
    texture{BrickTextures::Default},
    collision_area{position.x, position.y, game::grid::SIZE, game::grid::SIZE} {
    sprite_positions.push_back(position.x);
}

auto Brick::Update(float dt) -> void {
}

auto Brick::Draw() const -> void {
    switch (sprite_positions.size()) {
        case 1:
            this->DefineTexture({0, 0, game::grid::SIZE, game::grid::SIZE});
            break;
        case 2:
            this->DefineTexture(
                {game::grid::SIZE, 0, game::grid::SIZE * 2, game::grid::SIZE}
                );
            break;
        default:
            this->DefineTexture({0, 0, game::grid::SIZE, game::grid::SIZE});
            break;
    }
}

auto Brick::IncriseSize(const int pos_x) -> void {
    collision_area.width += game::grid::SIZE;
    sprite_positions.push_back(pos_x);
}

auto Brick::Destroy() -> void {
    is_destroyed = true;
}

auto Brick::IsDestroyed() const -> bool {
    return is_destroyed;
}

auto Brick::GetSpritePositions() const -> std::vector<int> {
    return sprite_positions;
}

auto Brick::GetCollisionArea() const -> Rectangle {
    return collision_area;
}

auto Brick::DefineTexture(const Rectangle &&src) const -> void {
    DrawTextureRec(TextureLoader::texture, src, position, color);
}

auto Brick::RandomizeTexture() -> void {

}
