/**
 * Demonstrates the Fisher-Yates algorithm.
 */

#include <iostream>
#include <ctime>

using namespace std;

//Prototypes
void printArray(int[], int);
void shuffle(int[], int);

/**
 * Main Function.
 */
int main() {
    int numbers[] = {3, 7, 9, 15, 18, 24, 31, 45, 67, 82};            
    const int LENGTH = sizeof(numbers)/sizeof(numbers[0]);          
    
    printArray(numbers, LENGTH);

    cout << "Shuffling..." << endl;
    shuffle(numbers, LENGTH);
    cout << "Done." << endl;

    printArray(numbers, LENGTH);

    return 0;
}

/**
 * Fisher-Yates Algorithm
 */
void shuffle(int a[], int length) {
	srand((int)time(0));
	for(int i = 1; i < length; i++) {
		int j = rand() % (i+1);                     //Random number between 0 and i
		int temp = a[j];
		a[j] = a[i];
		a[i] = temp;
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

