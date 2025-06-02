#include "Screens/GameScreen.h"
#include <raylib.h>

#include "Bricks/BrickLoader.h"
#include "Utils/Constants.h"
#include "Utils/Grid.h"

auto GameScreen::Init() -> void {
    Vector2 paddle_position {game::WINDOW_WIDTH/2, game::WINDOW_HEIGHT - 100};
    Vector2 ball_position {game::WINDOW_WIDTH/2, game::WINDOW_HEIGHT/2};

    paddle = std::make_unique<Paddle>(paddle_position);
    ball = std::make_unique<Ball>(ball_position);

    const auto file {BrickLoader::SetPatternToLoad("layout_1")};
    auto level_layout1 {BrickLoader::LoadFromFile(file)};

    level = std::make_unique<BrickSet>(level_layout1);
    level->InitializeBricks();
}

auto GameScreen::Update(const float dt) -> void {
    paddle->Update(dt);
    ball->Update(dt);
    level->OnCollision(*ball);

    level->SafalyDestroyBricks();
}

auto GameScreen::Draw() -> void {
    Grid::Draw();
    // paddle->Draw();
    ball->Draw();
    level->Draw();
}
auto GameScreen::Exit() -> void {

}
