#include "../Transport.h"
#include <iostream>

class Plane:Transport{
private:
    int WingsNumber;    // Кол-во крыльев
    bool IsScrewPlane;  // Это винтовой самолет или нет
public:
    // Конструктор
    Plane(string model, double enginePower, double maxSpeed,
        double weight, double cost, int maxNumOfUses, 
        int wingsNumber, bool isScrewPlane):
        Transport(model, enginePower, maxSpeed, weight, cost, maxNumOfUses){
        if (WingsNumber > 0 && WingsNumber % 2 == 0) {
            WingsNumber = wingsNumber;
            IsScrewPlane = isScrewPlane;
        }
        else {
            cout << "Error: WingsNumber must be > 0 and % 2 == 0" << endl;
        }
    };
    // Конструктор копирования
    Plane(Plane &plane):Transport(plane.Model, plane.EnginePower, plane.MaxSpeed,
                            plane.Weight, plane.Cost, plane.getMaxNumOfUses()){
        if (WingsNumber > 0 && WingsNumber % 2 == 0) {
            WingsNumber = plane.WingsNumber;
            IsScrewPlane = plane.IsScrewPlane;
        }
        else {
            cout << "Error: WingsNumber must be > 0 and % 2 == 0" << endl;
        }
    }

    Plane(){ setStatusErr(); }

    // Деструктор
    ~Plane();

    // get методы

    int getWingsNumber();
    bool getIsScrewPlane();

    // set методы

    void setWingsNumber(int newWingsNumber);
    void setIsScrewPlane(bool newIsScrewPlane);

    // Plane методы

    bool checkScrew();

    // перезаписанные методы Transport

    // Вывести все
    void printall();

    // Сравнить два транспорта
    bool compareTransport(Plane* otherPlane);

    // Может ли транспорт поехать/полететь (быть использованым)
    bool tryGo();

    // Можно ли перевезти данное кол-во груза
    bool tryTransferCargo(double weightCargo);

    // Можно ли перевезти данное кол-во людей
    bool tryTransferPeople(int numberOfPassenger);
};
