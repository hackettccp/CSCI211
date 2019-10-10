/**
 *  Demonstrates using a namespace
 */

#include <iostream>                                                 //Needed for std

using namespace std;                                                //No longer need to prefix cout or endl with "std::"

/**
 * Main Function. This is where a C++ program begins
 * (Equivalent to the main method in Java programs)
 */
int main() {
    cout << "Hello World!" << endl;                                 //Prints Hello World! with a line break (This is equivalent to: System.out.println("Hello World!"); in Java)
    cout << "Hello World!" << endl;                                 //Prints Hello World! again
    return 0;                                                       //End of main function
}