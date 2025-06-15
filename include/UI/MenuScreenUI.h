#ifndef MENU_SCREEN_UI_H
#define MENU_SCREEN_UI_H
#include <array>
#include <memory>

#include "Button.h"
#include "IUserInterface.h"

class MenuScreenUI final : public IUserInterface {
public:
    MenuScreenUI();

    auto Update() -> void override;

    auto Draw() const -> void override;

private:
    std::array<std::unique_ptr<Button>, 3> m_buttons{};
};

#endif //MENU_SCREEN_UI_H
