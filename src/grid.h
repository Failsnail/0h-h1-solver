#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>
#include <assert.h>

#include "box.h"

using namespace box;
using namespace std;

class grid {
    public:
        grid();
        grid(const int& newDiagonal);
        grid(const grid& other);
        virtual ~grid();

        void initialize(const int& newDiagonal);

        grid& operator = (const grid& other);
        boxValue& operator () (const int& x, const int& y) const;
        boxValue& operator () (const int& n) const;

        const int& getDiagonal() const;
        int getTotalBoxes() const;

        void printMatrix() const;
    protected:
    private:
        int diagonal = 0;
        boxValue* matrix = nullptr;
};

#endif // GRID_H
