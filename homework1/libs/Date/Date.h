#pragma once

#include <string>

//класс для даты
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

        void setDay(int newDay);
        void setMonth(int newMonth);
        void setYear(int newYear);
};
