#include "Screens/GameOverScreen.h"

#include "raylib.h"
#include "Screens/ScreenManager.h"
#include "Utils/Constants.h"

auto GameOverScreen::Init() -> void {
}

auto GameOverScreen::Update(float dt) -> void {
    if (IsKeyPressed(KEY_BACKSPACE)) {
        ScreenManager::ChangeScreen(Screens::MENU);
    }
}

auto GameOverScreen::Draw() -> void {
    DrawText(m_text.c_str(), game::WINDOW_WIDTH / 2.0f - 60, game::WINDOW_HEIGHT / 2.0f - 30, 30, WHITE);
}
