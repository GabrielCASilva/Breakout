#include "Utils/TextureLoader.h"

#include "Utils/Constants.h"

auto TextureLoader::Load(const std::string &file) -> Texture2D {
    return LoadTexture((game::ROOT + "assets/sprites/" + file + ".png").c_str());
}