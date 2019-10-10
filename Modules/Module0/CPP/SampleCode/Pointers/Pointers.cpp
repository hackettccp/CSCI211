/**
 * Demonstrates the use of pointers and the address operator.
 */
#include <iostream>

using namespace std;

/**
 * Main Function.
 */
int main() {
    int x = 7;                                          //Normal int variable x, assigned 7
    cout << "x = " << x << endl;                        //Prints the value referenced by x
    cout << "x's address is " << &x << endl;            //Prints the reference of x

    int *xPtr;                                          //Declares a pointer to an int
    xPtr = &x;                                          //Assigns the reference of x to xPtr

    cout << "xPtr = " << xPtr << endl;                  //Prints the reference of xPtr
    cout << "xPtr dereferenced is " << *xPtr << endl;   //Prints the value referenced by xPtr
}