/**
 * Demonstrates passing by value.
 */
#include <iostream>

using namespace std;

//Prototypes
void test(int);

/**
 * Main Function.
 */
int main() {
    int num1 = 18;
    cout << "num1 in main function = " << num1 << endl;
    test(num1);                                                         //Will change the references of num1 and num2 back here in the main function
    cout << "num1 in main function (not changed) = " << num1 << endl;

}

/**
 * Uses pointer arguments to swap the values of two ints 
 */
void test(int n1) {
    cout << "n1 in test function = " << n1 << endl;
    n1 = 100;
    cout << "n1 changed = " << n1 << endl;
}
