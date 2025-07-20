#ifndef TEXT_H
#define TEXT_H
#include <string>

#include "raylib.h"

enum class FontTypes {
    SIZE_12,
    SIZE_16,
    SIZE_20,
    SIZE_32,
};

struct Fonts {
    Font size_12{};
    Font size_16{};
    Font size_20{};
    Font size_32{};
};

class Text {
public:
    Text() = delete;

    static auto Load(std::string &&file) -> void;

    static auto Unload() -> void;

    static auto Measure(const FontTypes &types, const std::string &text) -> Vector2;

    static auto Draw(const FontTypes &types, const std::string &text,
                     const Vector2 &position, const Color &&color) -> void;

    static inline Fonts m_fonts{};
};

#endif //TEXT_H
