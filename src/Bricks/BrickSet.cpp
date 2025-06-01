#include "Bricks/BrickSet.h"

#include <iostream>
#include <memory>
#include <bits/ostream.tcc>

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

        //TODO: REFATORAR
        if (tile == '0') {
            auto brick = std::make_unique<Brick>();
            brick->SetLength(BrickLengths::Single);
            brick->SetPosition(Vector2{static_cast<float>(x), static_cast<float>(y)});
            brick->PushSpritePositions(x);
            bricks.push_back(std::move(brick));
            return;
        }

        if (tile == '1') {
            if (!bricks.empty() && bricks.back()->GetLength() == BrickLengths::Multiple) {
                const auto &last_brick_position {bricks.back()->GetSpritePositions()};
                if (const int lastBrickRightEdge{last_brick_position.back() + 32};
                    lastBrickRightEdge == x) {
                    bricks.back()->SetLength(BrickLengths::Multiple);
                    bricks.back()->PushSpritePositions(x);
                    return;
                }
            }

            auto brick = std::make_unique<Brick>();
            brick->SetLength(BrickLengths::Multiple);
            brick->SetPosition(Vector2{static_cast<float>(x), static_cast<float>(y)});
            brick->PushSpritePositions(x);
            bricks.push_back(std::move(brick));
        }
    });
}

auto BrickSet::Draw() const -> void {
    for (const auto &brick: bricks) {
        brick->Draw();
    }
}
