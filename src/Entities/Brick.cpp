#include "Entities/Brick.h"

#include <iostream>
#include <vector>

#include "Textures/TextureAtlas.h"

Brick::Brick(const BrickTypes &type, const BrickLengths &length, const Vector2 &position): type{type},
    length{length},
    position{position} {
    sprite_positions.push_back(static_cast<int>(position.x));
    constexpr int max{static_cast<int>(TextureBricksSingle::LEN) - 1};
    const TextureBricksSingle &brick{TextureAtlas<TextureBricksSingle>::GetRandomTextureImage(max)};
    texture = TextureAtlas<TextureBricksSingle>::GetTextureImage(brick);
}

auto Brick::Update(float dt) -> void {
}

auto Brick::Draw() const -> void {
    switch (sprite_positions.size()) {
        case 1: {
            TextureAtlas<TextureBricksSingle>::DefineTexture2(texture, position);
            break;
        }
        case 2: {
            TextureAtlas<TextureBricksDouble>::DefineTexture2(texture, position);
            break;
        }
        default:
            TextureAtlas<TextureBricksSingle>::DefineTexture2(texture, position);
            break;
    }
}

auto Brick::IncreaseSize(const int pos_x) -> void {
    collision_area.width += game::grid::SIZE;
    sprite_positions.push_back(pos_x);
    texture = this->DefineRandomTexture();
}

auto Brick::DefineRandomTexture() const -> Rectangle {
    switch (sprite_positions.size()) {
        case 1: {
            constexpr int max{static_cast<int>(TextureBricksSingle::LEN) - 1};
            const TextureBricksSingle &brick{TextureAtlas<TextureBricksSingle>::GetRandomTextureImage(max)};
            return TextureAtlas<TextureBricksSingle>::GetTextureImage(brick);
        }
        case 2: {
            constexpr int max{static_cast<int>(TextureBricksSingle::LEN) - 1};
            const TextureBricksDouble &brick{TextureAtlas<TextureBricksDouble>::GetRandomTextureImage(max)};
            return TextureAtlas<TextureBricksDouble>::GetTextureImage(brick);
        }
        default: {
            constexpr int max{static_cast<int>(TextureBricksSingle::LEN) - 1};
            const TextureBricksSingle &brick{TextureAtlas<TextureBricksSingle>::GetRandomTextureImage(max)};
            return TextureAtlas<TextureBricksSingle>::GetTextureImage(brick);
        }
    }
}

auto Brick::OnCollision(const IEntity &entity) -> void {
    // Do something
}