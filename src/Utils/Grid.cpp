#include "Utils/Grid.h"

#include "raylib.h"
#include "Utils/Constants.h"

auto Grid::Draw() -> void {
    LoopInsideGrid([](const int row, const int col, const int x, const int y) -> void {

        // DrawRectangle(x+1, y+1, game::grid::SIZE-1, game::grid::SIZE-1, game::grid::COLOR);
        DrawRectangle(x, y, game::grid::SIZE, game::grid::SIZE, game::grid::COLOR);
        // DrawRectangleLines(x+1, y+1, game::grid::SIZE-1, game::grid::SIZE-1, BLACK);
        // Rectangle rect {(float)x+1, (float)y+1, game::grid::SIZE-1, game::grid::SIZE-1};
        Rectangle rect {(float)x, (float)y, game::grid::SIZE, game::grid::SIZE};
        DrawRectangleLinesEx(rect, .5, BLACK);
    });
}