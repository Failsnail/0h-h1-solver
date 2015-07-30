#ifndef BOX_H
#define BOX_H

#include <string>

using namespace std;

enum box {
    empty,
    red,
    blue
};

inline string boxToString(const box& box_) {
    switch (box_) {
        case empty: return "empty";
        case red:   return "red";
        case blue:  return "blue";
    }
    return "ERROR";
}

#endif //BOX_H
