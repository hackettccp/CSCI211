/**
 *  Demonstrates variables and primitive data types in C++
 * 
 */

#include <iostream>
using namespace std;

/**
 * Main Function.
 */
int main() {
    int number = 75;                                        //Same 4-byte (32-bit) signed integer data type as Java
    long number2 = 1234L;                                   //Same as an int (4-bytes). Historically, ints were 16-bits.
    long long number3 = 12345L;                             //Equivalent to the 8-byte (64-bit) signed "long" data type in Java.
    
    float number4 = 100.6F;                                 //Same 4-byte (32-bit) signed floating point data type as Java
    double number5 = 123.456;                               //Same 8-byte (64-bit) signed floating point data type as Java
    long double number6 = 45.23;                            //12-byte (96-bit) signed floating point data type

    short int number7 = 100;                                //Equivalent to the 2-byte (16-bit) signed short data type in Java
    short number8 = 432;                                    //Equivalent to "short int"

    char char1 = 10;                                        //Equivalent to the 1-byte (8-bit) signed byte data type in Java
    char char2 = 'X';                                       //Can be used like the char data type in Java.

    bool boolean1 = true;                                   //Equivalent to the 1-byte (8-bit, though only 1 is ever used) boolean data type in Java.
    
    
    //Prints the size of each of these variables.
    //The sizeof function returns an int- The number of bytes the type uses.
    cout << "Size of number: " << sizeof(number) << " bytes." << endl;
    cout << "Size of number2: " << sizeof(number2) << " bytes." << endl;
    cout << "Size of number3: " << sizeof(number3) << " bytes.\n" << endl;
    cout << "Size of number4: " << sizeof(number4) << " bytes." << endl;
    cout << "Size of number5: " << sizeof(number5) << " bytes." << endl;
    cout << "Size of number6: " << sizeof(number6) << " bytes.\n" << endl;
    cout << "Size of number7: " << sizeof(number7) << " bytes." << endl;
    cout << "Size of number8: " << sizeof(number8) << " bytes.\n" << endl;
    cout << "Size of char1: " << sizeof(char1) << " byte." << endl;
    cout << "Size of char2: " << sizeof(char2) << " byte." << endl;
    cout << "Size of boolean1: " << sizeof(boolean1) << " byte." << endl;

    return 0;
}