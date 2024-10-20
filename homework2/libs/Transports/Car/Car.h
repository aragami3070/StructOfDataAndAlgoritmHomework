#include "../Transport.h"
#include "../Type/Type.h"
#include <string>

class Car:Transport{
private:
    string Brand;   // Марка машины
    int DorsNumber; // Кол-во дверей в машине
public:
    // Конструктор
    Car(string model, double enginePower, double maxSpeed,
        double weight, double cost, int maxNumOfUses, 
        string brand, int dorsNumber):
        Transport(model, enginePower, maxSpeed, weight, cost, maxNumOfUses){
        Brand = brand;
        DorsNumber = dorsNumber;
    };
    // Конструктор копирования
    Car(Car &car):Transport(car.Model, car.EnginePower, car.MaxSpeed,
                            car.Weight, car.Cost, car.getMaxNumOfUses()){
        Brand = car.Brand;
        DorsNumber = car.DorsNumber;
    }

    Car(){ setStatusErr(); }

    // Деструктор
    ~Car();

    // get методы
    string getBrand();
    int getDorsNumber();

    // set методы
    void setBrand(string newBrand);
    void setDorsNumber(int newDorsNumber);

    // Car методы
    bool IsBMW();

    // перезаписанные методы Transport

    // Вывести все
    void printall();

    // Сравнить два транспорта
    bool compareTransport(Car* otherCar);

    // Может ли транспорт поехать/полететь (быть использованым)
    bool tryGo();

    // Можно ли перевезти данное кол-во груза
    bool tryTransferCargo(double weightCargo);

    // Можно ли перевезти данное кол-во людей
    bool tryTransferPeople(int numberOfPassenger);
};

