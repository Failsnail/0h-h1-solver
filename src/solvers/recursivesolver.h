#ifndef RECURSIVESOLVER_H
#define RECURSIVESOLVER_H

#include "solver.h"

class recursiveSolver : public solver {
    public:
        recursiveSolver();
        virtual ~recursiveSolver();
        virtual bool solve(grid* const grid_);
    protected:
    private:
        int findEmpty(const grid& grid_) const;
};

#endif // RECURSIVESOLVER_H
