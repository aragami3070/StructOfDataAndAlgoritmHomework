#include "libs/Products/Product.h"
#include "libs/Errors/Errors.h"
#include "libs/Date/Date.h"
#include "libs/List/List.h"
#include <iostream>

using namespace std;

int main(){
    // создал даты
    Date create = Date(25, 8, 2024);
    Date valUnt = Date(25, 8, 2025);

    // создал печеньки
    Product cookie1 = Product("Печеньки шоколадные", "Любятово", "LU-COK-CC",
                              "Сладкие", "Темно-коричневые", "Коробка",
                              create, valUnt, true, 120, 0.4);

    List someProducts = List();
    
    someProducts.push_back(cookie1);
    

    cout << "Test type excpetion:" << endl;
    try{
        if (create.getYear() % 2 == 0) throw create;
    }
    catch(Date){
        cerr << "Exception on Date: year is even" << endl;
    }

    cout << "Test my exception:" << endl;

    Date create2 = Date(0, 0, 0);

    try {
    
        Product cookie2 = Product("Печеньки шоколадные", "Любятово", "LU-COK-CC",
                                "Сладкие", "Темно-коричневые", "Коробка",
                                create2, valUnt, true, 120, 0.4);
    } 
    catch (SomeError& test) {
        test.print();
    }
    try {
    
        Product cookie2 = Product("Печеньки шоколадные", "Любятово", "LU-COK-CC",
                                "Сладкие", "Темно-коричневые", "Коробка",
                                create, valUnt, true, 0, 0.4);
    } 
    catch (SomeError& test) {
        test.print();
    }

    cout << "Test my exception:" << endl;

    try {
        someProducts.del_elem();
    }
    catch (SomeError& test) {
    
    }
}
