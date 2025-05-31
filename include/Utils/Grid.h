#ifndef GRID_H
#define GRID_H
#include <cstdint>
#include <concepts>

#include "Constants.h"

class Grid {
public:
    static auto Draw() -> void;

    template<std::invocable<int, int, int, int> Func>
    static auto LoopInsideGrid(Func &&callback) -> void {
        for (int row{0}; row < game::grid::ROWS; ++row) {
            for (int col{0}; col < game::grid::COLS; ++col) {
                const int x{(game::grid::OFFSET_LEFT * game::grid::MARGIN_LEFT) + col * game::grid::SIZE};
                const int y{(game::grid::OFFSET_UP * game::grid::MARGIN_UP) + row * game::grid::SIZE};
                callback(row, col, x, y);
            }
        }
    }

    template<std::invocable<int, int> Func>
    static auto LoopInsideGrid(Func &&callback) -> void {
        for (int row{0}; row < game::grid::ROWS; ++row) {
            for (int col{0}; col < game::grid::COLS; ++col) {
                callback(row, col);
            }
        }
    }

    template<std::invocable Func>
    static auto LoopInsideGrid(Func &&callback) -> void {
        for (int row{0}; row < game::grid::ROWS; ++row) {
            for (int col{0}; col < game::grid::COLS; ++col) {
                callback();
            }
        }
    }
};

#endif //GRID_H
