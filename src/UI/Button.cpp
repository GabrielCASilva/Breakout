#include "UI/Button.h"

#include <cmath>

#include "raylib.h"
#include "UI/Text.h"

Button::Button(const Vector2 position, const std::string &text) : m_position{position},
                                                                  m_text{text} {
}

auto Button::Draw() const -> void {
    DrawRectangle(m_position.x, m_position.y, m_size.x, m_size.y, WHITE);
    // DrawText(m_text.c_str(), m_position.x, m_position.y, 20, RED);
    DrawTextEx(Text::m_font, m_text.c_str(), m_position, 64, 1, RED);
    // DrawTextEx(Text::m_font, m_text.c_str(), (Vector2){std::round(m_position.x), std::round(m_position.y)}, 54, 0, RED);
}