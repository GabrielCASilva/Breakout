#ifndef BRICK_H
#define BRICK_H
#include <cstdint>

#include "IEntity.h"
#include "raylib.h"

/*
 * Types of bricks:
 *  - Default:
 *      - '0' on txt
 *      - 1 hit to be destroyed
 *  - Storager:
 *      - '1' on txt
 *      - 1 hit to be destroyed
 *      - stores an item
 */

enum class BrickTypes : uint8_t {
    Default,
    Storager
};

class Brick final : public IEntity {
    BrickTypes type;
    std::uint8_t size;
    Vector2 position;
    Color color;

public:
    Brick();

    auto Update(float dt) -> void override;
    auto Draw() const -> void override;

    auto Collider() -> void;
    auto SetPosition(const Vector2 &pos) -> void;
};

#endif //BRICK_H
