#include "../Transport.h"

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
        WingsNumber = wingsNumber;
        IsScrewPlane = isScrewPlane;
    };
    // Конструктор копирования
    Plane(Plane &plane):Transport(plane.Model, plane.EnginePower, plane.MaxSpeed,
                            plane.Weight, plane.Cost, plane.getMaxNumOfUses()){
        WingsNumber = plane.WingsNumber;
        IsScrewPlane = plane.IsScrewPlane;
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
