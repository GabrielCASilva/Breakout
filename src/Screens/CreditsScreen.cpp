#import "Screens/CreditsScreen.h"

#include "raylib.h"
#include "Screens/ScreenManager.h"
#include "Utils/Constants.h"

auto CreditsScreen::Init() -> void {
}

auto CreditsScreen::Update(float dt) -> void {
    if (IsKeyPressed(KEY_BACKSPACE)) {
        ScreenManager::ChangeScreen(Screens::MENU);
    }
}

auto CreditsScreen::Draw() -> void {
    DrawText(m_text.c_str(), game::WINDOW_WIDTH / 2.0f - 60, game::WINDOW_HEIGHT / 2.0f - 30, 30, WHITE);
}
