/**
 *  Demonstrates including the math header
 */

#include <iostream>                                                 //Needed for std
#include <cmath>                                                    //Needed for sqrt, pow, round, ceil, and floor

using namespace std;                                                //No need to prefix cout or endl with "std::"

/**
 * Main Function.
 */
int main() {
    int num1 = 145;
    double num2 = sqrt(num1);                                       //Gets the square root of num1
    cout << "num2 = " << num2 << "\n" << endl;

    int num3 = 4;
    int num4 = pow(num3, 2);                                        //Raises num3 to the second power
    cout << "num4 = " << num4 << "\n" << endl;

    double num5 = 56.59;
    double rounded = round(num5);                                   //Rounds num5 up or down
    double roundedUp = ceil(num5);                                  //Rounds num5 up
    double roundedDown = floor(num5);                               //Rounds num5 down
    cout << "rounded = " << rounded << endl;
    cout << "roundedUp = " << roundedUp << endl;
    cout << "roundedDown = " << roundedDown << endl;

    return 0;                                                       //End of main function
}