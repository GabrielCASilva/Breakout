#ifndef DRAW_SPRITE_H
#define DRAW_SPRITE_H
#include "Constants.h"
#include "raylib.h"

class DrawSprite {
public:
    static auto Draw(const Texture2D &texture, const Vector2 &position, const Color tint = WHITE) -> void {
        const Rectangle source = {
            0.0f,
            0.0f,
            static_cast<float>(texture.width),
            static_cast<float>(texture.height)
        };
        const Rectangle dest = {
            position.x,
            position.y,
            static_cast<float>(texture.width * game::SCALE),
            static_cast<float>(texture.height * game::SCALE)
        };
        constexpr Vector2 origin{0.0f, 0.0f};
        constexpr float rotation{0.0f};
        DrawTexturePro(texture, source, dest, origin, rotation, tint);
    }

    static auto Draw(const Texture2D &texture, const Vector2 &position,
                     const Vector2 &origin, const float rotation = 0.0f, const Color tint = WHITE
    ) -> void {
        const Rectangle source = {
            0.0f,
            0.0f,
            static_cast<float>(texture.width),
            static_cast<float>(texture.height)
        };
        const Rectangle dest = {
            position.x,
            position.y,
            static_cast<float>(texture.width * game::SCALE),
            static_cast<float>(texture.height * game::SCALE)
        };
        DrawTexturePro(texture, source, dest, origin, rotation, tint);
    }
};

#endif //DRAW_SPRITE_H
