#ifndef GRID_H
#define GRID_H
#include <cstdint>
#include <concepts>

#include "Constants.h"

class Grid {
public:
    static std::uint8_t cell_size;
    static int offset_up;
    static int offset_down;
    static int offset_left;
    static int offset_right;
    static int cols;
    static int rows;

    static auto Draw() -> void;

    template<std::invocable<int, int, int, int> Func>
    static auto LoopInsideGrid(Func &&callback) -> void {
        for (int row {0}; row < rows; ++row) {
            for (int col {0}; col < cols; ++col) {
                const int x {(offset_left * game::grid::MARGIN_LEFT) + col * cell_size};
                const int y {(offset_up * game::grid::MARGIN_UP) + row * cell_size};
                callback(row, col, x, y);
            }
        }
    }
};

#endif //GRID_H
