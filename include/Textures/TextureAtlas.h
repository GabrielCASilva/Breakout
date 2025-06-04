#ifndef TEXTURE_ATLAS_H
#define TEXTURE_ATLAS_H
#include <array>
#include <cstdint>

#include "raylib.h"
#include "Utils/Constants.h"

enum class TextureBricksSingle: std::uint8_t {
    ORANGE_BRICK,
    PINK_BRICK,
    PURPLE_BRICK,
    GREEN_BRICK,
    RED_BRICK,
    METAL_BRICK,
    LEN
};

enum class TextureBricksDouble: std::uint8_t {
    ORANGE_BRICK,
    PINK_BRICK,
    PURPLE_BRICK,
    GREEN_BRICK,
    RED_BRICK,
    METAL_BRICK,
    LEN
};

enum class TextureEntities: std::uint8_t {
    PADDLE,
    BALL,
    LEN
};

constexpr std::array<Rectangle, static_cast<int>(TextureBricksSingle::LEN)> BricksSingle = {
    {
        {0, 0, game::grid::SIZE, game::grid::SIZE}, // Orange
        {0, game::grid::SIZE, game::grid::SIZE, game::grid::SIZE}, // Pink
        {0, game::grid::SIZE * 2, game::grid::SIZE, game::grid::SIZE}, // Purple
        {0, game::grid::SIZE * 3, game::grid::SIZE, game::grid::SIZE}, // green
        {0, game::grid::SIZE * 4, game::grid::SIZE, game::grid::SIZE}, // red
        {0, game::grid::SIZE * 5, game::grid::SIZE, game::grid::SIZE}, // metal
    }
};

constexpr std::array<Rectangle, static_cast<int>(TextureBricksDouble::LEN)> BricksDouble = {
    {
        {game::grid::SIZE, 0, game::grid::SIZE * 2, game::grid::SIZE}, // orange
        {game::grid::SIZE, game::grid::SIZE, game::grid::SIZE * 2, game::grid::SIZE}, // pink
        {game::grid::SIZE, game::grid::SIZE * 2, game::grid::SIZE * 2, game::grid::SIZE}, // purple
        {game::grid::SIZE, game::grid::SIZE * 3, game::grid::SIZE * 2, game::grid::SIZE}, // green
        {game::grid::SIZE, game::grid::SIZE * 4, game::grid::SIZE * 2, game::grid::SIZE}, // red
        {game::grid::SIZE, game::grid::SIZE * 5, game::grid::SIZE * 2, game::grid::SIZE}, // metal
    }
};

constexpr std::array<Rectangle, static_cast<int>(TextureEntities::LEN)> Entities = {
    {
        {game::grid::SIZE * 3, game::grid::SIZE / 2, game::grid::SIZE * 3, game::grid::SIZE / 2}, // paddle
        {game::grid::SIZE * 3 + 12, game::grid::SIZE + 12, 8, 8} // ball
    }
};

template<typename T>
class TextureAtlas {
    static inline Texture2D texture{};
    static inline std::array<Rectangle, static_cast<std::size_t>(T::LEN)> atlas{};
    static inline bool loaded = false;

public:
    static auto Load(const std::array<Rectangle, static_cast<std::size_t>(T::LEN)>& _atlas) -> void;

    static auto Unload() -> void;

    static auto GetTexture() -> Texture2D;

    static auto GetTextureImage(const T &texture) -> Rectangle;

    static auto GetRandomTextureImage(int max) -> T;

    static auto DefineTexture(const Rectangle &src, const Vector2 &position, Color color) -> void;

    static auto DefineTexturePro(const Rectangle &src, const Rectangle &dest, const Vector2& origin, float rotation, Color color) -> void;
};

#endif //TEXTURE_ATLAS_H
