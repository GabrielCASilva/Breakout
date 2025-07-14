#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H
#include <memory>

#include "IScreen.h"
#include "UI/MenuScreenUI.h"
#include "Utils/Background.h"
#include "Utils/Parallax.h"

enum class BackgroundsLayers {
    LAYER_0,
    LAYER_1,
    LAYER_2,
    LAYER_3,
    LAYER_4,
    LAYER_5,
    LEN
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
        static_cast<std::size_t>(BackgroundsLayers::LEN)> m_BackgroundLayers{};

    auto InitializeBackgrounds() -> void;

    auto UnloadBackgrounds() -> void;
};

#endif //MENU_SCREEN_H
