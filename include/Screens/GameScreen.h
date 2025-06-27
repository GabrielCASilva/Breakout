#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H
#include <memory>

#include "IScreen.h"
#include "PauseScreen.h"
#include "Entities/Ball.h"
#include "Entities/Paddle.h"
#include "Bricks/BrickSet.h"
#include "UI/GameScreenUI.h"
#include "Utils/Background.h"

class GameScreen final : public IScreen {
public:
    auto Init() -> void override;

    auto Update(float dt) -> void override;

    auto Draw() -> void override;

    auto Exit() -> void override;

private:
    std::unique_ptr<Paddle> paddle;
    std::unique_ptr<Ball> ball;
    std::unique_ptr<BrickSet> bricks;
    std::unique_ptr<GameScreenUI> m_ui;
    std::unique_ptr<PauseScreen> m_pause_screen;

    Background m_background{};
    int m_current_level{0};

    auto PauseGame() const -> void;

    auto ChangeLevel(const std::string &level) -> void;
};

#endif //GAME_SCREEN_H
