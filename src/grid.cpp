#include "grid.h"

grid::grid() {

}

grid::grid(const int& newDiagonal) {
    initialize(newDiagonal);
}

grid::grid(const grid& other) {
    *this = other;
}

grid::~grid() {
    delete[] matrix;
}

void grid::initialize(const int& newDiagonal) {
    //clean old matrix
    if (diagonal != 0){
        delete[] matrix;
        diagonal = 0;
    }

    //make new empty matrix
    diagonal = newDiagonal;
    matrix = new box[diagonal * diagonal];

    //set all boxes to empty
    int totalBoxes = getTotalBoxes();
    for (int n = 0; n < totalBoxes; n++) {
        (*this)(n) = EMPTY;
    }
}

grid& grid::operator = (const grid& rhs) {
    initialize(rhs.getDiagonal());

    int totalBoxes = getTotalBoxes();
    for (int n = 0; n < totalBoxes; n++) {
        (*this)(n) = rhs(n);
    }

    return *this;
}

box& grid::operator () (const int& x, const int& y) const {
    assert(x >= 0 && x < diagonal && y >= 0 && y < diagonal);

    return (*this)(diagonal * x + y);
}

box& grid::operator () (const int& n) const {
    assert(n >= 0 && n < diagonal * diagonal);
    assert(matrix != nullptr);

    return *(matrix + n);
}

const int& grid::getDiagonal() const {
    return diagonal;
}

int grid::getTotalBoxes() const {
    return diagonal * diagonal;
}

void grid::printMatrix() const {
    cout << endl;
    for (int y = 0; y < diagonal; y++) {
        for (int x = 0; x < diagonal; x++) {
            cout << boxToString((*this)(x, y)) << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
