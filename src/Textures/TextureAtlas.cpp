#include "Textures/TextureAtlas.h"

#include <random>

#include "Utils/Constants.h"
#include "Utils/TextureLoader.h"

template <typename T>
auto TextureAtlas<T>::Load(const std::array<Rectangle, static_cast<std::size_t>(T::LEN)>& _atlas) -> void {
    if (loaded) return;

    texture = TextureLoader::Load("atlas");
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

template <typename T>
auto TextureAtlas<T>::GetRandomTextureImage(const int max) -> T {
    static_assert(std::is_enum_v<T>, "T must be an enum");

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution dist(0, max - 1);

    return static_cast<T>(dist(gen));
}

template class TextureAtlas<TextureBricksSingle>;
template class TextureAtlas<TextureBricksDouble>;
template class TextureAtlas<TextureEntities>;