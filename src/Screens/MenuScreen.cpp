#include "Screens/MenuScreen.h"

#include <iostream>
#include <raylib.h>

#include "Textures/TextureAtlas.h"
#include "Utils/Parallax.h"

auto MenuScreen::Init() -> void {
    m_bg_planets.LoadTexture("title_screen_planets");
    InitializeBackgrounds();
}

static float pos_y = 0.0f;
static float dir = 1;
auto MenuScreen::Update(const float dt) -> void {
    m_ui->Update();

    if (pos_y >= 50.0f) {
        dir = -1;
    } else if (pos_y <= 0) {
        dir = 1;
    }

    pos_y = pos_y + dir * game::SCALE * dt * 4;
    m_bg_planets.SetPosition({0,pos_y});

    for (auto &bg : m_BackgroundLayers) {
        bg.Update(dt);
    }
}
auto MenuScreen::Draw() -> void {
    for (auto &bg : m_BackgroundLayers) {
        bg.Draw();
    }

    m_bg_planets.Draw();

    const Rectangle &texture = TextureAtlas<TextureEntities>::GetTextureImage(TextureEntities::TITLE);
    TextureAtlas<TextureEntities>::DefineTexture(texture,
        {game::WINDOW_WIDTH / 2.0f,game::WINDOW_HEIGHT / 3.0f},
        {texture.width / 2, texture.height / 2});

    m_ui->Draw();
}
auto MenuScreen::Exit() -> void {
    UnloadBackgrounds();
}

auto MenuScreen::InitializeBackgrounds() -> void {
    for (std::size_t i {0}; i < static_cast<std::size_t>(BackgroundsLayers::LEN); ++i) {
        if (i == static_cast<std::size_t>(BackgroundsLayers::LAYER_5))
            m_BackgroundLayers[i].LoadSprite(BG_DIR + "bg_starts");
            else
            m_BackgroundLayers[i].LoadSprite(BG_DIR + "bg_" + std::to_string(i));
    }

    Vector2 speed = {0.f, 1.f};
    for (auto& bg : m_BackgroundLayers) {
        speed.y += 2;
        bg.SetSpeed(speed);
    }
}

auto MenuScreen::UnloadBackgrounds() -> void {
    for (auto& bg : m_BackgroundLayers) {
        bg.UnloadSprite();
    }
    for (auto& bg : m_BackgroundLayers) {
        bg.SetDisable(true);
    }
}
