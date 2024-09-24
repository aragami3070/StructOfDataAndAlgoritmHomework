#include "Product.h"
#include <cstdlib>
#include <iostream>
#include <string>

// Private методы

// проверка на производственный брак
bool Product::manufacturingDefects(){
    if (StatusInit == OK) {
        int randResult = rand() % 101;
        if (randResult == 100) {
            return false;
        }
        else {
            return true;
        }
    }
    std::cout << "Error: StatusInit == Err" << std::endl;
    return false;
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
            StatusInit = OK;
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
    if (StatusInit == OK){
        return Type;
    }
    std::cout << "Error: StatusInit == Err" << std::endl;
    return "";
}

std::string Product::getName(){
    if (StatusInit == OK){
        return Name;
    }
    std::cout << "Error: StatusInit == Err" << std::endl;
    return "";
}

std::string Product::getArticle(){
    if (StatusInit == OK){
        return Article;
    }
    std::cout << "Error: StatusInit == Err" << std::endl;
    return "";
}

std::string Product::getFlavor(){
    if (StatusInit == OK){
        return Flavor;
    }
    std::cout << "Error: StatusInit == Err" << std::endl;
    return "";
}

std::string Product::getColor(){
    if (StatusInit == OK){
        return Color;
    }
    std::cout << "Error: StatusInit == Err" << std::endl;
    return "";
}

std::string Product::getPackaging(){
    if (StatusInit == OK){
        return Packaging;
    }
    std::cout << "Error: StatusInit == Err" << std::endl;
    return "";
}

std::string Product::getDateOfManufactureStr(){
    if (StatusInit == OK){
        return DateOfManufacture.getDate();
    }
    std::cout << "Error: StatusInit == Err" << std::endl;
    return "";
}

std::string Product::getValidUntilStr(){
    if (StatusInit == OK){
        return ValidUntil.getDate();
    }
    std::cout << "Error: StatusInit == Err" << std::endl;
    return "";
}

Date Product::getDateOfManufacture(){
    if (StatusInit == OK){
        return DateOfManufacture;
    }
    std::cout << "Error: StatusInit == Err" << std::endl;
    return Date(1, 1, 999999999);
}

Date Product::getValidUntil(){
    if (StatusInit == OK){
        return ValidUntil;
    }
    std::cout << "Error: StatusInit == Err" << std::endl;
    return Date(1, 1, 999999999);
}

bool Product::getEdible(){
    if (StatusInit == OK){
        return Edible;
    }
    std::cout << "Error: StatusInit == Err" << std::endl;
    return false;
}
int Product::getPrice(){
    if (StatusInit == OK){
        return Price;
    }
    std::cout << "Error: StatusInit == Err" << std::endl;
    return -10100;
}
double Product::getWeight(){
    if (StatusInit == OK){
        return Weight;
    }
    std::cout << "Error: StatusInit == Err" << std::endl;
    return -10100.0;
}

// сетторы
void Product::setType(std::string input){
    if (StatusInit == OK){
        Type = input;
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}

void Product::setName(std::string input){
    if (StatusInit == OK){
        Name = input;
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}

void Product::setArticle(std::string input){
    if (StatusInit == OK){
        Article = input;
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}

void Product::setFlavor(std::string input){
    if (StatusInit == OK){
        Flavor = input;
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}

void Product::setColor(std::string input){
    if (StatusInit == OK){
        Color = input;
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}

void Product::setPackaging(std::string input){
    if (StatusInit == OK){
        Packaging = input;
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}

void Product::setDateOfManufacture(Date input){
    if (StatusInit == OK){
        // дата создания не может быть 0.0.0
        if (input.getDay() == 0 || input.getMonth() == 0 || input.getYear() == 0) {
            std::cout << "Error[418]: Date of manufacture can't be 0.0.0" << std::endl;
        }
        else {
            DateOfManufacture.setDate(input);
        }
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}

void Product::setValidUntil(Date input){
    if (StatusInit == OK){
        ValidUntil.setDate(input);
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}

void Product::setEdible(bool input){
    if (StatusInit == OK){
        Edible = input;
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}

void Product::setPrice(int input){
    if (StatusInit == OK){
        if (input > 0) {
            Price = input;
        }
        else {
            std::cout << "Error[418]: Price can't be <= 0" << std::endl;
        }
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}

void Product::setWeight(double input){
    if (StatusInit == OK){
        if (input > 0){
            Weight = input;
        }
        else {
            std::cout << "Error[418]: Weight can't be <= 0" << std::endl;
        }
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}


// доп методы

// получение срока годности
std::string Product::getExpirationDate(){
    if (StatusInit == OK){
        int day = DateOfManufacture.getDay() - ValidUntil.getDay();
        int month = DateOfManufacture.getMonth() - ValidUntil.getMonth();
        int year = DateOfManufacture.getYear() - ValidUntil.getYear();
        Date expirationDate = Date(day, month, year);
        return expirationDate.getDate();
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
        return "";
    }
}

// попробовать съесть (если съедобное)
void Product::tryEat(){
    if (StatusInit == OK){
        if (Edible && Status) {
            std::cout << "You ate it" << std::endl;
        }
        else {
            std::cout << "You can't eat it" << std::endl;
        }
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}

// попробовать купить, если хватит денег
void Product::tryBuy(int money){
    if (StatusInit == OK){
        if (money >= Price && ((Status && Edible) || (Status && !Edible))){
            std::cout << "You bought it" << std::endl;
        }
        else{
            std::cout << "You can't buy it" << std::endl;
        }
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}


// попробовать открыть (распаковать)
void Product::tryOpen(){
    if (StatusInit == OK){
        if (Packaging == "None") {
            std::cout << "This product didn't have packaging" << std::endl;
        }
        else {
            std::cout << "You opened it" << std::endl;
        }
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}

// попробовать приготовить
void Product::tryCook(){
    if (StatusInit == OK){
        if (Edible && Status) {
            std::cout << "You cooked it" << std::endl;
        }
        else {
            std::cout << "You can't cook it" << std::endl;
        }
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}

// попробовать поднять
void Product::tryUp(int numberOfPeople){
    if (StatusInit == OK){
        if ((Weight >= 40 && numberOfPeople == 1) || (Weight >= 65 && numberOfPeople == 2) ||
            (Weight >= 80 && numberOfPeople == 3) || (Weight >= 92 && numberOfPeople == 4) ||
            (Weight >= 95 && numberOfPeople == 5) || (Weight >= 100 && numberOfPeople >= 6)) {
            std::cout << "You can't up it" << std::endl;
        }
        else {
            std::cout << "You up it" << std::endl;
        }
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
    }
}


bool Product::compareArticle(Product otherProduct){
    if (StatusInit == OK){
        return (Type == otherProduct.getType() && Name == otherProduct.getName() && Article == otherProduct.getArticle());
    }
    else {
        std::cout << "Error: StatusInit == Err" << std::endl;
        return false;
    }
}

