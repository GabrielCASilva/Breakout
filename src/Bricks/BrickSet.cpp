#include "Bricks/BrickSet.h"

#include <algorithm>
#include <memory>
#include <iostream>

#include "Utils/Grid.h"
#include "Entities/Brick.h"

BrickSet::BrickSet(const std::vector<std::string> &layout) : layout{layout}, bricks{} {
}

auto BrickSet::InitializeBricks() -> void {
    const auto max_rows{layout.size()};
    Grid::LoopInsideGrid([&](const int row, const int col, const int x, const int y) -> void {
        if (row >= static_cast<int>(max_rows)) return;
        const std::string &line = layout[row];

        if (col >= static_cast<int>(line.size())) return;
        const char tile = line[col];
        if (tile == '.') return;

        this->FactoryBrick(tile, x, y);
    });
}

auto BrickSet::FactoryBrick(const char &tile, const int x, const int y) -> void {
    switch (tile) {
        case '0':
            this->CreateOrUpdateBrick(BrickTypes::Default, BrickLengths::Single, x, y);
            break;
        case '1':
            this->CreateOrUpdateBrick(BrickTypes::Default, BrickLengths::Multiple, x, y);
            break;
        default:
            this->CreateOrUpdateBrick(BrickTypes::Default, BrickLengths::Single, x, y);
            break;
    }
}

/*
 * Create a new Brick or Update  it`s size dynamic if there BrickLengths is Multiple
 */
auto BrickSet::CreateOrUpdateBrick(const BrickTypes &type, const BrickLengths &len, const int x, const int y) -> void {
    if (!bricks.empty() && len == BrickLengths::Multiple) {
        if (const auto &last_brick = bricks.back();
            !last_brick->GetSpritePositions().empty() &&
            last_brick->GetSpritePositions().size() < 2
            ) {
            const auto last_position{last_brick->GetSpritePositions().back()};
            if (const auto next_position = last_position + game::grid::SIZE; next_position == x) {
                bricks.back()->IncreaseSize(x);
                return;
            }
        }
    }

    Vector2 pos {static_cast<float>(x), static_cast<float>(y)};
    auto brick{std::make_unique<Brick>(type, len, pos)};
    bricks.push_back(std::move(brick));
}

auto BrickSet::Draw() const -> void {
    for (const auto &brick: bricks) {
        brick->Draw();
    }
}

auto BrickSet::SafelyDestroyBricks() -> void {
    std::erase_if(bricks,
                  [](const std::unique_ptr<Brick> &brick) {
                      return brick->IsDestroyed();
                  });
}

auto BrickSet::OnCollision(Ball &ball) const -> void {
    for (const auto &brick: bricks) {
        if (ball.CheckCollisionWithBrick(*brick)) {
            brick->Destroy();
        }
    }
}
