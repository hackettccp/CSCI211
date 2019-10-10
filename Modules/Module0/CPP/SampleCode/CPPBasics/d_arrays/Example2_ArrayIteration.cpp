/**
 *  Demonstrates iterating through an array.
 */

#include <iostream>
using namespace std;

/**
 * Main Function.
 */
int main() {
    
    int numbers[] = {4, 8, 15, 16, 23, 42};             //An array of 6 ints.
    
    //Iterates using a traditional for loop
    for(int i = 0; i < 6; i++) {
        cout << "Element at index " << i << " is " << numbers[i] << endl;
    }

    cout << endl;       //Blank line

    //Iterates using an enhanced for loop ("for-each" or "for-in" loop)
    for(int number : numbers) {
        cout << "Element: " << number << endl;
    }

    return 0;
}