#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H
#include <memory>

#include "IScreen.h"
#include "UI/MenuScreenUI.h"
#include "Utils/Background.h"

class MenuScreen final : public IScreen {
public:
    auto Init() -> void override;

    auto Update(float dt) -> void override;

    auto Draw() -> void override;

    auto Exit() -> void override;

private:
    std::unique_ptr<MenuScreenUI> m_ui{std::make_unique<MenuScreenUI>()};
    Background m_bg{};
    Background m_bg_planets{};
};

#endif //MENU_SCREEN_H
