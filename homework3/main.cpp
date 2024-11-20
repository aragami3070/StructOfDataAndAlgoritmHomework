#include "libs/Products/Product.h"
#include "libs/Errors/Errors.h"
#include "libs/Date/Date.h"
#include "libs/List/List.h"
#include <iostream>
#include <fstream>

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
    
    // обработка исключения типа Date
    cout << "Test type excpetion(Date):" << endl;
    try{
        if (create.getYear() % 2 == 0) throw create;
    }
    catch(Date){
        cerr << "Exception on Date: year is even" << endl;
    }

    cout << "====================================================================" << endl;
    cout << "Test my exception(DateBroken):" << endl;

    Date create2 = Date(0, 0, 0);

    // обработка исключений из класса Errors
    try {
    
        Product cookie2 = Product("Печеньки шоколадные", "Любятово", "LU-COK-CC",
                                "Сладкие", "Темно-коричневые", "Коробка",
                                create2, valUnt, true, 120, 0.4);
    } 
    catch (SomeError& test) {
        test.print();
    }

    cout << "====================================================================" << endl;
    cout << "Test my exception(NotZero):" << endl;

    try {
    
        Product cookie2 = Product("Печеньки шоколадные", "Любятово", "LU-COK-CC",
                                "Сладкие", "Темно-коричневые", "Коробка",
                                create, valUnt, true, 0, 0.4);
    } 
    catch (SomeError& test) {
        test.print();
    }

    cout << "====================================================================" << endl;
    cout << "Test my exception(try del elem from empty List):" << endl;

    Node* someLink = someProducts.findProduct(cookie1);
    someProducts.del_elem(someLink);
    try {
        someProducts.del_elem(someLink);
    }
    catch (SomeError& test) {
        test.print();
    }

    cout << "====================================================================" << endl;
    cout << "Test my exception(try print empty List):" << endl;

    try {
        someProducts.printProduct();
    }
    catch (SomeError& test) {
        test.print();
    }

    cout << "====================================================================" << endl;
    cout << "Test my exception(try input from file):" << endl;

    try{
        string inputStr;
        ifstream input;
        // существующее название файла
        // string fileName = "../test.txt"; // использую ../ перед названием файла тк запускаю из папки build
        // не существующее название файла
        string fileName = "../testException.txt"; // использую ../ перед названием файла тк запускаю из папки build
        input.open(fileName);
        if (input.is_open()) {
            input >> inputStr;
            cout << inputStr << endl;
        }
        else {
            throw NotFindFile(fileName);
        }
        input.close();
    }
    catch (SomeError& test) {
        test.print();
    }

}
