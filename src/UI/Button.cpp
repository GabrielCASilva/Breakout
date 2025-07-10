#include "UI/Button.h"

#include <cmath>
#include <iostream>

#include "raylib.h"
#include "Textures/TextureAtlas.h"
#include "UI/Text.h"

auto Button::Draw() const -> void {
    // ReSharper disable once CppDFAConstantConditions
    if (m_isHovered) {
        // ReSharper disable once CppDFAUnreachableCode
        const Rectangle texture = TextureAtlas<TextureEntities>::GetTextureImage(
            TextureEntities::BTN_SELECTED_INDICATOR);
        const auto position = Vector2(
            m_position.x - (texture.width * game::SCALE) - 2 * game::SCALE,
            m_position.y + game::SCALE
        );
        TextureAtlas<TextureEntities>::DefineTexture(texture, position);

        const auto position2 = Vector2(
            m_position.x + m_size.x + 2 * game::SCALE,
            m_position.y + game::SCALE
        );
        TextureAtlas<TextureEntities>::DefineTexture(texture, position2);
    }

    Text::Draw(FontTypes::SIZE_20, m_text, m_textPosition, WHITE);
}

auto Button::DefineButtonAlign(const ButtonOrigins &origin) -> void {
    std::cout << static_cast<int>(origin) << std::endl;
    switch (origin) {
        case ButtonOrigins::CENTER:
            m_position.x -= m_size.x / 2.0f;
            m_textPosition = {
                .x = m_position.x,
                .y = m_position.y - m_size.y / 2.0f,
            };
            break;
        case ButtonOrigins::START:
        default:
            m_textPosition = m_position;
            break;
    }
}
