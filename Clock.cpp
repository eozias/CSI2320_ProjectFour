#include "Clock.h"
#include <iostream>
#include <iomanip>

using namespace std;

Clock::Clock() {
    hour = 0;
    minute = 0;
    second = 0;
    is24HourFormat = true;
    isPM = false;
}

Clock::Clock(int h, int m, int s) {
    is24HourFormat = true;
    isPM = false;
    if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
        hour = h;
        minute = m;
        second = s;
    } else {
        hour = 0;
        minute = 0;
        second = 0;
    }
}

void Clock::toggleFormat() {
    if (is24HourFormat == true) {
        // Switch to 12-hour format
        is24HourFormat = false;
        if (hour > 12) {
            hour -= 12;
            isPM = true;
        } else if (hour == 12) {
            isPM = true;
        } else if (hour == 0) {
            hour = 12;
            isPM = false;
        } else {
            isPM = false;
        }
    } else {
        // Switch to 24-hour format
        is24HourFormat = true;
        if (hour == 12 && isPM == false) {
            hour = 0;
        }
        else if (hour == 12 && isPM == true) {
            hour = 12;
        }
        else if (isPM == true) {
            hour += 12;
        }
    }
}

void Clock::tick() {
    second++;
    if (second == 60) {
        second = 0;
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
            }
        }
    }
}

void Clock::show() {
    if (is24HourFormat == true) {
        std::cout << std::setw(2) << std::setfill('0') << hour << ":"
                  << std::setw(2) << std::setfill('0') << minute << ":"
                  << std::setw(2) << std::setfill('0') << second << std::endl;
    } else {
        std::cout << std::setw(2) << std::setfill('0') << hour << ":"
                  << std::setw(2) << std::setfill('0') << minute << ":"
                  << std::setw(2) << std::setfill('0') << second
                  << (isPM ? " PM" : " AM") << std::endl;
    }
}

int main() {
    cout << "Testing Clock class with clock one" << endl;
    Clock one;
    one.show();
    cout << "Using the tick function..." << endl;
    one.tick();
    one.show();
    cout << "Using the toggleFormat function..." << endl;
    one.toggleFormat();
    one.show();
    cout << endl;

    cout << "Testing Clock class with clock two" << endl;
    Clock two(23, 59, 59);
    two.show();
    cout << "Using the tick function..." << endl;
    two.tick();
    two.show();
    cout << "Using the toggleFormat function..." << endl;
    two.toggleFormat();
    two.show();
    cout << endl;

    cout << "Testing Clock class with clock three" << endl;
    Clock three(12, 0, 0);
    three.show();
    cout << "Using the toggleFormat function..." << endl;
    three.toggleFormat();
    three.show();
    cout << endl;

    cout << "Testing Clock class with clock four" << endl;
    Clock four(15, 31, 45);
    four.show();
    cout << "Using the toggleFormat function..." << endl;
    four.toggleFormat();
    four.show();

    return 0;
}