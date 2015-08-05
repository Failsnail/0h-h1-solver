#ifndef SOLVER_H
#define SOLVER_H

#include "box.h"
#include "grid.h"
#include "utilities.h"

using namespace box;
using namespace utilities;

class solver {
    public:
        solver();
        virtual ~solver();
        virtual bool solve(grid* const grid_)=0;    //returns true if a valid solution is found
                                                    //on success, the solution is stored in *grid
    protected:
    private:
};

#endif // SOLVER_H
