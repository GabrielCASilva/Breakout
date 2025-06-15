#include "UI/Button.h"

#include "raylib.h"

Button::Button(const Vector2 position, const std::string &text) : m_position{position},
                                                                  m_text{text} {
}

auto Button::Draw() const -> void {
    DrawRectangle(m_position.x, m_position.y, m_size.x, m_size.y, WHITE);
    DrawText(m_text.c_str(), m_position.x, m_position.y, 20, RED);
}