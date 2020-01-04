/**
 * Demonstrates the quicksort.
 */
#include<iostream>
#include<ctime>
#include "QuickSort.h"

using namespace std;

//Prototypes
void printArray(int[], int);

int main() {
    const int LENGTH = 10; //Used to easily change/resize the array for testing with longer or shorter arrays
    int numbers[LENGTH];

    srand((int)time(0)); //Sets the seed to the current time

    //Fills the array with random numbers. (May include some duplicate numbers.)
    for(int i = 0; i < LENGTH; i++) {
          numbers[i] = rand() % 100 + 1; //Puts a random number between 1 and 100 at each index of the array.
    }

    printArray(numbers, LENGTH); //Prints the current values in the array (Function defined below)
    cout << "Sorting..." << endl;
    quicksort(numbers, 0, LENGTH-1);
    cout << "Done." << endl;
    printArray(numbers, LENGTH);

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
