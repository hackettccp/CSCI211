/**
 * Demonstrates the Cocktail Shaker Sort.
 */

#include <iostream>
#include <ctime>
#include "CocktailSorts.h"

using namespace std;

//Prototypes
void printArray(int[], int);

/**
 * Main Function.
 */
int main() {
    const int LENGTH = 10;                                                                          //Used to easily change/resize the array for testing with longer or shorter arrays
    int numbers[LENGTH];             
    int numbers2[LENGTH];

    srand((int)time(0));                                                                            //Sets the seed to the current time
    
    //Fills the array with random numbers. (May include some duplicate numbers.)
    for(int i = 0; i < LENGTH; i++) {
	    int rNum = rand() % 100 + 1;                                                                //Gets a random number between 1 and 100.
	    numbers[i] = rNum;
        numbers2[i] = rNum;
	}
    
    printArray(numbers, LENGTH);                                                                    //Prints the current values in the array (Function defined below)
    cout << "Sorting..." << endl;
    cocktailSort(numbers, LENGTH);
	cocktailSort2(numbers2, LENGTH);
    cout << "Done." << endl;
    
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

