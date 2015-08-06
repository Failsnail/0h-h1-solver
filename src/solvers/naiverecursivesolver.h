#ifndef NAIVERECURSIVESOLVER_H
#define NAIVERECURSIVESOLVER_H

#include "solver.h"


class naiveRecursiveSolver : public solver
{
    public:
        naiveRecursiveSolver();
        virtual ~naiveRecursiveSolver();
        virtual bool solve(grid* const grid_);
    protected:
    private:
        int findEmpty(const grid& grid_) const;
};

#endif // NAIVERECURSIVESOLVER_H
