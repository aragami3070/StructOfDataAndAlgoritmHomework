#pragma once

#include <iostream>
#include <string>
#include "../Date/Date.h"

//специальный тип данных, чтобы узнать - правильно ли создан объект класса или нет
enum StatusEr{
    OK, Err
};

// описание класса товара
class Product{
private:
    std::string Type;       // тип товара
    std::string Name;       // название товара
    std::string Article;    // артикул
    std::string Flavor;     // вкус = "сладкий"/"соленый"/"горький"/"безвкусный"/и тд
    std::string Color;      // цвет
    std::string Packaging;  // упаковка = "коробка"/"пакет"/и тд
    Date DateOfManufacture; // дата изготовления
    Date ValidUntil;        // годен до (если годен до = 0.0.0, то будем считать, что срока годности нет)
    bool Edible;            // съедобный = да/нет
    int Price;              // цена
    double Weight;          // вес
    bool Status;            // если == 1, то товар в надлежащем состоянии, иначе испорчен (бракован)
    StatusEr StatusInit;    // правильно ли создан товар

    bool manufacturingDefects();

public:
    // конструктор
    Product(std::string type, std::string name, std::string article,
            std::string flavor,std::string color, std::string packaging,
            Date dateOfManufacture, Date validUntil, bool edible, int price, double Weigt);

    Product(){ StatusInit = Err; }

    ~Product(){}

    // гетторы
    std::string getType();
    std::string getName();
    std::string getArticle();
    std::string getFlavor();
    std::string getColor();
    std::string getPackaging();
    std::string getDateOfManufactureStr();
    std::string getValidUntilStr();
    bool getEdible();
    int getPrice();
    double getWeight();
    bool getStatus();
    std::string getStatusInit();

    void printAll();

    // пару методов для удобства работы с другими методами
    Date getDateOfManufacture();
    Date getValidUntil();

    // сетторы
    void setType(std::string newType);
    void setName(std::string newName);
    void setArticle(std::string newArticle);
    void setFlavor(std::string newFlavor);
    void setColor(std::string newColor);
    void setPackaging(std::string newPackaging);
    void setDateOfManufacture(Date newDateOfManufacture);
    void setValidUntil(Date input);
    void setEdible(bool input);
    void setPrice(int input);
    void setWeight(double input);

    // перегрузки операторов

    void operator=(Product someProduct){
        Type = someProduct.getType();
        Name = someProduct.getName(); 
        Article = someProduct.getArticle();
        Flavor = someProduct.getFlavor(); 
        Color = someProduct.getColor(); Packaging = someProduct.getPackaging();
        DateOfManufacture = someProduct.getDateOfManufacture(); 
        ValidUntil = someProduct.getValidUntil();
        Edible = someProduct.getEdible();
        Price = someProduct.getPrice();
        Weight = someProduct.getWeight();
        Status = someProduct.getStatus();
        StatusInit = OK;
    }

    bool operator==(Product someProduct){
        return (Type == someProduct.getType() && Name == someProduct.getName() && Article == someProduct.getArticle() &&
                Flavor == someProduct.getFlavor() && Color == someProduct.getColor() && Packaging == someProduct.getPackaging() &&
                DateOfManufacture == someProduct.getDateOfManufacture() && ValidUntil == someProduct.getValidUntil() && 
                Edible == someProduct.getEdible() && Price == someProduct.getPrice() && Weight == someProduct.getWeight() && Status == someProduct.getStatus());
    }

    // доп методы

    // получение срока годности
    std::string getExpirationDate();

    // съесть, купить, открыть, приготовить, поднять, сравнение артикулов и параметров влияющих на артикул

    void tryEat();

    void tryBuy(int money);

    void tryOpen();

    void tryCook();

    void tryUp(int numberOfPeople);

    bool compareArticle(Product otherProduct);

    bool canCookTogether(Product otherProduct);

};
