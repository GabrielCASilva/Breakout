#ifndef BRICK_H
#define BRICK_H
#include <cstdint>
#include <vector>
#include <ostream>

#include "IEntity.h"
#include "raylib.h"
#include "Utils/Constants.h"

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

    Color color{WHITE};
    bool is_destroyed{false};
    std::uint8_t lives{1};
    Rectangle texture{};
    Rectangle collision_area{position.x, position.y, game::grid::SIZE, game::grid::SIZE};
    std::vector<int> sprite_positions;

public:
    Brick() = delete;

    Brick(const BrickTypes &type, const BrickLengths &length, const Vector2 &position);

    auto Update(float dt) -> void override;

    auto Draw() const -> void override;

    auto IncreaseSize(int pos_x) -> void;

    [[nodiscard]] auto DefineRandomTexture() const -> Rectangle;

    auto OnCollision(const IEntity &entity) -> void override;

    // inlines
    [[nodiscard]] auto IsDestroyed() const -> bool {
        return is_destroyed;
    }

    auto Destroy() -> void {
        is_destroyed = true;
    }

    [[nodiscard]] auto GetSpritePositions() const -> const std::vector<int> & {
        return sprite_positions;
    }

    [[nodiscard]] auto GetCollisionArea() const -> const Rectangle & {
        return collision_area;
    }

    [[nodiscard]] auto GetTexture() const -> const Rectangle & {
        return texture;
    }

    [[nodiscard]] auto GetPosition() const -> const Vector2 & {
        return position;
    }
};

#endif //BRICK_H
