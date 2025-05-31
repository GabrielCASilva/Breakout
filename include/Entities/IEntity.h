#ifndef I_ENTITY_H
#define I_ENTITY_H

class IEntity {
public:
    virtual ~IEntity() = default;
    virtual auto Update(float dt) -> void = 0;
    virtual auto Draw() const -> void = 0;
};

#endif //I_ENTITY_H
