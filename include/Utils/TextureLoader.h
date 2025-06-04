#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>

#include "raylib.h"

class TextureLoader {
public:
    static auto Load(const std::string &file) -> Texture2D;
};

#endif //TEXTURE_H
