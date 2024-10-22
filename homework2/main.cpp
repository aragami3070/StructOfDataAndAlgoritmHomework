// #include "libs/List/List.h"
// #include "libs/Transports/Type/Type.h"
#include "libs/Transports/Car/Car.h"
#include "libs/Transports/Plane/Plane.h"
#include "libs/Transports/Train/Train.h"
#include <iostream>
int main(){
    Car supra = Car("Some Car model", 500, 250, 10, 4000000, 10000, "Toyta", 2);
    cout << "Supra:" << endl;
    supra.printall();
    cout << endl;
    Plane samolet = Plane("Some Plane model", 50000, 500, 70, 50000000, 5000, 4, false);
    cout << "Samolet:" << endl;
    samolet.printall();
    cout << endl;
    Train paravos = Train("Some Train model", 5000, 150, 50, 20000000, 15000, 5, true);
    cout << "Paravos:" << endl;
    paravos.printall();
}
