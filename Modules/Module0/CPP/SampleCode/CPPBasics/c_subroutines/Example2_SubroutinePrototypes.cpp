/**
 *  Demonstrates creating a subroutine/function prototype
 */

#include <iostream>
using namespace std;

void printHello();              //Function prototype. This function can be defined anywhere in the file now.

/**
 * Main Function.
 */
int main() {
    
    printHello();

    return 0;
}

/**
 * A subroutine that simply prints "Hello World!"
 */
void printHello() {
    cout << "Hello World!" << endl;
}