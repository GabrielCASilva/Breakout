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

    auto LoadTexture(const std::string &file) -> void;

    auto UpdateAnimation() -> void;

    auto Draw() const -> void;

    auto Unload() const -> void;

    auto SetPosition(const Vector2 &position) -> void { m_position = position; }

    [[nodiscard]] auto GetTexture() -> Texture & { return m_texture; }
    [[nodiscard]] auto GetImage() -> Image & { return m_image; }
    [[nodiscard]] auto GetPosition() -> Vector2 & { return m_position; }

private:
    Vector2 m_position{};
    Texture2D m_texture{};
    Image m_image{};

    // animation relatable variables
    int m_frame{0};
    int m_frame_current{0};
    unsigned int m_next_frame{0};
    std::uint16_t m_frame_count{0};
    std::uint16_t m_frame_delay{24};
};

#endif //BACKGROUND_H
