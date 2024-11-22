#include <iostream>
#include "input.h"
using namespace std;
namespace seneca {
    int getInt() {
        int num = 0;
        bool done = false;
        do {
            // extract an integer from the console and put it in num
            cin >> num;
            // if this action fails (the integer is unreadable)
            if (cin.fail()) {
                cout << "Bad integer entry, please try again:\n> ";
                // clear the failure status to activate cin again
                cin.clear();
            }
            else {
                done = true;
            }
            // flush the keyboard buffer up to 1000 characters or '\n', whichever comes first
            cin.ignore(1000, '\n');
        } while (!done);
        return num;
    }

    int getInt(int minVal, int maxVal) {
        int num = 0;
        bool done = false;
        do {
            // extract an integer from the console and put it in num
            cin >> num;
            // if this action fails (the integer is unreadable)
            if (cin.fail()) {
                cout << "Bad integer entry, please try again:\n> ";
                // clear the failure status to activate cin again
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (num<minVal || num>maxVal) {
                cout << "Invalid value, [" << minVal << "<ENTRY<" << maxVal << "]\n> ";
                cin.ignore(1000, '\n');
            }
            else {
                done = true;
            }
            // flush the keyboard buffer up to 1000 characters or '\n', whichever comes first
        } while (!done);
        return num;
    }

    bool getInt(int& number, int minVal, int maxVal) {
        int num = 0;
        bool done = false;

        while (!done) {
            cin >> num;
            if (cin.fail()) {
                cout << "Bad integer entry, please try again:\n> ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (num < minVal || num > maxVal) {
                cout << "Only enter values between " << minVal << " and " << maxVal << ", inclusive:\n> ";
                cin.ignore(1000, '\n');
            }
            else {
                number = num;
                done = true;
            }
        }
        return done;
    }
}

