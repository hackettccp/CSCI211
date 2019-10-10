/**
 * Demonstrates the linear search.
 */

#include <iostream>
#include <ctime>

using namespace std;

//Prototypes
void printArray(int[], int);
int linearSearch(int[], int, int);

/**
 * Main Function.
 */
int main() {
    const int LENGTH = 10;                                                                          //Used to easily change/resize the array for testing with longer or shorter arrays
    int numbers[LENGTH];             
    
    srand((int)time(0));                                                                            //Sets the seed to the current time
    
    //Fills the array with random numbers. (May include some duplicate numbers.)
    for(int i = 0; i < LENGTH; i++) {
	    numbers[i] = rand() % 100 + 1;                                                              //Puts a random number between 1 and 100 at each index of the array.
	}
    
    printArray(numbers, LENGTH);                                                                    //Prints the current values in the array (Function defined below)
 
    int value = 0;
    cout << "Enter a value to search for (-99 to quit): ";
    cin >> value;
    while(value != -99) {
        int foundIndex = linearSearch(numbers, LENGTH, value);
        if(foundIndex >= 0) {
            cout << "Found " << value << " at index " << foundIndex << endl;
        }
        else {
            cout << value << " was not found." << endl;
        }
        cout << "Enter a value to search for (-99 to quit): ";
        cin >> value;
    }

    return 0;
}

/**
 * Linear Search Algorithm
 */
int linearSearch(int a[], int length, int searchValue) {
    for(int i = 0; i < length; i++) {
	    if(a[i] == searchValue) {
            return i;                                                               //The index we found it at
        }
	}
    return -1;                                                                      //The search value was not found
}

/**
 * Simply prints the current values in the array.
 */
void printArray(int a[], int length) {
    cout << "Current values in the array: " << endl;
    for(int i = 0; i < length; i++) {
	    cout << a[i] << " ";
	}
    cout << endl;
}

