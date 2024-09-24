#include "libs/Products/Product.h"
#include "libs/List/List.h"
#include "libs/Date/Date.h"

int main(){
    List<Product> shop = List<Product>();
    Date create = Date(25, 8, 2024);
    Date valUnt = Date(25, 8, 2025);
    Product cookie = Product("Печеньки шоколадные", "Любятово", "LU-COK-CC", "Сладкие", "Темно-коричневые", "Коробка", create, valUnt, true, 120, 0.4);
    shop.push_back(cookie);
    shop.printProduct();
    shop.delList();
}
