#include "Utils/TextureLoader.h"

#include "Utils/Constants.h"

auto TextureLoader::Load(const std::string &file) -> Texture2D {
    // Image img = LoadImage((game::ROOT + "assets/sprites/" + file + ".png").c_str());
    // ImageFormat(&img, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    // const Texture2D sprite = LoadTextureFromImage(img);
    // UnloadImage(img);
    // return sprite;
    return LoadTexture((game::ROOT + "assets/sprites/" + file + ".png").c_str());
}