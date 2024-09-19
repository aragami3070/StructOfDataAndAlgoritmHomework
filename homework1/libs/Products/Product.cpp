#include "Product.h"
#include <string>

// Private методы
Date Product::getDateOfManufacture(){
    return DateOfManufacture;
}

Date Product::getValidUntil(){
    return ValidUntil;
}

//Конструкстор
Product::Product(std::string name,
                 std::string article,
                 std::string flavor,
                 std::string color,
                 std::string packaging,
                 Date dateOfManufacture,
                 Date validUntil,
                 bool edible,
                 int price){
    Name = name;
    Article = article;
    Flavor = flavor;
    Color = color;
    Packaging = packaging;
    DateOfManufacture = dateOfManufacture;
    ValidUntil = validUntil;
    Edible = edible;
    Price = price;
}

//гетторы
std::string Product::getName(){
    return Name;
}

std::string Product::getArticle(){
    return Article;
}

std::string Product::getFlavor(){
    return Flavor;
}

std::string Product::getColor(){
    return Color;
}

std::string Product::getPackaging(){
    return Packaging;
}

std::string Product::getDateOfManufactureStr(){
    return DateOfManufacture.getData();
}

std::string Product::getValidUntilStr(){
    return ValidUntil.getData();
}


