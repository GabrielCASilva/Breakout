#ifndef GAME_H
#define GAME_H

#include <string>

class Game
{
    static auto Draw() -> void;
    static auto Update() -> void;
public:
    Game() = delete;
    Game(const Game &other) = delete;
    Game &operator=(const Game &other) = delete;

    [[nodiscard]] static auto GameShouldClose() -> bool;
    static auto Initialize(int width, int height, const std::string &title) -> void;
    static auto Tick() -> void;
    static auto Unload() -> void;
};

#endif //GAME_H
