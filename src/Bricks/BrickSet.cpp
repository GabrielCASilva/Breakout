#include "Bricks/BrickSet.h"

#include <iostream>

#include "raylib.h"
#include "Utils/Grid.h"

BrickSet::BrickSet(const std::vector<std::string> &layout) : layout{layout} {}

auto BrickSet::Draw() const -> void {
    Grid::LoopInsideGrid([&](const int row, const int col, const int x, const int y) -> void {
        if (row >= static_cast<int>(layout.size())) return;
        const std::string& line = layout[row];

        if (col >= static_cast<int>(line.size())) return;

        const char tile = line[col];
        if (tile == '.') return;

        auto color = WHITE;
        if (tile == '1') color = RED;
        else if (tile == '2') color = ORANGE;
        else if (tile == 'x') color = BLUE;

        DrawRectangle(x, y, Grid::cell_size, Grid::cell_size, color);
    });
}

