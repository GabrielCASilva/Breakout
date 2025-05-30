#include "Screens/ScreenManager.h"

std::unique_ptr<IScreen> ScreenManager::current_screen = nullptr;

auto ScreenManager::ChangeScreen(std::unique_ptr<IScreen> screen) -> void {
    if (current_screen) {
        current_screen->Exit();
    }
    current_screen = std::move(screen);

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