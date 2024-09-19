#pragma once

#include <string>
#include "../Date/Date.h"

// описание класса товара
class Product{
private:
    std::string Name;       // название товара
    std::string Article;    // артикул
    std::string Flavor;     // вкус = "сладкий"/"соленый"/"горький"/"безвкусный"/и тд
    std::string Color;      // цвет
    std::string Packaging;  // упаковка = "коробка"/"пакет"/и тд
    Date DateOfManufacture; // дата изготовления
    Date ValidUntil;        // годен до (если годен до = 0.0.0, то будем считать, что срока годности нет)
    bool Edible;            // съедобный = да/нет
    int Price;              // цена

    //пару методов для удобства работы с другими методами
    Date getDateOfManufacture();
    Date getValidUntil();
public:
    // конструктор
    Product(std::string name, std::string article, std::string flavor,
            std::string color, std::string packaging, Date dateOfManufacture,
            Date validUntil, bool edible, int price);

    // гетторы
    std::string getName();
    std::string getArticle();
    std::string getFlavor();
    std::string getColor();
    std::string getPackaging();
    std::string getDateOfManufactureStr();
    std::string getValidUntilStr();

        // сетторы
};
