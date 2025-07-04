#include "Entities/Paddle.h"

#include "Textures/TextureAtlas.h"

Paddle::Paddle(const Vector2 position) : position{position} {
}

auto Paddle::Update(const float dt) -> void {
    this->Move(dt);
}

auto Paddle::Draw() const -> void {
    const Rectangle &texture = TextureAtlas<TextureEntities>::GetTextureImage(TextureEntities::PADDLE);
    TextureAtlas<TextureEntities>::DefineTexture2(texture, position);
    // Rectangle source = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
    // Rectangle dest = { position.x, position.y, (float)texture.width*game::SCALE, (float)texture.height*game::SCALE };
    // Vector2 origin = { 0.0f, 0.0f };
    // DrawTexturePro(TextureAtlas<TextureEntities>::GetTexture(), source, dest, origin, 0.0, WHITE);

    // TextureAtlas<TextureEntities>::DefineTexturePro(source, dest, origin, 0.0, WHITE);
}

auto Paddle::Move(const float dt) -> void {
    // vel += acc * dt;
    // pos += vel * dt; <-- speed = vel
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) position.x -= speed * dt;
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) position.x += speed * dt;
}

auto Paddle::OnCollision(const IEntity &entity) -> void {
}