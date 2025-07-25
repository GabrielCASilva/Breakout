#include "Screens/PauseScreen.h"

#include "raylib.h"
#include "Utils/Constants.h"

auto PauseScreen::Init() -> void {
}

auto PauseScreen::Update(float dt) -> void {
    m_ui->Update();
}

auto PauseScreen::Draw() -> void {
    DrawRectangle(0,0, game::WINDOW_WIDTH, game::WINDOW_HEIGHT, game::PAUSE_BACKGROUND_COLOR);
    m_ui->Draw();
}