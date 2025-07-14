#include "Screens/MenuScreen.h"

#include <cmath>
#include <iostream>
#include <raylib.h>

#include "Textures/TextureAtlas.h"
#include "Utils/Parallax.h"

auto MenuScreen::Init() -> void {
    InitializeBackgrounds();
}

auto MenuScreen::Update(const float dt) -> void {
    m_ui->Update();
    for (auto &bg: m_background_layers)
        bg.Update(dt);
    AnimatePlanets(dt);
}

auto MenuScreen::Draw() -> void {
    for (auto &bg: m_background_layers)
        bg.Draw();
    for (auto &planet: m_planets)
        planet.Draw();
    DrawTittle();
    m_ui->Draw();
}

auto MenuScreen::Exit() -> void {
    UnloadBackgrounds();
}

auto MenuScreen::InitializeBackgrounds() -> void {
    for (std::size_t i{0}; i < static_cast<std::size_t>(BackgroundsLayers::LEN); ++i) {
        if (i == static_cast<std::size_t>(BackgroundsLayers::LAYER_START_1) ||
            i == static_cast<std::size_t>(BackgroundsLayers::LAYER_START_2))
            m_background_layers[i].LoadSprite(BG_DIR + "bg_starts");
        else
            m_background_layers[i].LoadSprite(BG_DIR + "bg_" + std::to_string(i));
    }
    m_background_layers[static_cast<std::size_t>(BackgroundsLayers::LAYER_START_1)]
            .SetFlip({-1, 1});

    Vector2 speed = {0.f, 1.f};
    for (auto &bg: m_background_layers) {
        speed.y += 2;
        bg.SetSpeed(speed);
    }

    for (std::size_t i{0}; i < static_cast<std::size_t>(BackgroundPlanets::LEN); ++i) {
        m_planets[i].LoadSprite(BG_DIR + "planet_" + std::to_string(i));

        // corrigindo a origem das imagens para o centro
        Vector2 position = {
            s_planets_position[i].x - m_planets[i].GetTexture().width / 2 * game::SCALE,
            s_planets_position[i].y - m_planets[i].GetTexture().height / 2 * game::SCALE
        };
        m_planets[i].SetPosition(position);
        m_planets[i].SetInitPosition(position);
    }
}

auto MenuScreen::UnloadBackgrounds() -> void {
    for (auto &bg: m_background_layers)
        bg.UnloadSprite();
    for (auto &bg: m_background_layers)
        bg.SetDisable(true);
    for (auto &planet: m_planets)
        planet.UnloadSprite();
}

auto MenuScreen::AnimatePlanets(const float dt) -> void {
    for (std::size_t i{0}; i < static_cast<std::size_t>(BackgroundPlanets::LEN); ++i) {
        m_planets[i].SetTranslate({0, s_planets_translations[i]});

        const auto [_, y_pos] = m_planets[i].Translation();
        const auto [x_dir, y_dir] = m_planets[i].GetDirection();

        if (y_pos < s_planets_translations_cap[i].min || y_pos > s_planets_translations_cap[i].max)
            m_planets[i].SetDirection({x_dir, y_dir * -1});

        m_planets[i].Update(dt);
    }
}

auto MenuScreen::DrawTittle() -> void {
    const Rectangle &texture = TextureAtlas<TextureEntities>::GetTextureImage(TextureEntities::TITLE);
    constexpr Vector2 pos{
        game::WINDOW_WIDTH / 2.0f,
        game::WINDOW_HEIGHT / 3.0f
    };
    const Vector2 origin{texture.width / 2, texture.height / 2};
    TextureAtlas<TextureEntities>::DefineTexture(texture, pos, origin);
}
