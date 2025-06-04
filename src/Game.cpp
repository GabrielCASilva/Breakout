#include "Game.h"
#include <cassert>
#include <raylib.h>

#include "Screens/GameScreen.h"
#include "Screens/ScreenManager.h"
#include "Textures/TextureAtlas.h"
#include "Utils/TextureLoader.h"

auto Game::Initialize(const int width, const int height, const std::string &title) -> void {
    assert(!GetWindowHandle());
    InitWindow(width, height, title.c_str());
    // Loading images
    TextureAtlas<TextureBricksSingle>::Load(BricksSingle);
    TextureAtlas<TextureBricksDouble>::Load(BricksDouble);
    TextureAtlas<TextureEntities>::Load(Entities);

    ScreenManager::ChangeScreen(std::make_unique<GameScreen>());
}

auto Game::GameShouldClose() -> bool {
    return WindowShouldClose();
}

auto Game::Tick() -> void {
    Update();
    Draw();
}

auto Game::Update() -> void {
    const float dt = GetFrameTime();
    ScreenManager::Update(dt);
}

auto Game::Draw() -> void {
    BeginDrawing();
    ClearBackground(BLACK);
    ScreenManager::Draw();
    EndDrawing();
}

auto Game::Unload() -> void {
    TextureAtlas<TextureBricksSingle>::Unload();
    TextureAtlas<TextureBricksDouble>::Unload();
    TextureAtlas<TextureEntities>::Unload();
}
