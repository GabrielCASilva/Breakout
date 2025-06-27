#ifndef WIN_SCREEN_H
#define WIN_SCREEN_H

#include <memory>

#include "IScreen.h"
#include "UI/WinScreenUI.h"

class WinScreen final : public IScreen {
public:
    auto Init() -> void override;

    auto Update(float dt) -> void override;

    auto Draw() -> void override;

    auto Exit() -> void override {}

// private:
    // std::unique_ptr<WinScreenUI> m_ui{std::make_unique<WinScreenUI>()};
};

#endif //WIN_SCREEN_H
