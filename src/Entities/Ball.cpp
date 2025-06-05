#include "Entities/Ball.h"

#include <cmath>
#include <iostream>

#include "Textures/TextureAtlas.h"

Ball::Ball():
    position{},
    velocity{},
    radius{8},
    color{GOLD},
    speed{},
    init_position{} {}

Ball::Ball(const Vector2 position):
    position{position},
    velocity{},
    radius{8},
    color{GOLD},
    speed{},
    init_position{position} {}

auto Ball::Update(float dt) -> void {
    position = init_position;
}

auto Ball::Draw() const -> void {
    const Rectangle& texture = TextureAtlas<TextureEntities>::GetTextureImage(TextureEntities::BALL);
    const Rectangle dest = { position.x, position.y, std::fabsf(texture.width), std::fabsf(texture.height) };
    const Vector2 origin = { texture.width/2, texture.height/2 };
    TextureAtlas<TextureEntities>::DefineTexturePro(texture, dest, origin, 0, color);
}

auto Ball::CheckCollisionWithBrick(const Brick &brick) const -> bool {
    return CheckCollisionCircleRec(position, radius, brick.GetCollisionArea());
}

auto Ball::DefineInitialPos(const Vector2& pos) -> void {
    init_position.x = pos.x + 48;
}
