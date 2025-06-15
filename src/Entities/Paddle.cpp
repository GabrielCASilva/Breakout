#include "Entities/Paddle.h"

#include "Textures/TextureAtlas.h"

Paddle::Paddle(const Vector2 position) : position{position} {
}

auto Paddle::Update(const float dt) -> void {
    this->Move(dt);
}

auto Paddle::Draw() const -> void {
    const Rectangle &texture = TextureAtlas<TextureEntities>::GetTextureImage(TextureEntities::PADDLE);
    TextureAtlas<TextureEntities>::DefineTexture(texture, position, color);
}

auto Paddle::Move(const float dt) -> void {
    // vel += acc * dt;
    // pos += vel * dt; <-- speed = vel
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) position.x -= speed * dt;
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) position.x += speed * dt;
}

auto Paddle::OnCollision(const IEntity &entity) -> void {
}