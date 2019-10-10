/**
 *  Demonstrates the basic use of arrays in C++
 *  (Same basic usage as Java; declaration is a little different)
 *  Like Java, all values in the array must be the correct data type.
 */

#include <iostream>
using namespace std;

/**
 * Main Function.
 */
int main() {
    
    int numbers[] = {4, 8, 15, 16, 23, 42};             //An array of 6 ints. [] follows the variable name instead of data type.
    double temperatures[3];                             //An (empty) array of 3 doubles.

    temperatures[0] = 45.7;                             //Assignment is the same syntax as Java
    temperatures[1] = 76.4;
    temperatures[2] = 81.5;

    int number = numbers[0];                            //Retrieval is the same syntax as Java
    
    cout << "The element at index 0 of the numbers array is " << number << endl;
    cout << "The element at index 3 of the numbers array is " << numbers[3] << endl;


    return 0;
}