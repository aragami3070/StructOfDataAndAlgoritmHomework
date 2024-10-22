#include "libs/List/List.h"
#include "libs/Transports/Type/Type.h"
#include "libs/Transports/Car/Car.h"
#include "libs/Transports/Plane/Plane.h"
#include "libs/Transports/Train/Train.h"
#include <iostream>
int main(){
    //  Создание разного транспората и вывод их атрибутов
    cout << "=======================================================================" << endl;
    Car supra = Car("Some Car model", 500, 250, 10, 4000000, 10000, "Toyta", 2);
    cout << "Supra:" << endl;
    supra.printall();
    cout << "=======================================================================" << endl;
    cout << endl;
    Plane samolet = Plane("Some Plane model", 50000, 500, 70, 50000000, 5000, 4, false);
    cout << "Samolet:" << endl;
    samolet.printall();
    cout << "=======================================================================" << endl;
    cout << endl;
    Train paravos = Train("Some Train model", 5000, 150, 50, 20000000, 15000, 5, true);
    cout << "Paravos:" << endl;
    paravos.printall();
    cout << "=======================================================================" << endl;

    // добавляю транспорт в список
    List transportsNote = List();
    transportsNote.push_back(&supra);
    transportsNote.push_back(&samolet);
    transportsNote.push_back(&paravos);

    Transport* testFindNode = transportsNote.findNode(&samolet);

    Cargo cargoForCar = Cargo(3, false, 1000);
    supra.setCargo(&cargoForCar);
    supra.printall();
    cout << "Supra (Cargo):" << endl;
    supra.printall();
    cout << "=======================================================================" << endl;

    Passenger passengerForPlane = Passenger(4, true, 100);
    samolet.setPassenger(&passengerForPlane);
    samolet.printall();
    cout << "Samolet (Passenger):" << endl;
    samolet.printall();
    cout << "=======================================================================" << endl;

    cout << "Test findNode method (find samolet):" << endl;
    testFindNode->printall();
    cout << "=======================================================================" << endl;
    transportsNote.delList();
}
