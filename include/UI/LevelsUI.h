#ifndef LEVELS_UI_H
#define LEVELS_UI_H
#include "IUserInterface.h"

class LevelsUI final : public IUserInterface {
public:
    auto Draw() const -> void override;
};

#endif //LEVELS_UI_H
