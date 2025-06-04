#include <raylib.h>
#include "Game.h"
#include "Utils/Constants.h"

int main() {
    Game::Initialize(game::WINDOW_WIDTH, game::WINDOW_HEIGHT, "breakout");

    SetTargetFPS(game::FPS);

    while (!Game::GameShouldClose())
    {
        Game::Tick();
    }

    Game::Unload();

    return 0;
}
