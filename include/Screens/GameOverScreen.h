#ifndef GAME_OVER_SCREEN_H
#define GAME_OVER_SCREEN_H
#include <string>

#include "IScreen.h"

class GameOverScreen final : public IScreen {
public:
    auto Init() -> void override;
    auto Update(float dt) -> void override;
    auto Draw() -> void override;
    auto Exit() -> void override {}
private:
    std::string m_text{"Game Over"};
};

#endif //GAME_OVER_SCREEN_H
