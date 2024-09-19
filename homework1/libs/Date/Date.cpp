#include "Date.h"
#include <string>

// конструктор
Date::Date(int day,
           int month,
           int year){
    Day = day;
    Month = month;
    Year = year;
}

// гетторы
int Date::getDay(){
    return Day;
}

int Date::getMonth(){
    return Month;
}

int Date::getYear(){
    return Year;
}

std::string Date::getData(){
    return (std::to_string(Day) + "." + std::to_string(Month) + "." + std::to_string(Year));
}

// сетторы
void Date::setDay(int input){
    Day = input;
}

void Date::setMonth(int input){
    Month = input;
}

void Date::setYear(int input){
    Year = input;
}
