#include "Entities/Paddle.h"

#include "Textures/TextureAtlas.h"

constexpr auto _size{Vector2{96.0f, 16.0f}};

Paddle::Paddle() : position{}, velocity{}, size{_size}, color{WHITE}, speed{}{}
Paddle::Paddle(const Vector2 position) : position {position},
    velocity{}, size{_size}, color{WHITE}, speed{}{}

auto Paddle::Update(float dt) -> void {}

auto Paddle::Draw() const -> void {
    const Rectangle& texture = TextureAtlas<TextureEntities>::GetTextureImage(TextureEntities::PADDLE);
    TextureAtlas<TextureEntities>::DefineTexture(texture, position, color);
}
