#include "Screens/ScreenManager.h"

#include "Screens/CreditsScreen.h"
#include "Screens/GameOverScreen.h"
#include "Screens/GameScreen.h"
#include "Screens/MenuScreen.h"
#include "Screens/Screens.h"
#include "Screens/WinScreen.h"

std::unique_ptr<IScreen> ScreenManager::current_screen = nullptr;

auto ScreenManager::ChangeScreen(const Screens screen) -> void {
    if (current_screen) {
        current_screen->Exit();
    }

    switch (screen) {
        case Screens::GAME:
            current_screen = std::make_unique<GameScreen>();
            break;
        case Screens::MENU:
            current_screen = std::make_unique<MenuScreen>();
            break;
        case Screens::WIN:
            current_screen = std::make_unique<WinScreen>();
            break;
        case Screens::CREDITS:
            current_screen = std::make_unique<CreditsScreen>();
            break;
        case Screens::GAME_OVER:
            current_screen = std::make_unique<GameOverScreen>();
            break;
        default:
            current_screen = std::make_unique<MenuScreen>();
    }

    if (current_screen) {
        current_screen->Init();
    }
}

auto ScreenManager::Init() -> void {
    if (current_screen) current_screen->Init();
}

auto ScreenManager::Update(const float dt) -> void {
    if (current_screen) current_screen->Update(dt);
}

auto ScreenManager::Draw() -> void {
    if (current_screen) current_screen->Draw();
}

auto ScreenManager::Exit() -> void {
    if (current_screen) current_screen->Exit();
}
