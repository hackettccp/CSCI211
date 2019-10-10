/**
 * Demonstrates the Counting Sort.
 */

#include <iostream>
#include <ctime>

using namespace std;

//Prototypes
void printArray(int[], int);
void countingSort(int[], int[], int);

/**
 * Main Function.
 */
int main() {
    const int LENGTH = 10;                                                                          //Used to easily change/resize the array for testing with longer or shorter arrays
    int unsortedNumbers[LENGTH];																	//The array of unsorted numbers
	int sortedNumbers[LENGTH];              														//The array to contain the numbers when the are sorted
    
	srand((int)time(0));                                                                            //Sets the seed to the current time
    //Fills the array with random numbers. (May include some duplicate numbers.)
    for(int i = 0; i < LENGTH; i++) {
	    unsortedNumbers[i] = rand() % 20 + 1;                                                       //Puts a random number between 1 and 20 at each index of the array.
	}
    
    printArray(unsortedNumbers, LENGTH);                                                            //Prints the current values in the unsorted array (Function defined below)
    cout << "Sorting..." << endl;
	countingSort(unsortedNumbers, sortedNumbers, LENGTH);											//Passes the unsorted array, the array to hold the sorted values, and the length to the counting sort function
    cout << "Done." << endl;
    printArray(sortedNumbers, LENGTH);																//Prints the current values in the sorted array
    
    return 0;
}

/**
 * Counting Sort Algorithm
 */
void countingSort(int a[], int r[], int length) {
	//Find the largest value in unsorted array "a"
	int max = a[0];
	for(int i = 1; i < length; i++) {
		if(a[i] > max) {
			max = a[i];
		}
	}

	//Create the counting array "c" and set all indexes to zero. (C++ doesn't do that automatically)
	int c[max + 1];
	for(int i = 0; i < max+1; i++) {
		c[i] = 0;
	}
	
	//For each value in "a", increment the corresponding index in "c"
	for(int i = 0; i < length; i++) {
		int value = a[i];
		c[value] += 1;
	}

	//Linearly sum the values in the array "c"
	for(int i = 1; i < max + 1; i++) {
		c[i] += c[i-1];
	}
	
	//For each value in "a", decrease the value at the corresponding index in "c", 
	//and put the value in the sorted array "r" at index "c[temp]"
	for(int i = 0; i < length; i++) {
		int temp = a[i];
		c[temp] -= 1;
		r[c[temp]] = temp;
	}
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

