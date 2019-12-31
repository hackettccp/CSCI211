/**
 * Demonstrates the Bucket Sort.
 */

#include <iostream>
#include <ctime>
#include "BucketSort.h"

using namespace std;

//Prototypes
void printArray(double[], int);

/**
 * Main Function.
 */
int main() { 
    const int LENGTH = 10;                                                                      //Used to easily change/resize the array for testing with longer or shorter arrays
    double numbers[LENGTH];             

    srand((int)time(0));                                                                        //Sets the seed to the current time

    //Fills the array with random numbers. (May include some duplicate numbers.)
    for(int i = 0; i < LENGTH; i++) {
        numbers[i] = (double)rand() / (double)RAND_MAX;                                         //Puts a random number between 0.0 and 1.0 at each index of the array.
    }

    printArray(numbers, LENGTH);                                                                //Prints the current values in the array (Function defined below)
    cout << "Sorting..." << endl;
    bucketSort(numbers, LENGTH);                                                                //Passes the array and the length to the bucket sort function
    cout << "Done." << endl;
    printArray(numbers, LENGTH);                                                                //Prints the current values in the sorted array
    
    return 0;
} 

/**
 * Simply prints the current values in the array.
 */
void printArray(double a[], int length) {
    cout << "Current values in the array: " << endl;
    for(int i = 0; i < length; i++) {
	    cout << a[i] << " ";
	}
    cout << endl;
}