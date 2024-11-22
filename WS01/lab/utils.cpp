#include "utils.h"
#include <iostream>

namespace seneca {

    // Flushes the keyboard
    void flushkeys() {
        while (std::cin.get() != '\n');
    }

    // Returns true if user enters 'y' or 'Y'
    bool yes() {
        char ch = std::cin.get();
        flushkeys();
        return ch == 'y' || ch == 'Y';
    }

    // Copies src Cstring to des and converts all characters to lowercase
    void toLowerCase(char* des, const char* src) {
        int i = 0;
        while (src[i]) {
            des[i] = src[i];
            if (des[i] >= 'A' && des[i] <= 'Z') {
                des[i] += ('a' - 'A');
            }
            i++;
        }
        des[i] = '\0';
    }

}
