#include "UI/PauseScreenUI.h"

#include <functional>

#include "raylib.h"
#include "GlobalStates/PlayerData.h"
#include "Screens/ScreenManager.h"
#include "UI/Button.h"
#include "Utils/Constants.h"

PauseScreenUI::PauseScreenUI() {
    constexpr float width{game::WINDOW_WIDTH / 2 - game::ui::BTN_SIZE.x / 2};
    constexpr float height{game::WINDOW_HEIGHT / 2.0f + 100};
    m_buttons[0] = std::make_unique<Button>(Vector2{width, height - 50}, "CONTINUE");
    m_buttons[1] = std::make_unique<Button>(Vector2{width, height}, "RESTART");
    m_buttons[2] = std::make_unique<Button>(Vector2{width, height + 50}, "RETURN TO TITLE SCREEN");
    m_buttons[3] = std::make_unique<Button>(Vector2{width, height + 100}, "QUIT");

    m_buttons[0]->SetOnClick([this](const bool hovered, const bool pressed) {
        if (hovered && pressed) SetContinue(false);
    });

    m_buttons[1]->SetOnClick([](const bool hovered, const bool pressed) {
        if (hovered && pressed) ScreenManager::ChangeScreen(Screens::GAME);
    });

    m_buttons[2]->SetOnClick([](const bool hovered, const bool pressed) {
        if (hovered && pressed) ScreenManager::ChangeScreen(Screens::MENU);
    });

    m_buttons[3]->SetOnClick([](const bool hovered, const bool pressed) {
        if (hovered && pressed) CloseWindow();
    });
}

auto PauseScreenUI::Update() -> void {
    const auto [mouse_x, mouse_y] = GetMousePosition();
    const bool mouse_pressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

    for (const auto &button: m_buttons) {
        button->UpdateState(mouse_x, mouse_y, mouse_pressed);
        if (button->IsPressed()) {
            button->Click();
            break; // importante, ele para no botão que foi clicado de fato
        }
    }
}

auto PauseScreenUI::Draw() const -> void {
    ShowPlayerData();

    for (const auto &button: m_buttons) {
        button->Draw();
    }
}

auto PauseScreenUI::ShowPlayerData() const -> void {
    const auto lives {"Lives " + std::to_string(PlayerData::GetLives())};
    const auto points {"Points " + std::to_string(PlayerData::GetPoints())};
    // const auto level {"Level " + std::to_string(m_level)};

    DrawText(lives.c_str(), 200, 200, 20, WHITE);
    DrawText(points.c_str(), 200, 250, 20, WHITE);
}
