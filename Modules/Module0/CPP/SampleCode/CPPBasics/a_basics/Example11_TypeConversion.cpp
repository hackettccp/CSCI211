/**
 *  Demonstrates type conversion
 */

#include <iostream>                                                 //Needed for std

using namespace std;                                                //No need to prefix cout, endl, string, stoi, stod or to_string with "std::"

/**
 * Main Function.
 */
int main() {
    double num1 = 10.55;
    int num2 = (int)num1;                                           //Typecasts num1 (a double) to an int
    cout << "Typecast result: " << num2 << endl;                    //Prints the result

    string numStr1 = "45";
    string numStr2 = "35.23";

    int num3 = stoi(numStr1);                                       //Converts numStr1 to an int. stoi = "string to int". Must use std:: if namespace was not included.
    double num4 = stod(numStr2);                                    //Converts numStr2 to a double. stod = "string to double". Must use std:: if namespace was not included.
    double num5 = num3 + num4;
    cout << "num5 = " << num5 << endl;                              //Prints the sum of num3 and num4

    string output1 = "The value of num3 is " + to_string(num3);     //Numeric types must be converted to string before concatenation. Must use std::to_string if namespace was not included.
    cout << output1 << endl;

    cout << "The value of num4 is " + to_string(num4) << endl;

    return 0;                                                       //End of main function
}
