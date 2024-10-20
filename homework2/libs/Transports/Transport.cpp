#include "Transport.h"
#include "Type/Type.h"

#include <iostream>
#include <string>


// Конструктор
Transport::Transport(string model, double enginePower, double maxSpeed,
                     double weight, double cost, int maxNumOfUses){
    if (enginePower > 0) {
        if (maxSpeed > 0) {
            if (weight > 0) {
                if (cost > 0) {
                    if (maxNumOfUses > 0) {
                        Model = model;
                        IsCargo = nullptr;
                        IsPassenger = nullptr;
                        EnginePower = enginePower;
                        MaxSpeed = maxSpeed;
                        Weight = weight;
                        Cost = cost;
                        NumberOfUses = 0;
                        MaxNumOfUses = maxNumOfUses;
                        Status = Ok;
                    }
                    else {
                        cout << "Error: Max number of use can't be <= 0" << endl;
                    }
                }
                else {
                    cout << "Error: Cost can't be <= 0" << endl;
                }
            }
            else {
                cout << "Error: Weight can't be <= 0" << endl;
            }
        }
        else {
            cout << "Error: Max Speed can't be <= 0" << endl;
        }
    }
    else {
        cout << "Error: Engine Power can't be <= 0" << endl;
    }
}
// Конструктор копирования
Transport::Transport(Transport &transport){
    if (transport.Status == Ok){
        if (transport.EnginePower > 0) {
            if (transport.MaxSpeed > 0) {
                if (transport.Weight > 0) {
                    if (transport.Cost > 0) {
                        if (transport.MaxNumOfUses > 0) {
                            Model = transport.Model;
                            IsCargo = nullptr;
                            IsPassenger = nullptr;
                            EnginePower = transport.EnginePower;
                            MaxSpeed = transport.MaxSpeed;
                            Weight = transport.Weight;
                            Cost = transport.Cost;
                            NumberOfUses = 0;
                            MaxNumOfUses = transport.MaxNumOfUses;
                            Status = Ok;
                        }
                        else {
                            cout << "Error: Max number of use can't be <= 0" << endl;
                        }
                    }
                    else {
                        cout << "Error: Cost can't be <= 0" << endl;
                    }
                }
                else {
                    cout << "Error: Weight can't be <= 0" << endl;
                }
            }
            else {
                cout << "Error: Max Speed can't be <= 0" << endl;
            }
        }
        else {
            cout << "Error: Engine Power can't be <= 0" << endl;
        }
    }
    else {
        cout << "Create Error" << endl;
    }
}

// Деструктор
Transport::~Transport(){

}

// get методы

string Transport::getModel(){
    if (Status == Ok) {
        return Model;
    }
    else {
        cout << "Create Error" << endl;
        return "";
    }
}
Cargo* Transport::getIsCargo(){
    if (Status == Ok) {
        if (IsCargo != nullptr){
            return IsCargo;
        }
        else {
            cout << "Is not Cargo" << endl;
            return nullptr;
        }
    }
    else {
        cout << "Create Error" << endl;
        return nullptr;
    }
}
Passenger* Transport::getIsPassenger(){
    if (Status == Ok) {
        if (IsPassenger != nullptr){
            return IsPassenger;
        }
        else {
            cout << "Is not Passenger" << endl;
            return nullptr;
        }
    }
    else {
        cout << "Create Error" << endl;
        return nullptr;
    }
}
double Transport::getEnginePower(){
    if (Status == Ok) {
        return EnginePower;
    }
    else {
        cout << "Create Error" << endl;
        return -1;
    }
}
double Transport::getMaxSpeed(){
    if (Status == Ok) {
        return MaxSpeed;
    }
    else {
        cout << "Create Error" << endl;
        return -1;
    }
}
double Transport::getWeight(){
    if (Status == Ok) {
        return Weight;
    }
    else {
        cout << "Create Error" << endl;
        return -1;
    }
}
double Transport::getCost(){
    if (Status == Ok) {
        return Cost;
    }
    else {
        cout << "Create Error" << endl;
        return -1;
    }
}
int Transport::getNumberOfUses(){
    if (Status == Ok) {
        return NumberOfUses;
    }
    else {
        cout << "Create Error" << endl;
        return -1;
    }
}
int Transport::getMaxNumOfUses(){
    if (Status == Ok) {
        return MaxNumOfUses;
    }
    else {
        cout << "Create Error" << endl;
        return -1;
    }
}

