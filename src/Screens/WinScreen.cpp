#include "Screens/WinScreen.h"

#include "raylib.h"
#include "Screens/ScreenManager.h"
#include "Screens/Screens.h"
#include "Utils/Constants.h"

auto WinScreen::Init() -> void {
}

auto WinScreen::Update(float dt) -> void {
    // m_ui->Update();
    if (IsKeyPressed(KEY_BACKSPACE)) {
        ScreenManager::ChangeScreen(Screens::MENU);
    }
}

auto WinScreen::Draw() -> void {
    DrawText("YOU WIN", game::WINDOW_WIDTH/2.0f - 60, game::WINDOW_HEIGHT/2.0f - 30, 30, WHITE);
    // m_ui->Draw();
}