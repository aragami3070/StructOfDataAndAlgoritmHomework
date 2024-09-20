#pragma once

#include <string>

// класс для даты
class Date{
private:
    int Day;
    int Month;
    int Year;

    bool checkMonthDay(int day, int month, int year);
public:
    // задать дату равную 0.0.0 можно только через setDate или инициализацию
    Date(int Day = 0, int Month = 0, int Year = 0);
    ~Date();

    // гетторы
    std::string getDate();
    int getDay();
    int getMonth();
    int getYear();

    // проверка на валидность задаваемых дат
    bool checkDate();

    // сетторы
    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);
    void setDate(Date newDate);
    bool operator==(Date someDate){
        return (Day == someDate.getDay() && Month == someDate.getMonth() && Year == someDate.getYear());
    }
};
