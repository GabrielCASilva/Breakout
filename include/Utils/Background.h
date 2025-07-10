#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <cstdint>
#include <string>

#include "raylib.h"

class Background {
public:
    Background() = default;

    explicit Background(const Vector2 position) : m_position(position) {
    }

    ~Background() = default;

    Background(const Background &) = delete;

    Background(Background &&) = delete;

    Background &operator=(const Background &) = delete;

    Background &operator=(Background &&) = delete;

    auto LoadAnimatedTexture(std::string &&file) -> void;

    auto LoadTexture(std::string &&file) -> void;

    auto UpdateAnimation() -> void;

    auto Draw() const -> void;

    auto UnloadBackgroundTexture() const -> void;

    auto UnloadBackgroundImage() const -> void;

private:
    int m_frame{0};
    int m_frame_current{0};
    unsigned int m_next_frame{0};
    std::uint16_t m_frame_count{0};
    std::uint16_t m_frame_delay{24};
    Texture2D m_texture{};
    Image m_image{};
    Vector2 m_position{};
};

#endif //BACKGROUND_H
