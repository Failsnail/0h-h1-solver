#include <iostream>
#include <string>

#include <box.h>
#include <grid.h>

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    grid grid1(6);

    grid1(2,5) = red;
    grid1(4,4) = blue;

    grid grid2(grid1);

    grid1 = grid2;

    cout << boxToString(grid1(2,5)) << " || " << boxToString(grid1(4,4))<< endl;

    grid1.printMatrix();

    return 0;
}
