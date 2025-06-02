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
    Storager
};

enum class BrickLengths : uint8_t {
    Single,
    Multiple,
};

class Brick final : public IEntity {
    friend std::ostream &operator<<(std::ostream &os, const Brick &brick);

    BrickTypes type;
    BrickLengths length;
    std::uint8_t size;
    Vector2 position;
    Color color;
    bool is_destroyed;

    Rectangle rect_area;
    std::vector<int> sprite_positions;

public:
    Brick();

    auto Update(float dt) -> void override;
    auto Draw() const -> void override;

    auto Collider() -> void;

    auto Destroy() -> void;
    auto IsDestroyed() const -> bool;

    auto SetPosition(const Vector2 &pos) -> void;
    auto GetPosition() const -> Vector2;

    auto AddSize() -> void;

    auto PushSpritePositions(int x) -> void;
    auto GetSpritePositions() const -> std::vector<int>;

    auto SetLength(BrickLengths l) -> void;
    auto GetLength() const -> BrickLengths;

    auto SetRectangle(const Rectangle &r) -> void;
    auto GetRectangle() const -> Rectangle;
    auto IncreaseRectangle() -> void;
};

#endif //BRICK_H
