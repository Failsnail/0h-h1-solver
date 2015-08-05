#include "utilities_utilities.h"

void utilities_utilities::columnToArray(boxValue * const list, const grid& grid_, const int& x) {
    const int& diagonal = grid_.getDiagonal();

    for (int y = 0; y < diagonal; y++) {
        list[y] = grid_(x, y);
    }
}


void utilities_utilities::rowToArray(boxValue * const list, const grid& grid_, const int& y) {
    const int& diagonal = grid_.getDiagonal();

    for (int x = 0; x < diagonal; x++) {
        list[x] = grid_(x, y);
    }
}

bool utilities_utilities::areArraysEqual(const boxValue* const list1, const boxValue* const list2, const int& diagonal) {
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

bool utilities_utilities::isArrayValid(const boxValue* const list, const int& diagonal) {
    int red = 0, blue = 0;
    boxValue currentColour, previousColour = EMPTY;
    int consecutive = 0;

    for (int n = 0; n < diagonal; n++) {
        currentColour = list[n];

        assert(currentColour == RED || currentColour == BLUE || currentColour == EMPTY);

        if (previousColour == currentColour) {
            consecutive++;
            if (consecutive >= 3 && currentColour != EMPTY) {
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
        return false;   //returns false if either red or blue occurs more than half of the time
    }

    return true;
}
