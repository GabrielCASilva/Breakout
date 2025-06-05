#include "Entities/Paddle.h"

#include <cmath>

#include "Textures/TextureAtlas.h"

constexpr auto _size{Vector2{96.0f, 16.0f}};

Paddle::Paddle() : position{}, velocity{}, size{_size}, color{WHITE}, speed{}{}
Paddle::Paddle(const Vector2 position) : position {position},
    velocity{}, size{_size}, color{WHITE}, speed{100.f}{}

auto Paddle::Update(const float dt) -> void {
    this->Move(dt);
}

auto Paddle::Draw() const -> void {
    const Rectangle& texture = TextureAtlas<TextureEntities>::GetTextureImage(TextureEntities::PADDLE);
    TextureAtlas<TextureEntities>::DefineTexture(texture, position, color);
}

auto Paddle::Move(const float dt) -> void {
    if (IsKeyDown(KEY_LEFT)) {
        position.x -= speed*dt;
    }

    if (IsKeyDown(KEY_RIGHT)) {
        position.x += speed*dt;
    }
}

auto Paddle::GetPosition() const -> const Vector2& {
    return position;
}