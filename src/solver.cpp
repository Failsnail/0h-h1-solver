#include "solver.h"

solver::solver() {
    //ctor
}

solver::~solver() {
    //dtor
}

bool solver::solve(grid* grid_) {

}

bool solver::isWon(const grid& grid_) const {
    int totalBoxes = grid_.getTotalBoxes();
    for (int n = 0; n < totalBoxes; n++) {
        if (grid_(n) == EMPTY) {
            return false; //returns false if an empty box is found
        }
    }

    return isValid(grid_); //returns false if the grid isn't valid
}

bool solver::isValid(const grid& grid_) const {
    const int& diagonal = grid_.getDiagonal();
    for (int n = 0; n < diagonal; n++) {
        if (!isColumnValid(grid_, n) || !isRowValid(grid_, n)) {
            return false; //returns false if a column or row isn't valid
        }
    }
    if (!areColumnsUnequal(grid_)) {
        return false; //returns false if two or more colums are identical
    }
    if (!areRowsUnequal(grid_)) {
        return false; //returns false if two or more rows are identical
    }
    return true;
}

bool solver::isColumnValid(const grid& grid_, const int& x) const {
    const int& diagonal = grid_.getDiagonal();
    boxValue list [diagonal];
    for (int y = 0; y < diagonal; y++) {
        list[y] = grid_(x, y);
    }
    return isArrayValid(list, diagonal);
}

bool solver::isRowValid(const grid& grid_, const int& y) const {
    const int& diagonal = grid_.getDiagonal();
    boxValue list [diagonal];
    for (int x = 0; x < diagonal; x++) {
        list[x] = grid_(x, y);
    }
    return isArrayValid(list, diagonal);
}

bool solver::areColumnsUnequal(const grid& grid_) const {
    return true;
}

bool solver::areRowsUnequal(const grid& grid_) const {
    return true;
}

bool solver::areArraysEqual(const boxValue* const list1, const boxValue* const list2, const int& diagonal) const {
    for (int n = 0; n < diagonal; n++) {
        if (list1[n] != list2[n]) {
            return false;   //the values of list1 and list2 for a particular index isn't equal, so the arrays aren't equal
        } else if (list1[n] == EMPTY) {
            return false;   //if an empty box is found, the value of the array isn't definitive
                            //so whether the arrays are the same can't yet be known
        }
    }
    return true;    //if no differences are found
}

bool solver::isArrayValid(const boxValue* const list, const int& diagonal) const {
    int red = 0, blue = 0;
    boxValue currentColour, previousColour = EMPTY;
    int consecutive = 0;

    for (int n = 0; n < diagonal; n++) {
        currentColour = list[n];

        if (previousColour == currentColour) {
            consecutive++;
            if (consecutive >= 3 && previousColour != EMPTY) {
                return false;   //return false if three consecutive colours are found that aren't empty
            }
        } else {
            previousColour = currentColour;
            consecutive = 1;
        }


        //keep track of the red and blue counters
        if (currentColour == RED) {
            red++;
        } else if (currentColour == BLUE) {
            blue++;
        }
    }

    if (red * 2 > diagonal || blue * 2 > diagonal) {
        return false;   //returns false if either red or blue occurs more than five times
    }

    return true;
}
