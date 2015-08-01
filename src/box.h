#ifndef BOX_H
#define BOX_H

#include <string>

namespace box {
    enum boxValue {
        EMPTY,
        RED,
        BLUE
    };

    inline std::string boxToString(const boxValue& box_) {
        switch (box_) {
            case EMPTY: return "empty";
            case RED:   return "red";
            case BLUE:  return "blue";
        }
        return "ERROR";
    }
}
#endif //BOX_H
