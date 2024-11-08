#include "Date.h"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

// private методы

// проверка валидности даты (дня/месяца)
bool Date::checkMonthDay(int day, int month, int year){
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (day < 1 || day>31) {
                return false;
            }
            else {
                return true;
            }
        case 4: case 6: case 9: case 11:
            if (day < 1 || day >30) {
                return false;
            }
            else {
                return true;
            }
        case 2:
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
                if (day < 1 || day>29) {
                    return false;
                }
                else {
                    return true;
                }
            }
            else {
                if (day < 1 || day>28) {
                    return false;
                }
                else {
                    return true;
                }
            }
        default:
            return false;
    }
    return false;
}
//public методы

// конструктор
Date::Date(int day,
           int month,
           int year){
    // если ввели 0.0.0 условно считаем, что даты нет
    if (day == 0 && month == 0 && year == 0) {
        Day = day;
        Month = month;
        Year = year;
    }
    // проверка валидности введеных данных
    else if (checkMonthDay(day, month, year) && year > 0) {
        Day = day;
        Month = month;
        Year = year;
    }
    // проверка не прошла
    else {
        std::cout << "Error[418]: This date not valid" << std::endl;
        system("pause");
    }
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

std::string Date::getDate(){
    return (std::to_string(Day) + "." + std::to_string(Month) + "." + std::to_string(Year));
}

// проверка валидности передаваемых в метод данных
bool Date::checkDate(){
    if (Day == 0 && Month == 0 && Year ==0) {
        return true;
    }
    else if (checkMonthDay(Day, Month , Year) && Year > 0) {
        return true;
    }
    return false;
}

// сетторы

void Date::setDay(int input){
    // задать дату равную 0.0.0 можно только через setDate или инициализацию
    if (input == 0) {
        std::cout << "Error[418]: Set 0 date only setDate method or init" << std::endl;
        system("pause");
    }
    // проверка валидности данной даты
    else if (checkMonthDay(input, Month , Year)) {
        Day = input;
    }
    // проверка не прошла
    else {
        std::cout << "Error[418]: This day not valid" << std::endl;
        system("pause");
    }
}

void Date::setMonth(int input){
    // задать дату равную 0.0.0 можно только через setDate или инициализацию
    if (input == 0) {
        std::cout << "Error[418]: Set 0 date only setDate method or init" << std::endl;
        system("pause");
    }
    // проверка валидности данной даты
    else if (checkMonthDay(Day, input , Year)) {
        Month = input;
    }
    // проверка не прошла
    else {
        std::cout << "Error[418]: This month not valid" << std::endl;
        system("pause");
    }
}

void Date::setYear(int input){
    // задать дату равную 0.0.0 можно только через setDate или инициализацию
    if (input == 0) {
        std::cout << "Error[418]: Set 0 date only setDate method or init" << std::endl;
        system("pause");
    }
    // проверка валидности данной даты
    else if (input > 0) {
        Year = input;
    }
    // проверка не прошла
    else {
        std::cout << "Error[418]: This year not valid" << std::endl;
        system("pause");
    }
}

void Date::setDate(Date input){
    // проверка валидности данной даты
    if (input.checkDate()) {
        Day = input.getDay();
        Month = input.getMonth();
        Year = input.getYear();
    }
    // проверка не прошла
    else {
        std::cout << "Error[418]: This date not valid" << std::endl;
        system("pause");
    }
}

