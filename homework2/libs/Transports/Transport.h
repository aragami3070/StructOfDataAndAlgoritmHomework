#pragma once
#include <string>

using namespace std;

// Статус работоспособности транспорта
enum StatusTransport{
    Ok, Err
};

// Тип транспорта
enum TransportType{
    Car, Plane, Train
};

// класс для транспорта
class Transport{
private:
    TransportType Type;     // Тип транспорта
    double EnginePower;     // Мощность двигателя
    double MaxSpeed;        // Максимальная скорость
    double Weight;          // Вес
    double Seats;           // Пассажирские места
    double Cost;            // цена
    int NumberOfUses;       // Кол-во использований
    int MaxNumOfUses;       // Максимальное кол-во использований перед обязательным техобслуживанием
    StatusTransport Status; // Готов ли транспорт к использованию

public:
    // Конструктор
    Transport(TransportType type, double enginePower,
              double maxSpeed, double weight,
              double seats, double cost,
              int numberOfUses, int MaxNumOfUses);

    // Конструктор копирования
    Transport(Transport &transport);
    
    // Деструктор
    ~Transport();

    // get методы

    string getType();
    double getEnginePower();
    double getMaxSpeed();
    double getWeight();
    double getSeats();
    double getCost();
    int getNumberOfUses();
    int getMaxNumOfUses();

    // set методы

    string setType(string newType);
    double setEnginePower(double newEnginePower);
    double setMaxSpeed(double newMaxSpeed);
    double setWeight(double newWeight);
    double setSeats(double newSeats);
    double setCost(double newCost);
    int setNumberOfUses(int newNumberOfUses);
    int setMaxNumOfUses(int newMaxNumOfUses);

    // Методы транспорта
};

