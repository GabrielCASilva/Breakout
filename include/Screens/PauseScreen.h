#ifndef PAUSE_SCREEN_H
#define PAUSE_SCREEN_H
#include <memory>
#include <string>

#include "IScreen.h"
#include "UI/PauseScreenUI.h"

class PauseScreen final : public IScreen {
public:
    auto Init() -> void override;

    auto Update(float dt) -> void override;

    auto Draw() -> void override;

    auto Exit() -> void override {
    }

    [[nodiscard]] auto GetContinue() const -> bool {
        return m_ui->GetContinue();
    }

    auto SetContinue(const bool cnt_game) const -> void {
        m_ui->SetContinue(cnt_game);
    }
private:
    std::string m_text{"Pausado"};
    std::unique_ptr<PauseScreenUI> m_ui{std::make_unique<PauseScreenUI>()};
};

#endif //PAUSE_SCREEN_H
