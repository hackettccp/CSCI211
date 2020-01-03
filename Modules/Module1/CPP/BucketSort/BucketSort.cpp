/**
 * Demonstrates the Bucket Sort.
 */

#include <iostream>
#include <ctime>
#include "BucketSort.h"

using namespace std;

//Prototypes
void printArray(int[], int);

/**
 * Main Function.
 */
int main() { 
    const int LENGTH = 20;                                                                      //Used to easily change/resize the array for testing with longer or shorter arrays
    const int BUCKETS = 5;																		//Used to easily change the number of buckets to use
	int numbers[LENGTH];             

    srand((int)time(0));                                                                        //Sets the seed to the current time

    //Fills the array with random numbers. (May include some duplicate numbers.)
    for(int i = 0; i < LENGTH; i++) {
    	int rNum = rand() % 50 + 1;                                                            //Puts a random number between 1 and 50 at each index of the array.
    	numbers[i] = rNum;
    }

    printArray(numbers, LENGTH);                                                                //Prints the current values in the array (Function defined below)
    cout << "Sorting..." << endl;
    bucketSort(numbers, LENGTH, BUCKETS);                                                       //Passes the array and the length to the bucket sort function
    cout << "Done." << endl;
    printArray(numbers, LENGTH);                                                                //Prints the current values in the sorted array
    
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
