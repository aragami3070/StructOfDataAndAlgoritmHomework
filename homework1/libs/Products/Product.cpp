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
Product::Product(std::string type,
                 std::string name,
                 std::string article,
                 std::string flavor,
                 std::string color,
                 std::string packaging,
                 Date dateOfManufacture,
                 Date validUntil,
                 bool edible,
                 int price){
    Type = type;
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
std::string Product::getType(){
    return Type;
}

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
    return DateOfManufacture.getDate();
}

std::string Product::getValidUntilStr(){
    return ValidUntil.getDate();
}

void Product::setType(std::string input){
    Type = input;
}

void Product::setName(std::string input){
    Name = input;
}

void Product::setArticle(std::string input){
    Article = input;
}

void Product::setFlavor(std::string input){
    Flavor = input;
}

void Product::setColor(std::string input){
    Color = input;
}

void Product::setPackaging(std::string input){
    Packaging = input;
}

void Product::setDateOfManufacture(Date input){
    DateOfManufacture.setDate(input);
}

