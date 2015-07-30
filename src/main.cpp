#include <iostream>
#include <string>

#include <box.h>
#include <grid.h>
#include <solver.h>

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    grid grid1(6);
    solver solver_;

    grid1(0,4) = BLUE;
    grid1(3,4) = BLUE;
    grid1(1,4) = BLUE;
    grid1(4,4) = BLUE;

    grid1.printMatrix();

    if(solver_.isValid(grid1)){
        cout << "the game is valid!" << endl;
    } else {
        cout << "the game is invalid" << endl;
    }

    return 0;
}
