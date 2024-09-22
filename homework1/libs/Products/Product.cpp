#include "Product.h"
#include <cstdlib>
#include <iostream>
#include <string>

// Private методы

// проверка на производственный брак
bool Product::manufacturingDefects(){
    int randResult = rand() % 101;
    if (randResult == 100) {
        return false;
    }
    else {
        return true;
    }
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
                 int price,
                 double weight){
    if (price > 0 && weight > 0) {
        if (dateOfManufacture.getDay() != 0 || dateOfManufacture.getMonth() != 0 || dateOfManufacture.getYear() != 0) {
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
            Weight = weight;
            Status = manufacturingDefects();
        }
        else {
            std::cout << "Error[418]: Date of manufacture can't be 0.0.0" << std::endl;
            system("pause");
        }
    }
    else {
        std::cout << "Error[418]: Price and weight can't be <=0" << std::endl;
        system("pause");
    }
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

Date Product::getDateOfManufacture(){
    return DateOfManufacture;
}

Date Product::getValidUntil(){
    return ValidUntil;
}

bool Product::getEdible(){
    return Edible;
}
int Product::getPrice(){
    return Price;
}
double Product::getWeight(){
    return Weight;
}

// сетторы
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
    // дата создания не может быть 0.0.0
    if (input.getDay() == 0 || input.getMonth() == 0 || input.getYear() == 0) {
        std::cout << "Error[418]: Date of manufacture can't be 0.0.0" << std::endl;
    }
    else {
        DateOfManufacture.setDate(input);
    }
}

void Product::setValidUntil(Date input){
    ValidUntil.setDate(input);
}

void Product::setEdible(bool input){
    Edible = input;
}

void Product::setPrice(int input){
    if (input > 0) {
        Price = input;
    }
    else {
        std::cout << "Error[418]: Price can't be <= 0" << std::endl;
    }
}

void Product::setWeight(double input){
    if (input > 0){
        Weight = input;
    }
    else {
        std::cout << "Error[418]: Weight can't be <= 0" << std::endl;
    }
}


// доп методы

// получение срока годности
std::string Product::getExpirationDate(){
    int day = DateOfManufacture.getDay() - ValidUntil.getDay();
    int month = DateOfManufacture.getMonth() - ValidUntil.getMonth();
    int year = DateOfManufacture.getYear() - ValidUntil.getYear();
    Date expirationDate = Date(day, month, year);
    return expirationDate.getDate();
}

// попробовать съесть (если съедобное)
void Product::tryEat(){
    if (Edible && Status) {
        std::cout << "You ate it" << std::endl;
    }
    else {
        std::cout << "You can't eat it" << std::endl;
    }
}

// попробовать купить, если хватит денег
void Product::tryBuy(int money){
    if (money >= Price && ((Status && Edible) || (Status && !Edible))){
        std::cout << "You bought it" << std::endl;
    }
    else{
        std::cout << "You can't buy it" << std::endl;
    }
}


// попробовать открыть (распаковать)
void Product::tryOpen(){
    if (Packaging == "None") {
        std::cout << "This product didn't have packaging" << std::endl;
    }
    else {
        std::cout << "You opened it" << std::endl;
    }
}

// попробовать приготовить
void Product::tryCook(){
    if (Edible && Status) {
        std::cout << "You cooked it" << std::endl;
    }
    else {
        std::cout << "You can't cook it" << std::endl;
    }
}

// попробовать поднять
void Product::tryUp(int numberOfPeople){
    if ((Weight >= 40 && numberOfPeople == 1) || (Weight >= 65 && numberOfPeople == 2) ||
        (Weight >= 80 && numberOfPeople == 3) || (Weight >= 92 && numberOfPeople == 4) ||
        (Weight >= 95 && numberOfPeople == 5) || (Weight >= 100 && numberOfPeople >= 6)) {
        std::cout << "You can't up it" << std::endl;
    }
    else {
        std::cout << "You up it" << std::endl;
    }
}
