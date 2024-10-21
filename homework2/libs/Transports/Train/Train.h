#include "../Transport.h"

class Train:Transport{
private:
    int WagonsNumber;   // Кол-во вагонов
    bool IsSteamTrain;  // Это паровоз
public:
    // Конструктор
    Train(string model, double enginePower, double maxSpeed,
        double weight, double cost, int maxNumOfUses, 
        int wagonsNumber, bool isSteamTrain):
        Transport(model, enginePower, maxSpeed, weight, cost, maxNumOfUses){
        WagonsNumber = wagonsNumber;
        IsSteamTrain = isSteamTrain;
    };

    // Конструктор копирования
    Train(Train &train):Transport(train.Model, train.EnginePower, train.MaxSpeed,
                            train.Weight, train.Cost, train.getMaxNumOfUses()){
        WagonsNumber = train.WagonsNumber;
        IsSteamTrain = train.IsSteamTrain;
    }

    Train(){ setStatusErr(); }

    // Деструктор
    ~Train();

    // get методы

    int getWagonsNumber();
    bool getIsSteamTrain();

    // set методы

    void setWagonsNumber(int newWagonsNumber);
    void setIsSteamTrain(bool newIsSteamTrain);

    // Train методы

    // перезаписанные методы Transport

    // Вывести все
    void printall();

    // Сравнить два транспорта
    bool compareTransport(Train* otherTrain);

    // Может ли транспорт поехать/полететь (быть использованым)
    bool tryGo();

    // Можно ли перевезти данное кол-во груза
    bool tryTransferCargo(double weightCargo);

    // Можно ли перевезти данное кол-во людей
    bool tryTransferPeople(int numberOfPassenger);
};
