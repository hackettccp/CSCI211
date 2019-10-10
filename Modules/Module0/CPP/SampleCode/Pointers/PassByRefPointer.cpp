/**
 * Demonstrates passing by reference with pointer arguments.
 */
#include <iostream>

using namespace std;

//Prototypes
void test(int*);

/**
 * Main Function.
 */
int main() {
    int num1;
    num1 = 18;
    cout << "num1 in main function = " << num1 << endl;
    test(&num1);                                                         //Will change the value at num1's address
    cout << "num1 in main function = " << num1 << endl;

}

/**
 * Uses pointer argument to change the data 
 */
void test(int *n1) {
    cout << "n1 in test function = " << *n1 << endl;
    *n1 = 100;
    cout << "n1 changed = " << *n1 << endl;
}