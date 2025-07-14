#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H
#include <memory>

#include "IScreen.h"
#include "Screens.h"

class ScreenManager {
public:
     static auto ChangeScreen(Screens screen) -> void;
     static auto Init() -> void;
     static auto Update(float dt) -> void;
     static auto Draw() -> void;
     static auto Exit() -> void;

private:
     static std::unique_ptr<IScreen> current_screen;
     static inline bool m_screen_changed = false;

};

#endif //SCREEN_MANAGER_H
