#ifndef CURSOR_H
#define CURSOR_H
#include "raylib.h"
#include "Textures/TextureAtlas.h"

class Cursor {
public:
    Cursor() = delete;

    Cursor(const Cursor &other) = delete;

    Cursor(Cursor &&other) = delete;

    Cursor &operator=(const Cursor &other) = delete;

    Cursor &operator=(Cursor &&other) = delete;

    ~Cursor() = delete;

    static auto Draw() -> void {
        const Rectangle &texture = TextureAtlas<TextureEntities>::GetTextureImage(
            TextureEntities::CURSOR);

        const Vector2 mouse = GetMousePosition();
        TextureAtlas<TextureEntities>::DefineTexture(
            texture,
            mouse
        );
    }

    static auto SetIsHovered(const bool isHovered) -> void { m_isHovered = isHovered; }

    static auto Disable(const bool isDisabled) -> void { m_isDisabled = isDisabled; }

    static auto SetTexture(const Rectangle &texture) -> void { m_texture = texture; }

private:
    static inline bool m_isHovered{false};
    static inline bool m_isDisabled{false};
    static inline Rectangle m_texture;
};

#endif //CURSOR_H
