#include "recursivesolver.h"

recursiveSolver::recursiveSolver() {
    //ctor
}

recursiveSolver::~recursiveSolver() {
    //dtor
}

bool recursiveSolver::solve(grid* const grid_) {
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

        if (utilities::isValid(redGrid)) {             //early termination
            bool isRedSuccesFull = solve(&redGrid);
            if (isRedSuccesFull) {
                *grid_ = redGrid;
                return true;
            }
        }


        grid blueGrid = *grid_;
        blueGrid(n) = BLUE;

        if (utilities::isValid(blueGrid)) {             //early termination
            bool isBlueSuccesFull = solve(&blueGrid);
            if (isBlueSuccesFull) {
                *grid_ = blueGrid;
                return true;
            }
        }

        return false;
    }
}

int recursiveSolver::findEmpty(const grid& grid_) const {
    int totalBoxes = grid_.getTotalBoxes();
    for(int n = 0; n < totalBoxes; n++) {
        if (grid_(n) == EMPTY) {
            return n;
        }
    }
    return -1;
}
