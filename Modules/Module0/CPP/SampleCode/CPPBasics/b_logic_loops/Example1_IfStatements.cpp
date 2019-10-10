/**
 *  Demonstrates if statements.
 *  (No difference from Java)
 */

#include <iostream>
using namespace std;

/**
 * Main Function.
 */
int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if(number < 0) {
        cout << "That number is negative." << endl;
    }
    else if(number % 2 == 1) {
        cout << "That number is odd." << endl;
    }
    else {
        cout << "That number is even." << endl;
    }

    return 0;
}