#ifndef LEVELS_UI_H
#define LEVELS_UI_H
#include "IUserInterface.h"

class GameScreenUI final : public IUserInterface {
public:
    auto Update() -> void override;

    auto Draw() const -> void override;

    auto SetLevel(const int level) -> void {
        m_level = level;
    }
private:
    int m_level{0};
};

#endif //LEVELS_UI_H
