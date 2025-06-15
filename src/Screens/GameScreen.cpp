#include "Screens/GameScreen.h"

#include <iostream>
#include <raylib.h>

#include "Bricks/BrickLoader.h"
#include "Utils/Constants.h"
#include "Utils/Grid.h"

namespace p = game::paddle;

auto GameScreen::Init() -> void {
    m_pause_screen = std::make_unique<PauseScreen>();

    Vector2 paddle_position{game::WINDOW_WIDTH / 2.0f - p::SIZE.x / 2, game::WINDOW_HEIGHT - 100};
    Vector2 ball_position{game::WINDOW_WIDTH / 2.0f, game::WINDOW_HEIGHT - 150};

    paddle = std::make_unique<Paddle>(paddle_position);
    ball = std::make_unique<Ball>(ball_position);

    const auto file{BrickLoader::SetPatternToLoad("layout_1")};
    auto level_layout1{BrickLoader::LoadFromFile(file)};

    bricks = std::make_unique<BrickSet>(level_layout1);
    bricks->InitializeBricks();
}

auto GameScreen::Update(const float dt) -> void {
    PauseGame();
    if (m_pause_screen->GetContinue()) {
        m_pause_screen->Update(dt);
        return;
    }

    paddle->Update(dt);
    ball->Update(dt);
    ball->DefineInitialPos(paddle->GetPosition());

    // collision detection
    bricks->OnCollision(*ball);
    ball->OnCollision(*paddle);

    bricks->SafelyDestroyBricks();
}

auto GameScreen::Draw() -> void {
    if (m_pause_screen->GetContinue()) {
        m_pause_screen->Draw();
        return;
    }
    Grid::Draw();
    paddle->Draw();
    ball->Draw();
    bricks->Draw();
    levels_ui->Draw();
}

auto GameScreen::PauseGame() const -> void {
    if (!m_pause_screen->GetContinue() && IsKeyPressed(KEY_BACKSPACE)) {
        m_pause_screen->SetContinue(!m_pause_screen->GetContinue());
    }
}
