#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>

#include "raylib.h"

class TextureLoader {
public:
    static Texture2D texture;
    static auto Load(const std::string &file) -> void;
};

#endif //TEXTURE_H
