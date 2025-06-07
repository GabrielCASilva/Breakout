#ifndef I_ENTITY_H
#define I_ENTITY_H

class IEntity {
public:
    virtual ~IEntity() = default;
    virtual auto Update(float dt) -> void = 0;
    virtual auto Draw() const -> void = 0;

    template <typename T>
    [[nodiscard]] const T& GetInstanceOf() const {
        return static_cast<const T&>(*this);
    }

    virtual auto OnCollision(const IEntity& entity) -> void = 0;
};

#endif //I_ENTITY_H
