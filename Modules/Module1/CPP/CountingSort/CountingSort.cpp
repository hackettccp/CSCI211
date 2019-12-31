/**
 * Demonstrates the Counting Sort.
 */
#include <iostream>
#include <ctime>
#include "CountingSort.h"

using namespace std;

//Prototypes
void printArray(int[], int);

/**
 * Main Function.
 */
int main() {
    const int LENGTH = 10;                                                                          //Used to easily change/resize the array for testing with longer or shorter arrays
    int numbers[LENGTH];																			//The array of numbers
    
	srand((int)time(0));                                                                            //Sets the seed to the current time
    //Fills the array with random numbers. (May include some duplicate numbers.)
    for(int i = 0; i < LENGTH; i++) {
	    numbers[i] = rand() % 20 + 1;                                                       		//Puts a random number between 1 and 20 at each index of the array.
	}
    
    printArray(numbers, LENGTH);                                                            		//Prints the current values in the unsorted array (Function defined below)
    cout << "Sorting..." << endl;
	countingSort(numbers, LENGTH);																	//Passes the array and the length to the counting sort function
    cout << "Done." << endl;
    printArray(numbers, LENGTH);																	//Prints the current values in the sorted array
    
    return 0;
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

