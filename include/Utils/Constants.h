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
    constexpr std::uint8_t FPS{60};
    constexpr std::uint8_t PIXELS_PER_METTER{100};

    namespace grid {
        constexpr Color COLOR{255,255,255,50};
        constexpr std::uint8_t SIZE{32};
        constexpr std::uint8_t MARGIN_UP{3};
        constexpr std::uint8_t MARGIN_DOWN{6};
        constexpr std::uint8_t MARGIN_LEFT{2};
        constexpr std::uint8_t MARGIN_RIGHT{2};

        constexpr int OFFSET_UP{SIZE};
        constexpr int OFFSET_DOWN{SIZE * 2};
        constexpr int OFFSET_LEFT{SIZE};
        constexpr int OFFSET_RIGHT{SIZE * 2};

        constexpr int COLS{(WINDOW_WIDTH - OFFSET_RIGHT * MARGIN_RIGHT) / SIZE};
        constexpr int ROWS{(WINDOW_HEIGHT - OFFSET_DOWN * MARGIN_DOWN) / SIZE};

        constexpr std::size_t MAX_CELLS{ROWS * COLS};
    } // namespace grid
} // namespace game

#endif // CONSTANTS_H
