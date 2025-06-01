#ifndef LEVEL_H
#define LEVEL_H
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "Entities/Brick.h"
#include "Utils/Grid.h"

class BrickSet {
    std::vector<std::string> layout;

    std::vector<std::unique_ptr<Brick>> bricks;

public:
    explicit BrickSet(const std::vector<std::string> &layout);

    ~BrickSet() = default;
    auto InitializeBricks() -> void;
    auto Draw() const -> void;
};

#endif //LEVEL_H
