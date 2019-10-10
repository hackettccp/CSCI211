/**
 *  Demonstrates creating a subroutine/function with parameters
 *  (No difference from Java)
 */

#include <iostream>
using namespace std;

//Prototype (Only data types of parameters are needed)
int calculateArea(int, int);

/**
 * Main Function.
 */
int main() {
    
    int length;
    int width;

    cout << "Enter the length: ";
    cin >> length;

    cout << "Enter the width: ";
    cin >> width;

    int area = calculateArea(length, width);
    cout << "The area is " << area << endl;

    return 0;
}

/**
 * Function that accepts two int arguments.
 * Multiplies the parameters and returns the result.
 */
int calculateArea(int len, int wid) {
    int a = len * wid;
    return a;
}