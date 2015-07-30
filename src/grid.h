#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>
#include <assert.h>

#include <box.h>

using namespace std;

class grid {
    public:
        grid();
        grid(const int& newDiagonal);
        grid(const grid& other);
        virtual ~grid();

        void initialize(const int& newDiagonal);

        grid& operator = (const grid& other);
        box& operator () (const int& x, const int& y) const;
        box& operator () (const int& n) const;

        int getDiagonal() const;
        int getTotalBoxes() const;

        void printMatrix() const;
    protected:
    private:
        int diagonal = 0;
        box *matrix = nullptr;
};

#endif // GRID_H
