#ifndef I_USER_INTERFACE_H
#define I_USER_INTERFACE_H

class IUserInterface {
public:
    virtual ~IUserInterface() = default;
    virtual auto Update() -> void = 0;
    virtual auto Draw() const -> void = 0;
};

#endif //I_USER_INTERFACE_H
