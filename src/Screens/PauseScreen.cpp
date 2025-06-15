#include "Screens/PauseScreen.h"

#include "raylib.h"
#include "Utils/Constants.h"

auto PauseScreen::Init() -> void {
}

auto PauseScreen::Update(float dt) -> void {
    m_ui->Update();
}

auto PauseScreen::Draw() -> void {
    DrawText(m_text.c_str(), game::WINDOW_WIDTH/2.0f - 60, game::WINDOW_HEIGHT/2.0f - 30, 30, WHITE);
    m_ui->Draw();
}