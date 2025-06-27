#ifndef SCREENS_H
#define SCREENS_H
#include <cstdint>

enum class Screens : std::uint8_t {
    MENU,
    GAME,
    WIN,
    CREDITS,
    GAME_OVER
};

#endif //SCREENS_H
