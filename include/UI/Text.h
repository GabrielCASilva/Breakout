#ifndef TEXT_H
#define TEXT_H
#include <string>

#include "raylib.h"

class Text {
public:
    static auto Load(std::string&& file) -> void;
    static auto Unload() -> void;
    static inline Font m_font{};
};

#endif //TEXT_H