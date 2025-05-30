#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H
#include <memory>

#include "IScreen.h"
#include "Entities/Ball.h"
#include "Entities/Paddle.h"
#include "Bricks/BrickSet.h"

class GameScreen final : public IScreen {
    std::unique_ptr<Paddle> paddle;
    std::unique_ptr<Ball> ball;
    std::unique_ptr<BrickSet> level;

public:
    auto Init() -> void override;
    auto Update(float dt) -> void override;
    auto Draw() -> void override;
    auto Exit() -> void override;
};

#endif //GAME_SCREEN_H
