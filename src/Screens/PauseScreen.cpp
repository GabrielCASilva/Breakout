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
    Vector2 men = Text::Measure(FontTypes::SIZE_32, m_text);
    const Vector2 position = {
        game::WINDOW_WIDTH/2.0f - men.x/2.0f,
        game::WINDOW_HEIGHT/4.0f - men.y/2.0f
    };
    Text::Draw(FontTypes::SIZE_32, m_text, position, WHITE);
    m_ui->Draw();
}