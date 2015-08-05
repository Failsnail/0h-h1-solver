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
        if (utilities::isWon(*grid_)) {
            return true;
        } else {
            return false;
        }
    }

    grid redGrid = *grid_;
    redGrid(n) = RED;

    bool isRedSuccesFull = false;

    if (utilities::isValid(redGrid)) {
        isRedSuccesFull = solve(&redGrid);
    }

    if (isRedSuccesFull) {
        *grid_ = redGrid;
        return true;
    }


    grid blueGrid = *grid_;
    blueGrid(n) = BLUE;

    bool isBlueSuccesFull = false;

    if (utilities::isValid(blueGrid)) {
        isBlueSuccesFull = solve(&blueGrid);
    }

    if (isBlueSuccesFull) {
        *grid_ = blueGrid;
        return true;
    }

    return false;
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
