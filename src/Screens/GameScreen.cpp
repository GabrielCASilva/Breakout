#include "Screens/GameScreen.h"

#include <raylib.h>

#include "Bricks/BrickLoader.h"
#include "GlobalStates/PlayerData.h"
#include "Screens/ScreenManager.h"
#include "Utils/Constants.h"
#include "Utils/Grid.h"

namespace p = game::paddle;
namespace level = game::level;
int animFrames = 0;

auto GameScreen::Init() -> void {
    m_pause_screen = std::make_unique<PauseScreen>();
    m_ui = std::make_unique<GameScreenUI>();

    m_background.LoadAnimatedTexture("game_background");

    Vector2 paddle_position{game::WINDOW_WIDTH / 2.0f - p::SIZE.x / 2, game::WINDOW_HEIGHT - 100};
    Vector2 ball_position{game::WINDOW_WIDTH / 2.0f, game::WINDOW_HEIGHT - 150};

    paddle = std::make_unique<Paddle>(paddle_position);
    ball = std::make_unique<Ball>(ball_position);

    m_ui->SetLevel(m_current_level);
    ChangeLevel("layout_" + std::to_string(m_current_level));
}

auto GameScreen::Update(const float dt) -> void {
    PauseGame();
    if (m_pause_screen->GetContinue()) {
        m_pause_screen->Update(dt);
        return;
    }

    m_background.UpdateAnimation();
    paddle->Update(dt);
    ball->Update(dt);
    ball->DefineInitialPos(paddle->GetPosition());

    // collision detection
    bricks->OnCollision(*ball);
    ball->OnCollision(*paddle);

    bricks->SafelyDestroyBricks();

    if (bricks->IsEmpty()) {
        ++m_current_level;
        if (m_current_level < level::MAX_LEVEL) {
            m_ui->SetLevel(m_current_level);
            ChangeLevel("layout_" + std::to_string(m_current_level));
            ball->Reset();
        } else {
            ScreenManager::ChangeScreen(Screens::WIN);
        }
    }

    if (PlayerData::GetLives() < 1) {
        ScreenManager::ChangeScreen(Screens::GAME_OVER);
    }
}

auto GameScreen::Draw() -> void {
    if (m_pause_screen->GetContinue()) {
        m_pause_screen->Draw();
        return;
    }
    m_background.Draw();
    Grid::Draw();
    m_ui->Draw();
    paddle->Draw();
    ball->Draw();
    bricks->Draw();

}

auto GameScreen::PauseGame() const -> void {
    if (!m_pause_screen->GetContinue() && IsKeyPressed(KEY_BACKSPACE)) {
        m_pause_screen->SetContinue(!m_pause_screen->GetContinue());
    }
}

auto GameScreen::ChangeLevel(const std::string& level) -> void {
    const auto file{BrickLoader::SetPatternToLoad(level)};
    auto level_layout{BrickLoader::LoadFromFile(file)};
    bricks = std::make_unique<BrickSet>(level_layout);
    bricks->InitializeBricks();
}

auto GameScreen::Exit() -> void {
    m_background.UnloadBackgroundTexture();
    m_background.UnloadBackgroundImage();
    PlayerData::Reset();
}