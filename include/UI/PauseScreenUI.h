#ifndef PAUSE_SCREEN_UI_H
#define PAUSE_SCREEN_UI_H
#include <array>
#include <memory>

#include "Button.h"
#include "IUserInterface.h"

class PauseScreenUI final : public IUserInterface {
public:
    PauseScreenUI();

    auto Update() -> void override;

    auto Draw() const -> void override;

    [[nodiscard]] auto GetContinue() const -> bool {
        return m_continue;
    }

    auto SetContinue(const bool cnt_game) -> void {
        m_continue = cnt_game;
    }

private:
    std::array<std::unique_ptr<Button>, 4> m_buttons{};
    bool m_continue{false};

    auto ShowPlayerData() const -> void;
};

#endif //PAUSE_SCREEN_UI_H
