/**
 * Demonstrates the Bogosort.
 */

#include <iostream>
#include <ctime>

using namespace std;

//Prototypes
void printArray(int[], int);
void bogoSort(int[], int);

/**
 * Main Function.
 */
int main() {
    //Might only take a second or so to finish sorting. Try it with a LENGTH of 11, then 12, then (if you have time to wait) 13...
    const int LENGTH = 10;                                                                          //Used to easily change/resize the array for testing with longer or shorter arrays
    int numbers[LENGTH];             
    
    srand((int)time(0));                                                                            //Sets the seed to the current time
    
    //Fills the array with random numbers. (May include some duplicate numbers.)
    for(int i = 0; i < LENGTH; i++) {
	    numbers[i] = rand() % 100 + 1;                                                              //Puts a random number between 1 and 100 at each index of the array.
	}
    
    printArray(numbers, LENGTH);                                                                    //Prints the current values in the array (Function defined below)
    cout << "Sorting..." << endl;
    bogoSort(numbers, LENGTH);
    cout << "Done." << endl;
    printArray(numbers, LENGTH);
    
    return 0;
}

/**
 * Bogosort Algorithm
 */
void bogoSort(int a[], int length) {
    bool sorted;
	srand((int)time(0));
	do {
		sorted = true;
		for(int i = 1; i < length; i++) {
			if(a[i-1] > a[i]) {
				sorted = false;
			}
		}
		if(!sorted) {
			for(int i = 1; i < length; i++) {
				int j = rand() % (i+1);
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	} while(!sorted);
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

