#pragma once

// тип транспорта
class Type{
protected:
    int NumOfPeopleToUse;        // Нужное кол-во челове для использования
    bool AdditionalConstruction; // Дополнительная конструкция

public:
    // Конструктор
    Type(int numOfPeopleToUse, bool additionalConstruction);
    // Конструктор копирования
    Type(Type &type);
    // деструктор
    ~Type();

    // get методы
    int getNumOfPeopleToUse();
    bool getAdditionalConstruction();

    // set методы
    void setNumOfPeopleToUse();
    void setAdditionalConstruction();

    virtual bool tryTransfer();
};

// грузовой транспорт
class Cargo:Type{
private:
    double LoadCapacity; // Грузоподъемность

public:
    // Конструктор
    Cargo(int numOfPeopleToUse, bool additionalConstruction, double loadCapacity):Type(numOfPeopleToUse, additionalConstruction){
        LoadCapacity = loadCapacity;
    }
    // Конструктор копирования
    Cargo(Cargo &cargo):Type(cargo.NumOfPeopleToUse, cargo.AdditionalConstruction){
        LoadCapacity = cargo.LoadCapacity;
    }
    // деструктор
    ~Cargo(){}

    // get метод
    double getLoadCapacity();
    // set метод
    void setLoadCapacity(double newLoadCapacity);

    // можно ли перевезти данное кол-во груза
    bool tryTransfer(double weight);
};

// пассажирский транспорт
class Passenger:Type{
private:
    int Seats; // Пассажирские места

public:
    // Конструктор
    Passenger(int numOfPeopleToUse, bool additionalConstruction, int seats):Type(numOfPeopleToUse, additionalConstruction){
        Seats = seats;
    }
    // Конструктор копирования
    Passenger(Passenger &passenger):Type(passenger.NumOfPeopleToUse, passenger.AdditionalConstruction){
        Seats = passenger.Seats;
    }
    // деструктор
    ~Passenger(){}
    // get метод
    double getSeats();
    // set метод
    void setSeats(int newSeats);

    // можно ли перевезти данное кол-во человек
    bool tryTransfer(int numOfPassengers);
};
