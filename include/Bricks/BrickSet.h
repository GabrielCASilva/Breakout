#ifndef LEVEL_H
#define LEVEL_H
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "Entities/Ball.h"
#include "Entities/Brick.h"
#include "Utils/Grid.h"

class BrickSet {
    std::vector<std::string> layout;
    std::vector<std::unique_ptr<Brick>> bricks;

    auto CreateOrUpdateBrick(const BrickTypes& type, const BrickLengths& len, int x, int y) -> void;
    auto FactoryBrick(const char& tile, int x, int y) -> void;
public:
    explicit BrickSet(const std::vector<std::string> &layout);

    ~BrickSet() = default;
    auto InitializeBricks() -> void;
    auto Draw() const -> void;

    auto SafalyDestroyBricks() -> void;

    // collision
    auto OnCollision(const Ball& ball) const -> void;
};

#endif //LEVEL_H
