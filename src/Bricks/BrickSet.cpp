#include "Bricks/BrickSet.h"

#include <iostream>
#include <memory>
#include <bits/ostream.tcc>

#include "Utils/Grid.h"
#include "Entities/Brick.h"

static int count = 0;

BrickSet::BrickSet(const std::vector<std::string> &layout) : layout{layout}, bricks{} {}

auto BrickSet::InitializeBricks() -> void {
    const auto max_rows {layout.size()};
    Grid::LoopInsideGrid([&](const int row, const int col, const int x, const int y) -> void {
        if (row >= static_cast<int>(max_rows)) return;
        const std::string& line = layout[row];

        if (col >= static_cast<int>(line.size())) return;
        const char tile = line[col];
        if (tile == '.') return;

        auto brick {std::make_unique<Brick>()};
        brick->SetPosition(Vector2{static_cast<float>(x), static_cast<float>(y)});
        bricks[row][col] = std::move(brick);
        count++;
    });
}


auto BrickSet::Draw() const -> void {
    Grid::LoopInsideGrid([&](const int row, const int col, const int x, const int y) -> void {
        if (row >= static_cast<int>(layout.size())) return;
        const std::string& line = layout[row];

        if (col >= static_cast<int>(line.size())) return;

        const char tile = line[col];
        if (tile == '.') return;

        bricks[row][col]->Draw();
    });
}

