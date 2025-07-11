#ifndef TEXTURE_ATLAS_H
#define TEXTURE_ATLAS_H
#include <array>
#include <cstdint>

#include "raylib.h"
#include "Utils/Constants.h"

enum class TextureBricksSingle: std::uint8_t {
    RED_BRICK,
    ORANGE_BRICK,
    PURPLE_BRICK,
    YELLOW_BRICK,
    GREEN_BRICK,
    BLUE_BRICK,
    METAL_BRICK,
    LEN
};

enum class TextureBricksDouble: std::uint8_t {
    RED_BRICK,
    ORANGE_BRICK,
    PURPLE_BRICK,
    YELLOW_BRICK,
    GREEN_BRICK,
    BLUE_BRICK,
    METAL_BRICK,
    LEN
};

enum class TextureEntities: std::uint8_t {
    PADDLE,
    BALL,
    TITLE,
    CURSOR_NORMAL,
    CURSOR_HOVER,
    BTN_SELECTED_INDICATOR,
    LEN
};

constexpr std::array<Rectangle, static_cast<int>(TextureBricksSingle::LEN)> BricksSingle = {
    {
        {8 * 2, 0, 8, 8}, // red
        {8 * 2, 8, 8, 8}, // orange
        {8 * 2, 8 * 2, 8, 8}, // purple
        {8 * 5, 0, 8, 8}, // yellow
        {8 * 5, 8, 8, 8}, // green
        {8 * 5, 8 * 2, 8, 8}, // blue
        {8 * 5, 8 * 2, 8, 8}, // metal
    }
};

constexpr std::array<Rectangle, static_cast<int>(TextureBricksDouble::LEN)> BricksDouble = {
    {
        {0, 0, 8 * 2, 8}, // red
        {0, 8, 8 * 2, 8}, // orange
        {0, 8 * 2, 8 * 2, 8}, // purple
        {8 * 3, 0, 8 * 2, 8}, // yellow
        {8 * 3, 8, 8 * 2, 8}, // green
        {8 * 3, 8 * 2, 8 * 2, 8}, // blue
        {8 * 3, 8 * 2, 8 * 2, 8}, // metal
    }
};

constexpr std::array<Rectangle, static_cast<int>(TextureEntities::LEN)> Entities = {
    {
        {0, 8 * 4, 8 * 5, 4}, // paddle
        {8 * 7, 8 * 4, 8, 8}, // ball
        {0, 8 * 5, 8 * 23, 8 * 4}, // title
        {8 * 10, 8 * 3, 8, 8}, // cursor normal
        {8 * 11, 8 * 3, 8, 8}, // cursor hover
        {8 * 8, 8 * 4, 8, 8}, // button selected indicator
    }
};

template<typename T>
class TextureAtlas {
    static inline Texture2D texture{};
    static inline std::array<Rectangle, static_cast<std::size_t>(T::LEN)> atlas{};
    static inline bool loaded = false;

public:
    static auto Load(const std::array<Rectangle, static_cast<std::size_t>(T::LEN)> &_atlas) -> void;

    static auto Unload() -> void;

    static auto GetTexture() -> Texture2D;

    static auto GetTextureImage(const T &texture) -> Rectangle;

    static auto GetRandomTextureImage(int max) -> T;

    // TODO: Some parts of this code are C like, change (float) to static_cast in de future
    static auto DefineTexture(const Rectangle &src, const Vector2 &position, const Vector2 origin = {0, 0}) -> void {
        const Rectangle dest = {
            position.x, position.y, (float) src.width * game::SCALE, (float) src.height * game::SCALE
        };
        const Vector2 originScaled = {origin.x * game::SCALE, origin.y * game::SCALE};
        DrawTexturePro(texture, src, dest, originScaled, 0.0, WHITE);
    }
};

#endif //TEXTURE_ATLAS_H
