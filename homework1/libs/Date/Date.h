#pragma once

#include <string>

class Date{
    private:
        int Day;
        int Month;
        int Year;
    public:
        Date(int Day, int Month, int Year);
        ~Date();

        std::string getData();
        int getDay();
        int getMonth();
        int getYear();

        int setDay(int newDay);
        int setMonth(int newMonth);
        int setYear(int newYear);
};
