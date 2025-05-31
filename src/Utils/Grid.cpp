#include "Utils/Grid.h"

#include "raylib.h"
#include "Utils/Constants.h"

auto Grid::Draw() -> void {
    LoopInsideGrid([](const int row, const int col, const int x, const int y) -> void {
         DrawRectangleLines(x, y, game::grid::SIZE, game::grid::SIZE, game::grid::COLOR);
    });
}