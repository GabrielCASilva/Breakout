#include "Screens/ScreenManager.h"

#include "Screens/CreditsScreen.h"
#include "Screens/GameOverScreen.h"
#include "Screens/GameScreen.h"
#include "Screens/MenuScreen.h"
#include "Screens/Screens.h"
#include "Screens/WinScreen.h"

auto ScreenManager::ChangeScreen(const Screens screen) -> void {
    switch (screen) {
        case Screens::GAME:
            next_screen = std::make_unique<GameScreen>();
            break;
        case Screens::MENU:
            next_screen = std::make_unique<MenuScreen>();
            break;
        case Screens::WIN:
            next_screen = std::make_unique<WinScreen>();
            break;
        case Screens::CREDITS:
            next_screen = std::make_unique<CreditsScreen>();
            break;
        case Screens::GAME_OVER:
            next_screen = std::make_unique<GameOverScreen>();
            break;
        default:
            next_screen = std::make_unique<MenuScreen>();
            break;
    }
    m_screen_changed = true;
}

auto ScreenManager::UpdateCurrentScreen() -> void {
    if (m_screen_changed) {
        m_screen_changed = false;
        Exit();
        current_screen = std::move(next_screen);
        Init();
    }
}

auto ScreenManager::Init() -> void {
    if (current_screen) current_screen->Init();
}

auto ScreenManager::Update(const float dt) -> void {
    if (current_screen && !m_screen_changed) current_screen->Update(dt);
}

auto ScreenManager::Draw() -> void {
    if (current_screen && !m_screen_changed) current_screen->Draw();
}

auto ScreenManager::Exit() -> void {
    if (current_screen) current_screen->Exit();
}
