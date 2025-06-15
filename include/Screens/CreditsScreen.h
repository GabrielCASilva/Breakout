#ifndef CREDITS_SCREEN_H
#define CREDITS_SCREEN_H
#include <string>

#include "IScreen.h"

class CreditsScreen final : public IScreen {
public:
    auto Init() -> void override;

    auto Update(float dt) -> void override;

    auto Draw() -> void override;

    auto Exit() -> void override {
    }

private:
    std::string m_text{"Créditos"};
};

#endif //CREDITS_SCREEN_H
