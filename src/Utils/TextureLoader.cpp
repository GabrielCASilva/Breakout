#include "Utils/TextureLoader.h"

#include "Utils/Constants.h"

Texture2D TextureLoader::texture = {};

auto TextureLoader::Load(const std::string &file) -> void {
    texture = LoadTexture((game::ROOT + "assets/sprites/" + file + ".png").c_str());
    SetTextureFilter(texture, TEXTURE_FILTER_POINT);
}