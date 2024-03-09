#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <iomanip>

class Clock {
private:
    int hour;
    int minute;
    int second;
    bool is24HourFormat;
    bool isPM;

public:
    // Default constructor
    Clock() {
        hour = 0;
        minute = 0;
        second = 0;
        is24HourFormat = true;
        isPM = false;
    }

    // Constructor
    Clock(int h, int m, int s) {
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

    // Switches between 12-hour and 24-hour format based on the value of is24HourFormat
    void toggleFormat() {
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

// Prints out the current time in the format "HH:MM:SS" or "HH:MM:SS AM/PM"
void show() {
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

// Advances the time by one second
void tick() {
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

};

#endif