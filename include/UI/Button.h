#ifndef BUTTON_H
#define BUTTON_H
#include <functional>
#include <string>

#include "raylib.h"
#include "Utils/Constants.h"

class Button {
public:
    Button(const Vector2 position, std::string &&text): m_position(position), m_text(text) {
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
    Vector2 m_position{};
    Vector2 m_size{game::ui::BTN_SIZE};
    std::string m_text{};
    bool m_isHovered{false};
    bool m_isPressed{false};

    std::function<void(bool, bool)> m_callback{nullptr};
};

#endif //BUTTON_H
