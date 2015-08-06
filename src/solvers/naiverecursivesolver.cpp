#include "naiverecursivesolver.h"

naiveRecursiveSolver::naiveRecursiveSolver() {
    //ctor
}

naiveRecursiveSolver::~naiveRecursiveSolver() {
    //dtor
}

bool naiveRecursiveSolver::solve(grid* const grid_) {
    int n = findEmpty(*grid_);

    if (n == -1) {
        //if the grid is filled, check if the game is won, if so return true
        if (utilities::isWon(*grid_)) {
            return true;
        } else {
            return false;
        }
    } else {
        //if the grid isn't filled, fill the first empty spot with both RED and BLUE
        //terminate the redGrid and blueGrid early if they aren't valid
        //solve() for both redGrid and blueGrid
        //if one has found a possible result, return true with the answer it gave

        grid redGrid = *grid_;
        redGrid(n) = RED;

        bool isRedSuccesFull = solve(&redGrid);
        if (isRedSuccesFull) {
            *grid_ = redGrid;
            return true;
        }


        grid blueGrid = *grid_;
        blueGrid(n) = BLUE;

        bool isBlueSuccesFull = solve(&blueGrid);
        if (isBlueSuccesFull) {
            *grid_ = blueGrid;
            return true;
        }

        return false;
    }
}

int naiveRecursiveSolver::findEmpty(const grid& grid_) const {
    int totalBoxes = grid_.getTotalBoxes();
    for(int n = 0; n < totalBoxes; n++) {
        if (grid_(n) == EMPTY) {
            return n;
        }
    }
    return -1;
}
