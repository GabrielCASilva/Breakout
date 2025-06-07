#include "Screens/GameScreen.h"

#include <iostream>
#include <raylib.h>

#include "Bricks/BrickLoader.h"
#include "Utils/Constants.h"
#include "Utils/Grid.h"

auto GameScreen::Init() -> void {
    Vector2 paddle_position {game::WINDOW_WIDTH/2.0f - game::paddle::SIZE.x/2, game::WINDOW_HEIGHT - 100};
    Vector2 ball_position {game::WINDOW_WIDTH/2.0f, game::WINDOW_HEIGHT - 150};

    paddle = std::make_unique<Paddle>(paddle_position);
    ball = std::make_unique<Ball>(ball_position);

    const auto file {BrickLoader::SetPatternToLoad("layout_1")};
    auto level_layout1 {BrickLoader::LoadFromFile(file)};

    bricks = std::make_unique<BrickSet>(level_layout1);
    bricks->InitializeBricks();
}

auto GameScreen::Update(const float dt) -> void {
    paddle->Update(dt);
    ball->Update(dt);
    ball->DefineInitialPos(paddle->GetPosition());

    // collision detection
    bricks->OnCollision(*ball);
    ball->OnCollision(*paddle);

    bricks->SafelyDestroyBricks();
}

auto GameScreen::Draw() -> void {
    Grid::Draw();
    paddle->Draw();
    ball->Draw();
    bricks->Draw();
}

auto GameScreen::Exit() -> void {

}
