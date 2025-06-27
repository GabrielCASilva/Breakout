#ifndef WIN_SCREEN_UI_H
#define WIN_SCREEN_UI_H

#include "IUserInterface.h"

class WinScreenUI final : public IUserInterface {
public:
    WinScreenUI();

    auto Update() -> void override;

    auto Draw() const -> void override;
};


#endif //WIN_SCREEN_UI_H
