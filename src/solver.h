#ifndef SOLVER_H
#define SOLVER_H

#include <box.h>
#include <grid.h>

using namespace box;

class solver {
    public:
        solver();
        virtual ~solver();
        virtual bool solve(grid* grid_);    //attempts to solve the puzzle and fill * grid_ with the correct answer
                                            //returns true on success, otherwise returns false

        bool isWon              (const grid& grid_) const;                  //returns true if the restrictions are met AND all boxes are non-empty
        bool isValid            (const grid& grid_) const;                  //returns true if the restrictions are met
        bool isColumnValid      (const grid& grid_, const int& x) const;    //returns true if the restrictions within column x are met
        bool isRowValid         (const grid& grid_, const int& y) const;
        bool areColumnsUnequal  (const grid& grid_) const;
        bool areRowsUnequal     (const grid& grid_) const;
    protected:
    private:
        bool areArraysEqual(const boxValue* const list1, const boxValue* const list2, const int& diagonal) const;
        bool isArrayValid(const boxValue* const list, const int& diagonal) const;
};

#endif // SOLVER_H
