#ifndef BOX_H
#define BOX_H

#include <string>
#include <iostream>

namespace box {
    enum boxValue {
        EMPTY,
        RED,
        BLUE
    };

    inline std::string boxToString(const boxValue& boxValue_, const bool& shortEmpty = true) {
        switch (boxValue_) {
            case EMPTY: if (shortEmpty) {
                            return "-";
                        } else {
                            return "empty";
                        }
            case RED:   return "red";
            case BLUE:  return "blue";
        }
        return "ERROR";
    }

    inline std::ostream& operator<< (std::ostream& output, const boxValue& boxValue_) {
        output << boxToString(boxValue_, true);
        return output;
    }
}
#endif //BOX_H
