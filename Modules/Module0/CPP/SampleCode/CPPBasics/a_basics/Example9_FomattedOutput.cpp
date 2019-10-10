/**
 *  Demonstrates formatting output
 * 
 */

#include <iostream>
#include <iomanip>                  //Only needed in this program to use the setw and setprecision functions
using namespace std;

/**
 * Main Function.
 */
int main() {
    string value1 = "ABCD";
    int value2 = 1234;

    cout << setw(10) << value1 << setw(6) << value2 << setw(15) << "XYZ\n" <<endl;      //Prints the output with various amounts of spacing before each value (The spacing includes the characters/numbers in the value!)

    double value3 = 19.6;
    double value4 = 18.3;
    double result = value3 / value4;

    int defaultPrecision = cout.precision();                                            //Get the default precision (we need to remember it if we want to change it back)

    cout << "19.6 / 18.3 = " << result << "\n" << endl;                                 //Prints the result
    cout << "19.6 / 18.3 = " << setprecision(3) << result << endl;                      //Sets the precision of the output to 3 (total) digits
    cout << "19.6 / 18.3 = " << result << endl;                                         //Precision is still set
    cout << "19.6 / 18.3 = " << setprecision(4) << result << "\n" << endl;              //Sets the precision of the output to 4 (total) digits

    cout << "19.6 / 18.3 = " << setprecision(defaultPrecision) << result << endl;       //Prints the result (precision was reset)

    return 0;
}