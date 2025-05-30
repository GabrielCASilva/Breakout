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
        constexpr std::uint8_t SIZE{16};
        constexpr std::uint8_t MARGIN_UP{3};
        constexpr std::uint8_t MARGIN_DOWN{8};
        constexpr std::uint8_t MARGIN_LEFT{2};
        constexpr std::uint8_t MARGIN_RIGHT{2};
    } // namespace grid
} // namespace game

#endif // CONSTANTS_H
