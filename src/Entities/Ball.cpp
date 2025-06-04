#include "Entities/Ball.h"

#include <cmath>

#include "Textures/TextureAtlas.h"

Ball::Ball(): position{}, velocity{}, radius{8}, color{GOLD}, speed{} {}

Ball::Ball(const Vector2 position): position{position}, velocity{}, radius{5}, color{GOLD}, speed{}  {}

auto Ball::Update(float dt) -> void {
    // position.x = GetMousePosition().x;
    // position.y = GetMousePosition().y;
}

auto Ball::Draw() const -> void {
    const Rectangle& texture = TextureAtlas<TextureEntities>::GetTextureImage(TextureEntities::BALL);
    Rectangle dest = { position.x, position.y, std::fabsf(texture.width), std::fabsf(texture.height) };
    Vector2 origin = { texture.width/2, texture.height/2 };
    TextureAtlas<TextureEntities>::DefineTexturePro(texture, dest, origin, 0, color);
}

auto Ball::CheckCollisionWithBrick(const Brick &brick) const -> bool {
    return CheckCollisionCircleRec(position, radius, brick.GetCollisionArea());
}
