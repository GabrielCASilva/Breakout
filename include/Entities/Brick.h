#ifndef BRICK_H
#define BRICK_H
#include <cstdint>
#include <vector>
#include <ostream>

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
    Storager,
    Indestructible // Textura metálica
};

enum class BrickLengths : uint8_t {
    Single,
    Multiple,
};

class Brick final : public IEntity {
    BrickTypes type;
    BrickLengths length;
    Vector2 position;
    Color color;
    bool is_destroyed;
    std::uint8_t lives;
    Rectangle texture;

    Rectangle collision_area;
    std::vector<int> sprite_positions;

public:
    Brick() = delete;
    Brick(const BrickTypes& type, const BrickLengths& length, const Vector2 &position);

    auto Update(float dt) -> void override;
    auto Draw() const -> void override;

    auto IncriseSize(int pos_x) -> void;

    auto Destroy() -> void;
    auto IsDestroyed() const -> bool;

    auto GetSpritePositions() const -> std::vector<int>;
    auto GetCollisionArea() const -> Rectangle;

    auto GetTexture() const -> Rectangle;
    auto DefineRandomTexture() -> Rectangle;

    auto OnCollision(const IEntity& entity) -> void override;
};

#endif //BRICK_H
