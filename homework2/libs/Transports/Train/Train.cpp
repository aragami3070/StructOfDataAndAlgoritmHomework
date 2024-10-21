#include <iostream>
#include "Train.h"

// get методы

int Train::getWagonsNumber(){
    if (getStatus() == Ok) {
        return WagonsNumber;
    }
    else {
        cout << "Create Error" << endl;
        return -1;
    }
}

bool Train::getIsSteamTrain(){
    if (getStatus() == Ok) {
        return IsSteamTrain;
    }
    else {
        cout << "Create Error" << endl;
        return false; 
    }
}

// set методы

void Train::setWagonsNumber(int newWagonsNumber){
    if (getStatus() == Ok) {
        if (newWagonsNumber >= 0) {
            WagonsNumber = newWagonsNumber;
        }
        else {
            cout << "Error: WagonsNumber can't be < 0" << endl;
        }
    }
    else {
        cout << "Create Error" << endl;
    }
}

void Train::setIsSteamTrain(bool newIsSteamTrain){
    if (getStatus() == Ok) {
        IsSteamTrain = newIsSteamTrain;
    }
    else {
        cout << "Create Error" << endl;
    }
}

// Train методы

void Train::printall(){
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
        cout << "Кол-во вагонов = " << WagonsNumber << endl 
            << "Паровоз = " << IsSteamTrain << endl;
    }
    else {
        cout << "Create Error" << endl;
    }
}

bool Train::compareTransport(Train* otherTrain){
    if (getStatus() == Ok && otherTrain->getStatus() == Ok) {
        return (
            Model == otherTrain->Model && IsCargo == otherTrain->IsCargo && 
            IsPassenger == otherTrain->IsPassenger && EnginePower == otherTrain->EnginePower && 
            MaxSpeed == otherTrain->MaxSpeed && Weight == otherTrain->Weight &&
            Cost == otherTrain->Cost && getMaxNumOfUses() == otherTrain->getMaxNumOfUses() &&
            getNumberOfUses() == otherTrain->getNumberOfUses() && WagonsNumber == otherTrain->WagonsNumber &&
            IsSteamTrain == otherTrain->IsSteamTrain
        );
    }
    else {
        cout << "Create Error" << endl;
        return false;
    }
}

// Может ли транспорт поехать/полететь (быть использованым)
bool Train::tryGo(){
    if (getStatus() == Ok) {
        if (getNumberOfUses() <= getMaxNumOfUses()){
            if (WagonsNumber >= 0) {
                return true;
            }
            else {
                cout << "Error: WagonsNumber can't be < 0" << endl;
                return false;
            }
        }
        else {
            cout << "Error: This train need maintenance" << endl;
            return false;
        }
    }
    else {
        cout << "Create Error" << endl;
        return false;
    }
}

// Можно ли перевезти данное кол-во груза
bool Train::tryTransferCargo(double weightCargo){
    if (getStatus() == Ok){
        if (IsCargo != nullptr) {
            return IsCargo->tryTransfer(weightCargo);
        }
        else {
            cout << "Error: This train isn't cargo" << endl;
            return false;
        }
    }
    else {
        cout << "Create Error" << endl;
        return false;
    }
}

// Можно ли перевезти данное кол-во людей
bool Train::tryTransferPeople(int numberOfPassenger){
    if (getStatus() == Ok){
        if (IsPassenger != nullptr) {
            return IsPassenger->tryTransfer(numberOfPassenger);
        }
        else {
            cout << "Error: This train isn't passenger" << endl;
            return false;
        }
    }
    else {
        cout << "Create Error" << endl;
        return false;
    }
}
