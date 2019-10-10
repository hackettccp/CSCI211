/**
 *  Demonstrates a do-while loop.
 *  (No difference from Java)
 */

#include <iostream>
using namespace std;

/**
 * Main Function.
 */
int main() {
    
    string entry;

    do {
        cout << "Enter a word with at least 5 characters: ";
        cin >> entry;
    } while(entry.length() < 5);

    cout << entry << " has " << entry.length() << " characters.";

    return 0;
}