#include "utilities.h"

bool utilities::isWon(const grid& grid_) {
    int totalBoxes = grid_.getTotalBoxes();
    for (int n = 0; n < totalBoxes; n++) {
        if (grid_(n) == EMPTY) {
            return false; //returns false if an empty box is found
        }
    }

    return isValid(grid_); //returns false if the grid isn't valid
}

bool utilities::isValid(const grid& grid_) {
    const int& diagonal = grid_.getDiagonal();
    for (int n = 0; n < diagonal; n++) {
        if (!isColumnValid(grid_, n) || !isRowValid(grid_, n)) {
            return false; //returns false if a column or row isn't valid
        }
    }
    if (!areColumnsUnequal(grid_)) {
        return false; //returns false if two or more columns are identical
    }
    if (!areRowsUnequal(grid_)) {
        return false; //returns false if two or more rows are identical
    }
    return true;
}

bool utilities::isColumnValid(const grid& grid_, const int& x) {
    const int& diagonal = grid_.getDiagonal();
    boxValue list [diagonal];

    utilities_utilities::columnToArray(list, grid_, x);
    return utilities_utilities::isArrayValid(list, diagonal);
}

bool utilities::isRowValid(const grid& grid_, const int& y) {
    const int& diagonal = grid_.getDiagonal();
    boxValue list [diagonal];

    utilities_utilities::rowToArray(list, grid_, y);
    return utilities_utilities::isArrayValid(list, diagonal);
}

bool utilities::areColumnsUnequal(const grid& grid_) {
    const int& diagonal = grid_.getDiagonal();

    boxValue array1 [diagonal];
    boxValue array2 [diagonal];

    for (int n1 = 0; n1 < diagonal; n1++) {
        utilities_utilities::columnToArray(array1, grid_, n1);
        for (int n2 = n1 + 1; n2 < diagonal; n2++) {
            utilities_utilities::columnToArray(array2, grid_, n2);
            if (utilities_utilities::areArraysEqual(array1, array2, diagonal)) {
                    return false;
            }
        }
    }

    return true;
}

bool utilities::areRowsUnequal(const grid& grid_) {
    const int& diagonal = grid_.getDiagonal();

    boxValue array1 [diagonal];
    boxValue array2 [diagonal];

    for (int n1 = 0; n1 < diagonal; n1++) {
        utilities_utilities::rowToArray(array1, grid_, n1);
        for (int n2 = n1 + 1; n2 < diagonal; n2++) {
            utilities_utilities::rowToArray(array2, grid_, n2);
            if (utilities_utilities::areArraysEqual(array1, array2, diagonal)) {
                    return false;
            }
        }
    }

    return true;
}