void Transport::printall(){
    if (Status == Ok) {
        cout << "Модель = " << Model << endl 
            << "Мощность мотора = " << EnginePower << endl
            << "Максимальная скорость = "<< MaxSpeed << endl
            << "Вес = "<< Weight << endl
            << "Цена = "<< Cost << endl
            << "Кол-во использований = "<< NumberOfUses << endl
            << "Максимальное кол-во использований (до техобслуживания) = " << MaxNumOfUses << endl;
        if (IsCargo != nullptr){
            IsCargo->printType();
        }
        if (IsPassenger != nullptr){
            IsPassenger->printType();
        }
    }
}

// set методы

void Transport::setModel(string newModel){
    if (Status == Ok) {
        Model = newModel;
    }
    else {
        cout << "Create Error" << endl;
    }
}
void Transport::setCargo(Cargo* newCargo){
    if (Status == Ok) {
        IsPassenger = nullptr;
        IsCargo = newCargo;
        cout << "Now is only cargo transport" << endl;
    }
    else {
        cout << "Create Error" << endl;
    }
}
void Transport::setPassenger(Passenger* newPassenger){
    if (Status == Ok) {
        IsPassenger = newPassenger;
        IsCargo = nullptr;
        cout << "Now is only passenger transport" << endl;
    }
    else {
        cout << "Create Error" << endl;
    }
}
void Transport::setEnginePower(double newEnginePower){
    if (Status == Ok) {
        if (newEnginePower > 0){
            EnginePower = newEnginePower;
        }
        else {
            cout << "Error: EnginePower can't be <= 0" << endl;
        }
    }
    else {
        cout << "Create Error" << endl;
    }
}
void Transport::setMaxSpeed(double newMaxSpeed){
    if (Status == Ok) {
        if (newMaxSpeed > 0) {
            MaxSpeed = newMaxSpeed;
        }
        else {
            cout << "Error: MaxSpeed can't be <= 0" << endl;
        }
    }
    else {
        cout << "Create Error" << endl;
    }
}
void Transport::setWeight(double newWeight){
    if (Status == Ok) {
        if (newWeight > 0) {
            Weight = newWeight;
        }
        else {
            cout << "Error: MaxSpeed can't be <= 0" << endl;
        }
    }
    else {
        cout << "Create Error" << endl;
    }
}
void Transport::setCost(double newCost){
    if (Status == Ok) {
        if (newCost > 0) {
            Cost = newCost;
        }
        else {
            cout << "Error: Cost can't be <= 0" << endl;
        }
    }
    else {
        cout << "Create Error" << endl;
    }
}
void Transport::setMaxNumOfUses(int newMaxNumOfUses){
    if (Status == Ok) {
        if (newMaxNumOfUses > 0){
            MaxNumOfUses = newMaxNumOfUses;
        }
        else {
            cout << "Error: Max number of use can't be <= 0" << endl;
        }
    }
    else {
        cout << "Create Error" << endl;
    }
}

// Сравнить два транспорта
bool Transport::compareTransport(Transport* otherTransport){
    if (Status == Ok && otherTransport->Status == Ok) {
        return (
            Model == otherTransport->Model && IsCargo == otherTransport->IsCargo && 
            IsPassenger == otherTransport->IsPassenger && EnginePower == otherTransport->EnginePower && 
            MaxSpeed == otherTransport->MaxSpeed && Weight == otherTransport->Weight &&
            Cost == otherTransport->Cost && MaxNumOfUses == otherTransport->MaxNumOfUses &&
            NumberOfUses == otherTransport->NumberOfUses
        );
    }
    else {
        cout << "Create Error" << endl;
        return false;
    }
}

// Методы транспорта

// Может ли транспорт поехать/полететь (быть использованым)
bool Transport::tryGo(){
    if (Status == Ok) {
        if (NumberOfUses <= MaxNumOfUses){
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
bool Transport::tryTransferCargo(double weightCargo){
    if (Status == Ok){
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
bool Transport::tryTransferPeople(int numberOfPassenger){
    if (Status == Ok){
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
