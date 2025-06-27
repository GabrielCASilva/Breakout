#include "Utils/TextureLoader.h"

#include "Utils/Constants.h"

auto TextureLoader::Load(const std::string &file, const std::string& type) -> Texture2D {
    return LoadTexture((game::ROOT + "assets/sprites/" + file + "." + type).c_str());
}