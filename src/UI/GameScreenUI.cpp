#include "UI/GameScreenUI.h"

#include <string>

#include "raylib.h"
#include "GlobalStates/PlayerData.h"
#include "UI/Text.h"
#include "Utils/Constants.h"

auto GameScreenUI::Update() -> void {

}

auto GameScreenUI::Draw() const -> void {
    constexpr int font_size {12 * game::SCALE};
    constexpr int pos_y{6 * game::SCALE};

    const auto points {"Score " + std::to_string(PlayerData::GetPoints())};
    DrawTextEx(Text::m_font, points.c_str(), {8 * game::SCALE, pos_y}, font_size, 1, WHITE);

    const auto level {"Level " + std::to_string(m_level)};
    Vector2 teste2 = MeasureTextEx(Text::m_font, level.c_str(), font_size, 1);
    DrawTextEx(Text::m_font, level.c_str(), {game::WINDOW_WIDTH/2.0f - teste2.x/2, pos_y}, font_size, 1, WHITE);

    const auto lives {"Lives " + std::to_string(PlayerData::GetLives())};
    Vector2 teste = MeasureTextEx(Text::m_font, lives.c_str(), font_size, 1);
    DrawTextEx(Text::m_font, lives.c_str(), {game::WINDOW_WIDTH - teste.x - 8 * game::SCALE, pos_y}, font_size, 1, WHITE);


}
