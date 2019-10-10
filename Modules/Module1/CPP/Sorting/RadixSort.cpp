/**
 * Demonstrates the Radix Sort.
 */

#include <iostream>
#include <ctime>

using namespace std;

//Prototypes
void radixSort(int[], int);
void countingSort(int[], int, int);
int getMax(int[], int);
void printArray(int[], int);

/**
 * Main Function.
 */
int main() { 
    const int LENGTH = 10;                                                                      //Used to easily change/resize the array for testing with longer or shorter arrays
    int numbers[LENGTH];             

    srand((int)time(0));                                                                        //Sets the seed to the current time

    //Fills the array with random numbers. (May include some duplicate numbers.)
    for(int i = 0; i < LENGTH; i++) {
	    numbers[i] = rand() % 100 + 1;                                                          //Puts a random number between 1 and 100 at each index of the array.
	}

    printArray(numbers, LENGTH);                                                                //Prints the current values in the array (Function defined below)
    cout << "Sorting..." << endl;
    radixSort(numbers, LENGTH);
    cout << "Done." << endl;
    printArray(numbers, LENGTH);
    
    return 0;
} 

/**
 * Radix Sort Algorithm.
 */
void radixSort(int a[], int length) {
    int max = getMax(a, length);                                                                //Gets the largest value in the array (Function defined below)

    //Performs a counting sort for every position (1's, 10's, 100's... places). 
    //The loop counter, i, represents the values of 10^x (Starts at 1, or 10^0)
    for (int i = 1; max/i > 0; i *= 10) {
        countingSort(a, length, i);
    }
}

/**
 * Performs a counting sort for each position/place (i) 
 */
void countingSort(int a[], int length, int i) {
    int temp[length];                                                                           //Temporary array for sorting
    int digitCount[10] = {0};                                                                   //Valid digits can only be 0-9 (hence indexes 0-9)
  
    //Stores the counts of each digit's occurrence in position i into digitCount[]
    for (int j = 0; j < length; j++) {
        digitCount[(a[j] / i) % 10]++;
    }
  
    //Linearly sum the values in the digitCount array
    for (int j = 1; j < 10; j++) {
        digitCount[j] += digitCount[j - 1];
    }
  
    //For each value in a, put the value in the temp array
    //and decrease the value at the corresponding index in digitCount, 
    for (int j = length - 1; j >= 0; j--) {
        int index = digitCount[(a[j] / i) % 10] - 1;
        temp[index] = a[j];
        digitCount[(a[j] / i) % 10]--;
    }

    //Copy the values from the temp array (sorted by position) 
    //into the array, a (replacing the old ordering)
    for (int j = 0; j < length; j++) {
        a[j] = temp[j];
    }
} 

/**
 * Finds the largest value in an array of ints.
 */ 
int getMax(int a[], int length) {
    int max = a[0];
    for (int i = 1; i < length; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
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