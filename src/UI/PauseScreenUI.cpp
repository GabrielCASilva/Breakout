#include "UI/PauseScreenUI.h"

#include <functional>

#include "raylib.h"
#include "States/PlayerData.h"
#include "Screens/ScreenManager.h"
#include "UI/Button.h"
#include "UI/Cursor.h"
#include "Utils/Constants.h"

PauseScreenUI::PauseScreenUI() {
    constexpr float width{game::WINDOW_WIDTH / 2.0f};
    constexpr float height{game::WINDOW_HEIGHT / 2.5f};
    constexpr float gap{20 * game::SCALE};
    m_buttons[0] = std::make_unique<Button>(Vector2{width, height}, "CONTINUE", FontTypes::SIZE_20,
                                            ButtonOrigins::CENTER);
    m_buttons[1] = std::make_unique<Button>(Vector2{width, height + gap}, "RESTART", FontTypes::SIZE_20,
                                            ButtonOrigins::CENTER);
    m_buttons[2] = std::make_unique<Button>(Vector2{width, height + 2*gap}, "MAIN MENU", FontTypes::SIZE_20,
                                            ButtonOrigins::CENTER);
    m_buttons[3] = std::make_unique<Button>(Vector2{width, height + 3*gap}, "QUIT", FontTypes::SIZE_20,
                                            ButtonOrigins::CENTER);

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
        if (button->IsHovered()) {
            Cursor::SetIsHovered(true);
            break; // importante, ele para no botão que foi clicado de fato
        }
        Cursor::SetIsHovered(false);
    }

    for (const auto &button: m_buttons) {
        button->UpdateState(mouse_x, mouse_y, mouse_pressed);
        if (button->IsPressed()) {
            Cursor::SetIsDisable(false);
            button->Click();
            Cursor::SetIsHovered(false);
            break; // importante, ele para no botão que foi clicado de fato
        }
    }
}

auto PauseScreenUI::Draw() const -> void {

    for (const auto &button: m_buttons) {
        button->Draw();
    }
}