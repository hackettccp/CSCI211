/**
 * Demonstrates the jump search.
 */

#include <iostream>
#include <cmath>

using namespace std;

//Prototypes
void printArray(int[], int);
int jumpSearch(int[], int, int);

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
        int foundIndex = jumpSearch(numbers, LENGTH, value);
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
 * Jump Search Algorithm
 */
int jumpSearch(int a[], int length, int searchValue) {
    int previous = 0;
	int jump = (int) sqrt(length);
	while(a[(jump < length ? jump : length-1)-1] < searchValue) {
		previous = jump;
		jump += jump;
		if(jump >= length) {
            break;
		}
	}
	while(a[previous] < searchValue) {
		previous += 1;
		if(previous == (jump < length ? jump : length)) {
			return -1;
		}
	}
	return a[previous] == searchValue ? previous : -1;
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

