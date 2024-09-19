#pragma once

#include <string>

//класс для даты
class Date{
private:
    int Day;
    int Month;
    int Year;
public:
    Date(int Day = 0, int Month = 0, int Year = 0);
    ~Date();

    std::string getData();
    int getDay();
    int getMonth();
    int getYear();

    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);
};
