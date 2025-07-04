#include "UI/Button.h"

#include <cmath>
#include <iostream>

#include "raylib.h"
#include "UI/Text.h"

auto Button::Draw() const -> void {
    // ReSharper disable once CppDFAConstantConditions
    if (m_isHovered) {
        // ReSharper disable once CppDFAUnreachableCode
        DrawRectangle(m_position.x, m_position.y, m_size.x, m_size.y, RED);
    } else {
        DrawRectangle(m_position.x, m_position.y, m_size.x, m_size.y, GREEN);
    }

    float a = m_size.x/2;
    float b = m_size.y/2;
    Vector2 teste = MeasureTextEx(Text::m_font, m_text.c_str(), 64, 1);
    Vector2 teste2 = {m_position.x - teste.x/2 + a + 2, m_position.y - teste.y/2 + b - 2};
    // Vector2 teste2 = {m_position.x , m_position.y};


    DrawTextEx(Text::m_font, m_text.c_str(), teste2, 64, 1, WHITE);
}
