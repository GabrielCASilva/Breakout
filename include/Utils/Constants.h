#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cstdint>
#include <string>

#include "raylib.h"

namespace game
{
    constexpr std::string ROOT{"../"};
    constexpr std::uint16_t WINDOW_WIDTH{1024};
    constexpr std::uint16_t WINDOW_HEIGHT{768};
    constexpr std::uint8_t FPS{144};
    constexpr std::uint8_t PIXELS_PER_METTER{100};

    namespace paddle {
        constexpr Vector2 SIZE{96.0f, 16.0f};
        constexpr float SPEED{200.0f};
    } // namespace paddle

    namespace ball {
        constexpr std::uint8_t RADIUS{8};
        constexpr float SPEED{300.0f};
    } // namespace ball

    namespace grid {
        constexpr Color COLOR{255,255,255,50};
        constexpr std::uint8_t SIZE{32};
        constexpr std::uint8_t MARGIN_UP{2};
        constexpr std::uint8_t MARGIN_DOWN{6};
        constexpr std::uint8_t MARGIN_LEFT{2};
        constexpr std::uint8_t MARGIN_RIGHT{2};

        constexpr int COLS = (WINDOW_WIDTH - (MARGIN_LEFT * MARGIN_RIGHT) * SIZE) / SIZE;
        constexpr int ROWS = (WINDOW_HEIGHT - (MARGIN_UP * MARGIN_DOWN) * SIZE) / SIZE;
    } // namespace grid

    namespace ui {
        constexpr Vector2 BTN_SIZE{32 * 4, 32};
    }
} // namespace game

#endif // CONSTANTS_H