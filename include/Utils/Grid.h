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
                int x {(game::grid::MARGIN_LEFT * game::grid::SIZE) + col * game::grid::SIZE};
                int y {(game::grid::MARGIN_UP * game::grid::SIZE) + row * game::grid::SIZE};
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
