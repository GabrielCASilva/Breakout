#include "Textures/TextureAtlas.h"

#include <random>

#include "Utils/Constants.h"
#include "Utils/TextureLoader.h"

template <typename T>
auto TextureAtlas<T>::Load(const std::array<Rectangle, static_cast<std::size_t>(T::LEN)>& _atlas) -> void {
    if (loaded) return;

    texture = TextureLoader::Load("bricks");
    SetTextureFilter(texture, TEXTURE_FILTER_POINT);
    atlas = _atlas;

    loaded = true;
}

template <typename T>
auto TextureAtlas<T>::Unload() -> void {
    if (!loaded) return;
    UnloadTexture(texture);
    loaded = false;
}

template <typename T>
auto TextureAtlas<T>::GetTexture() -> Texture2D {
    return texture;
}

template <typename T>
auto TextureAtlas<T>::GetTextureImage(const T& texture) -> Rectangle {
    return atlas[static_cast<int>(texture)];
}

// TODO: DESCONSIDERAR NO RANDOM A TEXTURA METÁLICA
template <typename T>
auto TextureAtlas<T>::GetRandomTextureImage(const int max) -> T {
    static_assert(std::is_enum_v<T>, "T must be an enum");

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution dist(0, max - 1);

    return static_cast<T>(dist(gen));
}

template <typename T>
auto TextureAtlas<T>::DefineTexture(const Rectangle &src, const Vector2 &position, const Color color) -> void {
    DrawTextureRec(texture, src, position, color);
    // DrawTextureEx();
    //DrawTextureV();
}

// Use this instead: DrawTextureEx(_sprite->GetTexture(), _position, 0.0, 1.0, WHITE); OR DrawTextureV(texture, vector2, tint);

template <typename T>
auto TextureAtlas<T>::DefineTexturePro(const Rectangle &src, const Rectangle &dest, const Vector2& origin, float rotation, const Color color) -> void {
    DrawTexturePro(texture, src, dest, origin, rotation, color);
}

template <typename T>
auto TextureAtlas<T>::DefineTextureEx(const Vector2 &position, const float rotation, const Color color) -> void {
    DrawTextureEx(texture, position, rotation, 1, color);
}

template class TextureAtlas<TextureBricksSingle>;
template class TextureAtlas<TextureBricksDouble>;
template class TextureAtlas<TextureEntities>;