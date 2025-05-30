#include "Utils/Grid.h"

#include "raylib.h"
#include "Utils/Constants.h"

// tamanho da célula da grid
std::uint8_t Grid::cell_size = game::grid::SIZE;

// offset para consertar a posição da grid
int Grid::offset_up = game::grid::SIZE;
int Grid::offset_down = game::grid::SIZE * 2;
int Grid::offset_left = game::grid::SIZE;
int Grid::offset_right = game::grid::SIZE * 2;

// pega a quantidade de colunas e linhas que vai ter
int Grid::cols = {(game::WINDOW_WIDTH - offset_right * game::grid::MARGIN_RIGHT) / cell_size};
int Grid::rows = {(game::WINDOW_HEIGHT - offset_down * game::grid::MARGIN_DOWN) / cell_size};

auto Grid::Draw() -> void {
    LoopInsideGrid([](const int row, const int col, const int x, const int y) -> void {
         DrawRectangleLines(x, y, cell_size, cell_size, game::grid::COLOR);
    });
}