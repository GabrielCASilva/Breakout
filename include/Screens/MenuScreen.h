#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H
#include <memory>

#include "IScreen.h"
#include "UI/MenuScreenUI.h"

class MenuScreen final : public IScreen {
public:
    auto Init() -> void override;

    auto Update(float dt) -> void override;

    auto Draw() -> void override;

    auto Exit() -> void override;

private:
    std::unique_ptr<MenuScreenUI> m_ui{std::make_unique<MenuScreenUI>()};
};

#endif //MENU_SCREEN_H
