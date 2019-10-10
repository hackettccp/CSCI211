#include <iostream>

using namespace std;

/**
 * Bicycle Class 
 */
class Bicycle {

    /**
     * Private Fields/Methods
     */
    private:
        int gear;
        int speed;
        string color;

    /**
     * Public Fields/Methods 
     */
    public:
        //Default Constructor
        Bicycle() {
            gear = 1;
            speed = 0;
            color = "Black";
        }

        //Three-argument constructor
        Bicycle(int g, int s, string c) {
            gear = g;
            speed = s;
            color = c;
        }

        //Setter method for the gear field
        void setGear(int g) {
            if(g < 1) {
                gear = 1;
            }
            else if(g > 10) {
                gear = 10;
            }
            else {
                gear = g;
            }
        }

        //Setter method for the speed field
        void setSpeed(int s) {
            speed = s;
        }

        //Setter method for the color field
        void setColor(string c) {
            color = c;
        }

        //Getter method for the gear field
        int getGear() {
            return gear;
        }

        //Getter method for the speed field
        int getSpeed() {
            return speed;
        }

        //Getter method for the color field
        string getColor() {
            return color;
        }

};
