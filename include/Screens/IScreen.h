#ifndef I_SCREEN_H
#define I_SCREEN_H

class IScreen {
public:
    virtual ~IScreen() = default;
    virtual auto Init() -> void = 0;
    virtual auto Update(float dt) -> void = 0;
    virtual auto Draw() -> void = 0;
    virtual auto Exit() -> void = 0;
};

#endif //I_SCREEN_H
