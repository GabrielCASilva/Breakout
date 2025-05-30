#ifndef BRICK_H
#define BRICK_H
#include <cstdint>

#include "IEntity.h"

/*
 * Types of bricks:
 *  - Default:
 *      - 1 hit to be destroyed
 *  - Storager:
 *      - 1 hit to be destroyed
 *      - stores an item
 */

enum class BrickTypes : uint8_t {
    Default,
    Storager
};

class Brick final : public IEntity {
    std::uint8_t type;
    std::uint8_t height;
    std::uint8_t width;
    public:
        Brick();

        auto Update(float dt) -> void override;
        auto Draw() -> void override;
};

#endif //BRICK_H
