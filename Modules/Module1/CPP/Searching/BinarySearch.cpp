/**
 * Demonstrates the binary search.
 */

#include <iostream>

using namespace std;

//Prototypes
void printArray(int[], int);
int binarySearch(int[], int, int);

/**
 * Main Function.
 */
int main() {
    int numbers[] = {3, 7, 9, 15, 18, 24, 31, 45, 67, 82};                                          //Array must be sorted for a binary search to work.             
    const int LENGTH = sizeof(numbers)/sizeof(numbers[0]);                                          //Calculates the length of the array
    printArray(numbers, LENGTH);                                                                    //Prints the current values in the array (Function defined below)
 
    int value = 0;
    cout << "Enter a value to search for (-99 to quit): ";
    cin >> value;
    while(value != -99) {
        int foundIndex = binarySearch(numbers, LENGTH, value);
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
 * Binary Search Algorithm
 */
int binarySearch(int a[], int length, int searchValue) {
    int lowBoundary = 0;
	int highBoundary = length - 1;
	while(highBoundary >= lowBoundary) {
		int middle = (highBoundary + lowBoundary) / 2;                              //Calculate middle index
		if(searchValue == a[middle]) {
			return middle;                                                          //Return the index we found it at
		}
		else if(searchValue > a[middle]) {
			lowBoundary = middle + 1;                                               //Raise the low boundary
		}
		else {
			highBoundary = middle - 1;                                              //Lower the high boundary
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

