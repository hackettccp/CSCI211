/**
 *  Demonstrates a while loop.
 *  (No difference from Java)
 */

#include <iostream>
using namespace std;

/**
 * Main Function.
 */
int main() {
    
    int number;

    cout << "Enter a number between 1 and 10: ";
    cin >> number;

    while(number < 1 || number > 10) {
        cout << "Try again. Enter a number between 1 and 10: ";
        cin >> number;
    }

    cout << "You entered " << number << endl;

    return 0;
}