#ifndef UTILITIES_H
#define UTILITIES_H

#include "box.h"
#include "grid.h"
#include "utilities_utilities.h"

namespace utilities {
    bool isWon               (const grid& grid_);
    bool isValid             (const grid& grid_);
    bool isColumnValid       (const grid& grid_, const int& x);
    bool isRowValid          (const grid& grid_, const int& y);
    bool areColumnsUnequal   (const grid& grid_);
    bool areRowsUnequal      (const grid& grid_);

    using namespace box;
}

#endif // UTILITIES_H
