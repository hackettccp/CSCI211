/**
 *  Demonstrates making the primitive data types unsigned in C++
 * 
 */

#include <iostream>
using namespace std;

/**
 * Main Function.
 */
int main() {
    unsigned int number = 17;                                   //Creates a 4-byte (32-bit) UNSIGNED integer data type. (0 through ~4 billion)
    unsigned int number2 = -100;                                //Can't represent negatives. The bits will be stored as a signed number, but interpreted as an unsigned number.
    
    cout << "The value of number is: " << number << endl;
    cout << "The value of number2 is: " << number2 << endl;     //Will not be -100
    
    return 0;
}