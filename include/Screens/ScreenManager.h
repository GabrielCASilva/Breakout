#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H
#include <memory>

#include "IScreen.h"

class ScreenManager {
public:
     static auto ChangeScreen(std::unique_ptr<IScreen> screen) -> void;
     static auto Init() -> void;
     static auto Update(float dt) -> void;
     static auto Draw() -> void;
     static auto Exit() -> void;
private:
     static std::unique_ptr<IScreen> current_screen;
};

#endif //SCREEN_MANAGER_H
