#include "UI/MenuScreenUI.h"

#include <functional>

#include "raylib.h"
#include "Screens/ScreenManager.h"
#include "Screens/Screens.h"
#include "Utils/Constants.h"

MenuScreenUI::MenuScreenUI() {
    constexpr float width{game::WINDOW_WIDTH / 2 - game::ui::BTN_SIZE.x / 2};
    constexpr float height{game::WINDOW_HEIGHT / 2.0f + 100};
    m_buttons[0] = std::make_unique<Button>(Vector2{width, height - 50}, "START");
    m_buttons[1] = std::make_unique<Button>(Vector2{width, height}, "CREDITS");
    m_buttons[2] = std::make_unique<Button>(Vector2{width, height + 50}, "QUIT");

    m_buttons[0]->SetOnClick([](const bool hovered, const bool pressed) {
        if (hovered && pressed) ScreenManager::ChangeScreen(Screens::GAME);
    });

    m_buttons[1]->SetOnClick([](const bool hovered, const bool pressed) {
        if (hovered && pressed) ScreenManager::ChangeScreen(Screens::CREDITS);
    });

    m_buttons[2]->SetOnClick([](const bool hovered, const bool pressed) {
        if (hovered && pressed) CloseWindow();
    });
}

auto MenuScreenUI::Update() -> void {
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


auto MenuScreenUI::Draw() const -> void {
    constexpr auto width{static_cast<float>(game::WINDOW_WIDTH / 2 - 380 / 2)};
    constexpr auto height{static_cast<float>(game::WINDOW_HEIGHT / 2 - 100)};
    DrawText("BREAKOUT CLONE", width, height, 40, WHITE);
    for (const auto &button: m_buttons) {
        button->Draw();
    }
}
