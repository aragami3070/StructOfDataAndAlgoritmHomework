#include <iostream>
#include "Car.h"

// get методы
string getBrand();
int getDorsNumber();

// set методы
void setBrand(string newBrand);
void setDorsNumber(int newDorsNumber);

// Car методы

// Да, да, да шутки про чек
bool Car::IsBMW(){
    if (getStatus()) {
        if (Brand == "BMW"){
            cout << "CHEEEEEEEEEEEEEEECK" << endl;
            setStatusErr();
            return true;
        }
        else {
            cout << "Mmmm nice choice" << endl;
            return false;
        }
    }
    else {
        cout << "Create Error" << endl;
        return false;
    }
    
}

void Car::printall(){
    if (getStatus() == Ok) {
        cout << "Модель = " << Model << endl 
            << "Мощность мотора = " << EnginePower << endl
            << "Максимальная скорость = "<< MaxSpeed << endl
            << "Вес = "<< Weight << endl
            << "Цена = "<< Cost << endl
            << "Кол-во использований = "<< getNumberOfUses() << endl
            << "Максимальное кол-во использований (до техобслуживания) = " << getMaxNumOfUses() << endl;
        if (IsCargo != nullptr){
            IsCargo->printType();
        }
        if (IsPassenger != nullptr){
            IsPassenger->printType();
        }
        cout << "Марка = " << Brand << endl 
            << "Кол-во дверей = " << DorsNumber << endl;
    }
    else {
        cout << "Create Error" << endl;
    }
}

bool Car::compareTransport(Car* otherCar){
    if (getStatus() == Ok && otherCar->getStatus() == Ok) {
        return (
            Model == otherCar->Model && IsCargo == otherCar->IsCargo && 
            IsPassenger == otherCar->IsPassenger && EnginePower == otherCar->EnginePower && 
            MaxSpeed == otherCar->MaxSpeed && Weight == otherCar->Weight &&
            Cost == otherCar->Cost && getMaxNumOfUses() == otherCar->getMaxNumOfUses() &&
            getNumberOfUses() == otherCar->getNumberOfUses() && Brand == otherCar->Brand &&
            DorsNumber == otherCar->DorsNumber
        );
    }
    else {
        cout << "Create Error" << endl;
        return false;
    }
}

// Может ли транспорт поехать/полететь (быть использованым)
bool Car::tryGo(){
    if (getStatus() == Ok) {
        if (getNumberOfUses() <= getMaxNumOfUses()){
            return true;
        }
        else {
            cout << "Error: This transport need maintenance" << endl;
            return false;
        }
    }
    else {
        cout << "Create Error" << endl;
        return false;
    }
}

// Можно ли перевезти данное кол-во груза
bool Car::tryTransferCargo(double weightCargo){
    if (getStatus() == Ok){
        if (IsCargo != nullptr) {
            return IsCargo->tryTransfer(weightCargo);
        }
        else {
            cout << "Error: This transport isn't cargo" << endl;
            return false;
        }
    }
    else {
        cout << "Create Error" << endl;
        return false;
    }
}

// Можно ли перевезти данное кол-во людей
bool Car::tryTransferPeople(int numberOfPassenger){
    if (getStatus() == Ok){
        if (IsPassenger != nullptr) {
            return IsPassenger->tryTransfer(numberOfPassenger);
        }
        else {
            cout << "Error: This transport isn't passenger" << endl;
            return false;
        }
    }
    else {
        cout << "Create Error" << endl;
        return false;
    }
}
