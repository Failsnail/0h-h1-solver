#include <iostream>
#include <string>

#include "box.h"
#include "grid.h"
#include "utilities.h"
#include "solver.h"
#include "recursivesolver.h"
#include "naiverecursivesolver.h"

using namespace box;
using namespace std;

void getInput(const int& diagonal, int& x, int& y, boxValue& currentValue, bool& isRunning) {
        do {
            cout << "x(-1 to stop): ";
            cin >> x;
            cout << endl;
            if (x == -1) {
                isRunning = false;
                return; //asking for other input is not necessary if the program was asked to stop
            }
        } while (x < 0 || x >= diagonal);
        do {
            cout << "y: ";
            cin >> y;
            cout << endl;
        } while (y < 0 || y >= diagonal);
        int colour;
        do {
            cout << "colour(1 = RED, 2 = BLUE, 3 = EMPTY): ";
            cin >> colour;
            cout << endl;
        } while (colour < 1 || colour > 3);

        switch(colour) {
            case 1: currentValue = RED;
                    break;
            case 2: currentValue = BLUE;
                    break;
            default: currentValue = EMPTY;
                    break;
        }
}

int main() {

    bool isRunning = true, succesfullSolve;
    int x, y;
    boxValue currentValue;

    int diagonal;

    int startSolving;

    cout << "Enter the diagonal: " << endl;
    cin >> diagonal;
    cout << endl;

    grid grid1(diagonal);

    solver* mySolver = new recursiveSolver();

    grid1.printMatrix();

    while(isRunning) {
        getInput(diagonal, x, y, currentValue, isRunning);

        if(!isRunning) {
            break;
        }

        grid1(x, y) = currentValue;

        grid1.printMatrix();

        if (utilities::isValid(grid1)) {
            cout << "the grid is Valid" << endl;
        } else {
            cout << "the grid isn't valid" << endl;
        }

        do {
            cout << "start solving? (0 = false, 1 = true) ";
            cin >> startSolving;
            cout << endl;
        } while (startSolving != 0 && startSolving != 1);

        if (startSolving) {
            cout << "solving..." << endl;
            succesfullSolve = mySolver->solve(&grid1);
            if (succesfullSolve) {
                cout << "a solution was found!" << endl;
                grid1.printMatrix();
            } else {
                cout << "a solution could not be found!" << endl;
            }
            startSolving = false;
        }
    }

    delete mySolver;

    return 0;
}
