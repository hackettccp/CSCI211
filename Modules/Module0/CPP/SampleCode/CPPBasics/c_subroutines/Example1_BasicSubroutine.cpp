/**
 *  Demonstrates creating a subroutine/function
 */

#include <iostream>
using namespace std;

/**
 * A subroutine that simply prints "Hello World!"
 * Subroutines must be defined before you can call them.
 * In this program's case, we could not put this function after the main function.
 */
void printHello() {
    cout << "Hello World!" << endl;
}

/**
 * Main Function.
 */
int main() {
    
    printHello();

    return 0;
}