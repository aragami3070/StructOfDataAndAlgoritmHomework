#include <iostream>
#include "Plane.h"

// get методы

int Plane::getWingsNumber(){
    if (getStatus() == Ok) {
        return WingsNumber;
    }
    else {
        cout << "Create Error" << endl;
        return -1;
    }
}

bool Plane::getIsScrewPlane(){
    if (getStatus() == Ok) {
        return IsScrewPlane;
    }
    else {
        cout << "Create Error" << endl;
        return false; 
    }
}

// set методы

void Plane::setWingsNumber(int newWingsNumber){
    if (getStatus() == Ok) {
        if (newWingsNumber > 0 && newWingsNumber % 2 == 0) {
            WingsNumber = newWingsNumber;
        }
        else {
            cout << "Error: WingsNumber must be > 0 and % 2 == 0" << endl;
        }
    }
    else {
        cout << "Create Error" << endl;
    }
}

void Plane::setIsScrewPlane(bool newIsScrewPlane){
    if (getStatus() == Ok) {
        IsScrewPlane = newIsScrewPlane;
    }
    else {
        cout << "Create Error" << endl;
    }
}

// Plane методы

bool Plane::checkScrew(){
    if (getStatus() == Ok) {
        if (IsScrewPlane) {
            cout << "This plane is screw" << endl;
            return true;
        }
        else {
            cout << "This plane is jet" << endl;
            return false;
        }
    }
    else {
        cout << "Create Error" << endl;
        return false;
    }
}

void Plane::printall(){
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
        cout << "Кол-во крыльев = " << WingsNumber << endl 
            << "Самолет винтовой = " << IsScrewPlane << endl;
    }
    else {
        cout << "Create Error" << endl;
    }
}

bool Plane::compareTransport(Plane* otherPlane){
    if (getStatus() == Ok && otherPlane->getStatus() == Ok) {
        return (
            Model == otherPlane->Model && IsCargo == otherPlane->IsCargo && 
            IsPassenger == otherPlane->IsPassenger && EnginePower == otherPlane->EnginePower && 
            MaxSpeed == otherPlane->MaxSpeed && Weight == otherPlane->Weight &&
            Cost == otherPlane->Cost && getMaxNumOfUses() == otherPlane->getMaxNumOfUses() &&
            getNumberOfUses() == otherPlane->getNumberOfUses() && WingsNumber == otherPlane->WingsNumber &&
            IsScrewPlane == otherPlane->IsScrewPlane
        );
    }
    else {
        cout << "Create Error" << endl;
        return false;
    }
}

// Может ли транспорт поехать/полететь (быть использованым)
bool Plane::tryGo(){
    if (getStatus() == Ok) {
        if (getNumberOfUses() <= getMaxNumOfUses()){
            if (WingsNumber > 0 && WingsNumber % 2 == 0) {
                return true;
            }
            else {
                cout << "Error: WingsNumber must be > 0 and % 2 == 0" << endl;
                return false;
            }
        }
        else {
            cout << "Error: This plane need maintenance" << endl;
            return false;
        }
    }
    else {
        cout << "Create Error" << endl;
        return false;
    }
}

// Можно ли перевезти данное кол-во груза
bool Plane::tryTransferCargo(double weightCargo){
    if (getStatus() == Ok){
        if (IsCargo != nullptr) {
            return IsCargo->tryTransfer(weightCargo);
        }
        else {
            cout << "Error: This plane isn't cargo" << endl;
            return false;
        }
    }
    else {
        cout << "Create Error" << endl;
        return false;
    }
}

// Можно ли перевезти данное кол-во людей
bool Plane::tryTransferPeople(int numberOfPassenger){
    if (getStatus() == Ok){
        if (IsPassenger != nullptr) {
            return IsPassenger->tryTransfer(numberOfPassenger);
        }
        else {
            cout << "Error: This plane isn't passenger" << endl;
            return false;
        }
    }
    else {
        cout << "Create Error" << endl;
        return false;
    }
}
