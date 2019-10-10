#include <iostream>
#include "Bicycle.h"

using namespace std;

int main() {

    Bicycle bike1;                                  //Calls default constructor
    Bicycle bike2(4, 15, "Blue");                   //Calls constructor with three arguments (int, int, string)
    Bicycle bike3;                                  //Calls default constructor

    bike3.setSpeed(13);
    bike3.setGear(8);
    bike3.setColor("Red");

    Bicycle bikes[4];                               //Array of Bicycle objects
    bikes[0] = bike1;
    bikes[1] = bike2;
    bikes[2] = bike3;
    bikes[3] = Bicycle(6, 9, "Green");

    for(int i = 0; i < 4; i++) {
        cout << "Bike " << i << " Speed: " << bikes[i].getSpeed() << ", Current Gear: " << bikes[i].getGear() << ", Color: " << bikes[i].getColor() << endl;
    }


}