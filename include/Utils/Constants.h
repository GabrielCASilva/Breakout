#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cstdint>
#include <string>

#include "raylib.h"

namespace game
{
    constexpr std::string ROOT{"../"};
    constexpr std::uint8_t SCALE{4};
    constexpr std::uint16_t WINDOW_WIDTH{320*SCALE};
    constexpr std::uint16_t WINDOW_HEIGHT{240*SCALE};
    constexpr std::uint8_t FPS{144};
    constexpr std::uint8_t PIXELS_PER_METTER{100};

    namespace paddle {
        constexpr Vector2 SIZE{8 * 5 * SCALE, 8 * SCALE};
        constexpr float SPEED{120.0f*SCALE};
    } // namespace paddle

    namespace ball {
        constexpr std::uint8_t RADIUS{3*SCALE};
        constexpr float SPEED{120.0f*SCALE};
    } // namespace ball

    namespace grid {
        constexpr Color COLOR{255,255,255,50};
        constexpr std::uint8_t SIZE{8*SCALE};
        constexpr std::uint8_t O_SIZE{8};
        constexpr std::uint8_t MARGIN_UP{3};
        constexpr std::uint8_t MARGIN_DOWN{6};
        constexpr std::uint8_t MARGIN_LEFT{2};
        constexpr std::uint8_t MARGIN_RIGHT{2};

        constexpr int COLS = (WINDOW_WIDTH - (MARGIN_LEFT * MARGIN_RIGHT) * SIZE) / SIZE;
        constexpr int ROWS = (WINDOW_HEIGHT - (MARGIN_UP * MARGIN_DOWN) * SIZE) / SIZE;
    } // namespace grid

    namespace ui {
        constexpr float SIZE_12{12.0f*SCALE};
        constexpr float SIZE_16{16.0f*SCALE};
        constexpr float SIZE_20{20.0f*SCALE};
    }

    namespace level {
        constexpr int MAX_LEVEL{2};
    }
} // namespace game

#endif // CONSTANTS_H