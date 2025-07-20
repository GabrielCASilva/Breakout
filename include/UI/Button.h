#ifndef BUTTON_H
#define BUTTON_H
#include <functional>
#include <string>

#include "raylib.h"
#include "Text.h"
#include "Utils/Constants.h"

enum class ButtonOrigins {
    START,
    CENTER,
};

class Button {
public:
    Button(const Vector2 position, std::string &&text,
           FontTypes &&type = FontTypes::SIZE_20, ButtonOrigins &&origin = ButtonOrigins::START)
        : m_position(position), m_type(type), m_text(text) {
        m_size = Text::Measure(type, m_text);
        m_size.x = m_size.x - game::SCALE;
        m_size.y /= 2;
        DefineButtonAlign(origin);
    }

    auto Draw() const -> void;

    void UpdateState(const float mouse_x, const float mouse_y, const bool mouse_pressed) {
        m_isHovered = (mouse_x >= m_position.x && mouse_x < m_position.x + m_size.x) &&
                      (mouse_y >= m_position.y && mouse_y < m_position.y + m_size.y);
        m_isPressed = m_isHovered && mouse_pressed;
    }

    auto SetOnClick(std::function<void(bool, bool)> callback) -> void {
        m_callback = std::move(callback);
    }

    auto Click() const -> void {
        if (m_callback) m_callback(m_isHovered, m_isPressed);
    }

    [[nodiscard]] auto IsHovered() const -> bool { return m_isHovered; }

    [[nodiscard]] auto IsPressed() const -> bool { return m_isPressed; }

private:
    auto DefineButtonAlign(const ButtonOrigins &origin) -> void;

    std::function<void(bool, bool)> m_callback{nullptr};

    Vector2 m_position{};
    Vector2 m_size{};
    FontTypes m_type{};

    std::string m_text{};
    Vector2 m_textPosition{}; // text position relate to button

    bool m_isHovered{false};
    bool m_isPressed{false};

};

#endif //BUTTON_H
