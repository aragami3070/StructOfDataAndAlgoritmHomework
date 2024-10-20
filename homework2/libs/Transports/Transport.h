#pragma once
#include <string>
#include "Type/Type.h"

using namespace std;

// Статус работоспособности транспорта
enum StatusTransport{
    Ok, Err
};

// класс для транспорта
class Transport{
private:
    int NumberOfUses;           // Кол-во использований
    int MaxNumOfUses;           // Максимальное кол-во использований перед обязательным техобслуживанием
    StatusTransport Status;     // Правильно ли создан класс

protected:
    Cargo* IsCargo;              // Является ли этот транспорт грузовым
    Passenger* IsPassenger;      // Является ли этот транспорт пассажирским
    double EnginePower;         // Мощность двигателя
    double MaxSpeed;            // Максимальная скорость
    double Weight;              // Вес
    double Cost;                // Цена

public:
    // Конструктор
    Transport(double enginePower,double maxSpeed, double weight,
              double cost, int maxNumOfUses);

    // Конструктор копирования
    Transport(Transport &transport);

    Transport(){ Status = Err; }
    
    // Деструктор
    ~Transport();

    // get методы

    Cargo* getIsCargo();
    Passenger* getIsPassenger();
    double getEnginePower();
    double getMaxSpeed();
    double getWeight();
    double getCost();
    int getNumberOfUses();
    int getMaxNumOfUses();
    StatusTransport getStatus();
    void printall();

    // set методы

    void setCargo(Cargo* newCargo);
    void setPassenger(Passenger* newPassenger);
    void setEnginePower(double newEnginePower);
    void setMaxSpeed(double newMaxSpeed);
    void setWeight(double newWeight);
    void setCost(double newCost);
    void setMaxNumOfUses(int newMaxNumOfUses);

    // Сравнить два транспорта
    virtual bool compareTransport(Transport* otherTransport);

    // Методы транспорта

    // Может ли транспорт поехать/полететь (быть использованым)
    virtual bool tryGo();

    // Можно ли перевезти данное кол-во груза
    virtual bool tryTransferCargo(double weightCargo);

    // Можно ли перевезти данное кол-во людей
    virtual bool tryTransferPeople(int numberOfPassenger);
};

