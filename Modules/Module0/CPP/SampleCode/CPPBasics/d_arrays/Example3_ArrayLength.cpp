/**
 *  Demonstrates determining the length of an array.
 * 
 *  The sizeof function is used, which returns the total BYTESIZE of the array.
 *  To get the length (total elements), this size must be divided by the size of the data type.
 */

#include <iostream>
using namespace std;

/**
 * Main Function.
 */
int main() {
    
    int numbers[] = {4, 8, 15, 16, 23, 42};                                     //An array of 6 ints.

    int size = sizeof(numbers);                                                 //The total size (in bytes) of the array
    cout << "The numbers array is " << size << " bytes." << endl;
    
    int length = sizeof(numbers) / 4;                                           //Divide the total size by the size of the element (ints are 4 bytes)
    cout << "The numbers array contains " << length << " elements." << endl;

    double temperatures[] = {45.7, 76.4, 81.5};

    //Iterates through the temperatures array. Each element is a double (8 bytes)
    for(int i = 0; i < sizeof(temperatures) / 8; i++) {
        cout << "Element at index " << i << " of the temperatures array is " << temperatures[i] << endl;
    }

    string texts[] = {"ABC", "DEFG", "GHIJK"};

    //Iterates through the texts array. Each element is a string (24 bytes). The loop below acts as if we didn't already know the size of a string.
    for(int i = 0; i < sizeof(texts) / sizeof(string); i++) {
        cout << "Element at index " << i << " of the texts array is " << texts[i] << endl;
    }


    return 0;
}