#include "Utils/Grid.h"

#include "raylib.h"
#include "Utils/Constants.h"

auto Grid::Draw() -> void {
    LoopInsideGrid([](const int row, const int col, const int x, const int y) -> void {

        DrawRectangle(x+1, y+1, game::grid::SIZE-1, game::grid::SIZE-1, game::grid::COLOR);
        DrawRectangleLines(x+1, y+1, game::grid::SIZE-1, game::grid::SIZE-1, BLACK);
    });
}