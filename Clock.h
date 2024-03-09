#ifndef CLOCK_H
#define CLOCK_H

class Clock {
private:
    int hour;
    int minute;
    int second;
    bool is24HourFormat;
    bool isPM;

public:
    // Default constructor
    Clock();

    // Constructor
    Clock(int, int, int);

    // Switches between 12-hour and 24-hour format based on the value of is24HourFormat
    void toggleFormat();

    // Prints out the current time in the format "HH:MM:SS" or "HH:MM:SS AM/PM"
    void show();

    // Advances the time by one second
    void tick();

};

#endif