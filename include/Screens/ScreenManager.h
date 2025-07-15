#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H
#include <memory>

#include "IScreen.h"
#include "Screens.h"

class ScreenManager {
public:
     static auto ChangeScreen(Screens screen) -> void;
     static auto UpdateCurrentScreen() -> void;
     static auto Init() -> void;
     static auto Update(float dt) -> void;
     static auto Draw() -> void;
     static auto Exit() -> void;

private:
     static inline std::unique_ptr<IScreen> current_screen {nullptr};
     static inline std::unique_ptr<IScreen> next_screen {nullptr};
     static inline bool m_screen_changed {nullptr};
};

#endif //SCREEN_MANAGER_H
