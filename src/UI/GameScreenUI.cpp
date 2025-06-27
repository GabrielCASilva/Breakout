#include "UI/GameScreenUI.h"

#include <string>

#include "raylib.h"
#include "GlobalStates/PlayerData.h"
#include "UI/Text.h"

auto GameScreenUI::Update() -> void {

}

auto GameScreenUI::Draw() const -> void {
    const auto lives {std::to_string(PlayerData::GetLives())};
    const auto points {std::to_string(PlayerData::GetPoints())};
    const auto level {"Level " + std::to_string(m_level)};
    // DrawTextEx(Text::m_font, level.c_str(), {200, 20}, 20, 1, WHITE);
    DrawText(points.c_str(), 20,20,20, WHITE);
    DrawText(lives.c_str(), 20,40,20, WHITE);
    DrawText(level.c_str(), 100,20,20, WHITE);
}
