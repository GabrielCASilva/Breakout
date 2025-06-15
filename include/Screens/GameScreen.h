#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H
#include <memory>

#include "IScreen.h"
#include "PauseScreen.h"
#include "Entities/Ball.h"
#include "Entities/Paddle.h"
#include "Bricks/BrickSet.h"
#include "UI/LevelsUI.h"

class GameScreen final : public IScreen {
public:
    auto Init() -> void override;

    auto Update(float dt) -> void override;

    auto Draw() -> void override;

    auto Exit() -> void override{}

private:
    std::unique_ptr<Paddle> paddle;
    std::unique_ptr<Ball> ball;
    std::unique_ptr<BrickSet> bricks;
    std::unique_ptr<LevelsUI> levels_ui{};
    std::unique_ptr<PauseScreen> m_pause_screen;

    auto PauseGame() const -> void;
};

#endif //GAME_SCREEN_H
