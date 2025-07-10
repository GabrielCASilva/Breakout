#include "UI/MenuScreenUI.h"

#include <functional>

#include "raylib.h"
#include "Screens/ScreenManager.h"
#include "Screens/Screens.h"
#include "Utils/Constants.h"

MenuScreenUI::MenuScreenUI() {
    constexpr float width{game::WINDOW_WIDTH / 2.0f};
    constexpr float height{game::WINDOW_HEIGHT / 2.0f};
    constexpr float gap{20 * game::SCALE};
    m_buttons[0] = std::make_unique<Button>(Vector2{width, height}, "START",
                                            FontTypes::SIZE_20, ButtonOrigins::CENTER);


    m_buttons[1] = std::make_unique<Button>(Vector2{width, height + gap}, "CREDITS",
                                            FontTypes::SIZE_20, ButtonOrigins::CENTER);
    m_buttons[2] = std::make_unique<Button>(Vector2{width, height + 2 * gap}, "QUIT",
                                            FontTypes::SIZE_20, ButtonOrigins::CENTER);

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
    for (const auto &button: m_buttons) {
        button->Draw();
    }
}
