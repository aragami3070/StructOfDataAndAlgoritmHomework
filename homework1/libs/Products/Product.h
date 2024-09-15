#pragma once

#include <string>
#include "../Date/Date.h"

// описание класса товара
class Product{
    private:
        std::string Name; // название товара
        std::string Article; // артикул
        std::string Flavor; // вкус = "сладкий"/"соленый"/"горький"/"безвкусный"/и тд
        std::string Color; // цвет
        std::string Packaging; // упаковка = "коробка"/"пакет"/и тд
        Date DateOfManufacture; // дата изготовления
        Date ValidUntil; // годен до
        bool Edible; // съедобный = да/нет
        int Price; // цена
    public:
        std::string getName();
        std::string getArticle();
        std::string getFlavor();
        std::string getColor();
        std::string getPackaging();
        std::string getDateOfManufacture();
        std::string getValidUntil();
};
