#include "libs/Products/Product.h"
#include "libs/List/List.h"
#include "libs/Date/Date.h"
#include <iostream>

int main(){
    // создал список
    List<Product> shop = List<Product>();

    // создал даты
    Date create = Date(25, 8, 2024);
    Date valUnt = Date(25, 8, 2025);

    // создал печеньки
    Product cookie1 = Product("Печеньки шоколадные", "Любятово", "LU-COK-CC", "Сладкие", "Темно-коричневые", "Коробка", create, valUnt, true, 120, 0.4);

    // попытка впихнуть печеньки в пустой список
    std::cout << "Try add cookie1 in shop (List):" << std::endl;
    if (!shop.findProduct(cookie1)) {
        shop.push_back(cookie1);
        std::cout << "Add successfull" << std::endl;
    }
    else {
        std::cout << "Error: Product with this Article already on the list" << std::endl;
    }
    std::cout << std::endl;

    
    std::cout << "Cookie1:" << std::endl;
    std::cout << "Type: "<< cookie1.getType() << std::endl;
    std::cout << "Name: "<< cookie1.getName() << std::endl;
    std::cout << "Article: "<< cookie1.getArticle() << std::endl;
    std::cout << "Flavor: "<< cookie1.getFlavor() << std::endl;
    std::cout << "Color: "<< cookie1.getColor() << std::endl;
    std::cout << "Packaging: "<< cookie1.getPackaging() << std::endl;
    std::cout << "DateOfManufacture: "<< cookie1.getDateOfManufactureStr() << std::endl;
    std::cout << "ValidUntil: "<< cookie1.getValidUntilStr() << std::endl;
    std::cout << "Edible: "<< cookie1.getEdible() << std::endl;
    std::cout << "Price: "<< cookie1.getPrice() << std::endl;
    std::cout << "Weight: "<< cookie1.getWeight() << std::endl;
    std::cout << "Status: "<< cookie1.getStatus() << std::endl;
    std::cout << "StatusInit: "<< cookie1.getStatusInit() << std::endl;
    std::cout << std::endl;

    // создал печеньки2 = печеньки1
    Product cookie2 = Product("Печеньки шоколадные", "Любятово", "LU-COK-CC", "Сладкие", "Темно-коричневые", "Коробка", create, valUnt, true, 120, 0.4);

    std::cout << "Try add cookie2 == cookie1 in shop (list)" << std::endl;
    // попытка впихнуть печеньки2 в список, где лежат такие же печеньки1
    if (!shop.findProduct(cookie2)) {
        shop.push_back(cookie2);
        std::cout << "Add successfull" << std::endl;
    }
    else {
        std::cout << "Error: Product with this Article already on the shop (list)" << std::endl;
    }
    std::cout << std::endl;


    std::cout << "Change Cookie2:" << std::endl;
    create.setDay(12);
    valUnt.setDay(14);
    cookie2.setType("Печеньки ванильные с шоколадом");
    cookie2.setArticle("LU-COK-VC");
    cookie2.setFlavor("Сладкие");
    cookie2.setColor("Бежевые");
    cookie2.setPackaging("Пакет");
    cookie2.setDateOfManufacture(create);
    cookie2.setValidUntil(valUnt);
    cookie2.setPrice(140);
    cookie2.setWeight(0.35);
    std::cout << std::endl;

    // узнать срок годности
    std::cout << "Cookie2 ExpirationDate:" << std::endl;
    std::cout << cookie2.getExpirationDate() << std::endl;
    std::cout << std::endl;

    // попытка впихнуть изменненые печеньки2 в список
    std::cout << "Try add changed cookie2 in shop (list)" << std::endl;
    if (!shop.findProduct(cookie2)) {
        shop.push_back(cookie2);
        std::cout << "Add successfull" << std::endl;
    }
    else {
        std::cout << "Error: Product with this Article already on the list" << std::endl;
    }
    std::cout << std::endl;


    shop.printProduct();

    std::cout << std::endl;
    shop.delList();
}
