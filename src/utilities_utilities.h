#ifndef UTILITIES_UTILITIES_H
#define UTILITIES_UTILITIES_H

#include <iostream>
#include <assert.h>

#include "box.h"
#include "grid.h"

using namespace box;

namespace utilities_utilities {
    void columnToArray   (boxValue * const list, const grid& grid_, const int& x);
    void rowToArray      (boxValue * const list, const grid& grid_, const int& y);
    bool areArraysEqual  (const boxValue* const list1, const boxValue* const list2, const int& diagonal);
    bool isArrayValid    (const boxValue* const list, const int& diagonal);

    using namespace box;
}

#endif // UTILITIES_UTILITIES_H
