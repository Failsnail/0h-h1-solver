#ifndef BOX_H
#define BOX_H

#include <string>

using namespace std;

enum box {
    EMPTY,
    RED,
    BLUE
};

inline string boxToString(const box& box_) {
    switch (box_) {
        case EMPTY: return "empty";
        case RED:   return "red";
        case BLUE:  return "blue";
    }
    return "ERROR";
}

#endif //BOX_H
