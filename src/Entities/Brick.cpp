#include "Entities/Brick.h"

#include <iostream>
#include <vector>

#include "Textures/TextureAtlas.h"
#include "Utils/Grid.h"
#include "Utils/TextureLoader.h"

Brick::Brick(const BrickTypes &type, const BrickLengths &length, const Vector2 &position): type{type},
    length{length},
    position{position},
    color{WHITE},
    is_destroyed{false},
    lives{1},
    collision_area{position.x, position.y, game::grid::SIZE, game::grid::SIZE} {
    sprite_positions.push_back(position.x);

    constexpr int max {static_cast<int>(TextureBricksSingle::LEN) - 1};
    const TextureBricksSingle &brick{TextureAtlas<TextureBricksSingle>::GetRandomTextureImage(max)};
    texture = TextureAtlas<TextureBricksSingle>::GetTextureImage(brick);
}

auto Brick::Update(float dt) -> void {
}

auto Brick::Draw() const -> void {
    switch (sprite_positions.size()) {
        case 1: {
            TextureAtlas<TextureBricksSingle>::DefineTexture(texture, position, color);
            break;
        }
        case 2: {
            TextureAtlas<TextureBricksDouble>::DefineTexture(texture, position, color);
            break;
        }
        default:
            TextureAtlas<TextureBricksSingle>::DefineTexture(texture, position, color);
            break;
    }
}

auto Brick::IncriseSize(const int pos_x) -> void {
    collision_area.width += game::grid::SIZE;
    sprite_positions.push_back(pos_x);
    texture = this->DefineRandomTexture();
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

auto Brick::DefineRandomTexture() -> Rectangle {
    switch (sprite_positions.size()) {
        case 1: {
            constexpr int max {static_cast<int>(TextureBricksSingle::LEN) - 1};
            const TextureBricksSingle &brick{TextureAtlas<TextureBricksSingle>::GetRandomTextureImage(max)};
            return TextureAtlas<TextureBricksSingle>::GetTextureImage(brick);
        }
        case 2: {
            constexpr int max {static_cast<int>(TextureBricksSingle::LEN) - 1};
            const TextureBricksDouble &brick{TextureAtlas<TextureBricksDouble>::GetRandomTextureImage(max)};
            return TextureAtlas<TextureBricksDouble>::GetTextureImage(brick);
        }
        default: {
            constexpr int max {static_cast<int>(TextureBricksSingle::LEN) - 1};
            const TextureBricksSingle &brick{TextureAtlas<TextureBricksSingle>::GetRandomTextureImage(max)};
            return TextureAtlas<TextureBricksSingle>::GetTextureImage(brick);
        }
    }
}
