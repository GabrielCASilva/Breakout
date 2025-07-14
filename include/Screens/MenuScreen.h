#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H
#include <memory>

#include "IScreen.h"
#include "UI/MenuScreenUI.h"
#include "Utils/Background.h"
#include "Utils/Parallax.h"
#include "Utils/Translate.h"

struct MinMax {
    float min;
    float max;
};

enum class BackgroundsLayers {
    LAYER_0,
    LAYER_START_1,
    LAYER_1,
    LAYER_2,
    LAYER_3,
    LAYER_4,
    LAYER_START_2,
    LEN
};

enum class BackgroundPlanets {
    BACK,
    MIDDLE,
    FRONT,
    LEN
};

constexpr std::array<Vector2,
    static_cast<std::size_t>(BackgroundsLayers::LEN)> s_planets_position = {
    {
        {100.f * game::SCALE, game::WINDOW_HEIGHT / 2 + 70.f * game::SCALE},
        {30.f * game::SCALE, game::WINDOW_HEIGHT / 2 + 70.f * game::SCALE},
        {game::WINDOW_WIDTH, game::WINDOW_HEIGHT / 2 + 90.f * game::SCALE}
    }
};

constexpr std::array<float,
    static_cast<std::size_t>(BackgroundsLayers::LEN)> s_planets_translations = {
    {
        game::SCALE,
        4 * game::SCALE,
        6 * game::SCALE
    }
};

constexpr std::array<MinMax,
    static_cast<std::size_t>(BackgroundsLayers::LEN)> s_planets_translations_cap = {
    {
        {-50.f, 80.f},
        {-100.f, 120.f},
        {-150.f, 140.f}
    }
};

class MenuScreen final : public IScreen {
    std::string BG_DIR = "title_screen/";

public:
    auto Init() -> void override;

    auto Update(float dt) -> void override;

    auto Draw() -> void override;

    auto Exit() -> void override;

private:
    std::unique_ptr<MenuScreenUI> m_ui{std::make_unique<MenuScreenUI>()};
    Background m_bg{};
    Background m_bg_planets{};

    std::array<Parallax<Background>,
        static_cast<std::size_t>(BackgroundsLayers::LEN)> m_background_layers{};

    std::array<Translate<Background>,
        static_cast<std::size_t>(BackgroundPlanets::LEN)> m_planets{};

    auto InitializeBackgrounds() -> void;

    auto UnloadBackgrounds() -> void;

    auto AnimatePlanets(float dt) -> void;

    static auto DrawTittle() -> void;
};

#endif //MENU_SCREEN_H
