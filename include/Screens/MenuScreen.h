#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H
#include "IScreen.h"

class MenuScreen final : public IScreen {
public:
    auto Init() -> void override;
    auto Update(float dt) -> void override;
    auto Draw() -> void override;
    auto Exit() -> void override;
};

#endif //MENU_SCREEN_H
