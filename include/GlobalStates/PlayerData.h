#ifndef PLAYER_DATA_H
#define PLAYER_DATA_H
#include <cstdint>

class PlayerData {
public:
    PlayerData() = delete;

    static auto Reset() -> void {
        m_lives = 3;
        m_lose = false;
        m_points = 0;
    }

    static auto ResetLives() -> void {
        m_lives = 3;
    }

    static auto GetLives() -> int {
        return m_lives;
    }

    static auto DidPlayerLose() -> bool {
        return m_lose;
    }

    static auto GetPoints() -> int {
        return m_points;
    }

    static auto DecrementLives() -> void {
        if (m_lives > 0)
            --m_lives;
    }

    static auto PlayerLost() -> void {
        m_lose = true;
    }

    static auto GainPoints(const int points) -> void {
        m_points += points;
    }

    static auto LosePoints(const int points) -> void {
        m_points -= points;
    }
private:
    inline static std::uint8_t m_lives {3};
    inline static bool m_lose {false};
    inline static int m_points {0};
};

#endif //PLAYER_DATA_H
