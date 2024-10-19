
#include "Type.h"
#include <iostream>
using namespace std;
// Type class

// Конструктор
Type::Type(int numOfPeopleToUse, bool additionalConstruction){
    NumOfPeopleToUse = numOfPeopleToUse;
    AdditionalConstruction = additionalConstruction;
}
// Конструктор копирования
Type::Type(Type &type){
    NumOfPeopleToUse = type.NumOfPeopleToUse;
    AdditionalConstruction = type.AdditionalConstruction;
}
// деструктор
Type::~Type(){}

// get методы
int Type::getNumOfPeopleToUse(){
    return NumOfPeopleToUse;
}
bool Type::getAdditionalConstruction(){
    return AdditionalConstruction;
}

// set методы
void Type::setNumOfPeopleToUse(int newNumOfPeopleToUse){
    NumOfPeopleToUse = newNumOfPeopleToUse;
}
void Type::setAdditionalConstruction(bool newAdditionalConstruction){
    AdditionalConstruction = newAdditionalConstruction;
}

bool Type::tryTransfer(){
    return true;
}

void Type::printType(){
    cout << "Нужное кол-во челове для использования = " << NumOfPeopleToUse << endl 
        << "Дополнительная конструкция = " << AdditionalConstruction << endl;
}

// грузовой транспорт

// get метод
double Cargo::getLoadCapacity(){
    return LoadCapacity;
}
// set метод
void Cargo::setLoadCapacity(double newLoadCapacity){
    LoadCapacity = newLoadCapacity;
}

// можно ли перевезти данное кол-во груза
bool Cargo::tryTransfer(double weight){
    if (LoadCapacity >= weight){
        return true;
    }
    return false;
}
void Cargo::printType(){
    cout << "Нужное кол-во челове для использования = " << NumOfPeopleToUse << endl 
        << "Дополнительная конструкция = " << AdditionalConstruction << endl
        << "Грузоподъемность = " << LoadCapacity << endl;
}

// пассажирский транспорт

// get метод
double Passenger::getSeats(){
    return Seats;
}
// set метод
void Passenger::setSeats(int newSeats){
    Seats = newSeats;
}

// можно ли перевезти данное кол-во человек
bool Passenger::tryTransfer(int numOfPassengers){
    if (Seats >= numOfPassengers) {
        return true;
    }
    return false;
}

void Passenger::printType(){
    cout << "Нужное кол-во челове для использования = " << NumOfPeopleToUse << endl 
        << "Дополнительная конструкция = " << AdditionalConstruction << endl
        << "Пассажирские места = " << Seats << endl;
}
