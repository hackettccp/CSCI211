/**
 * Compares the counts of multiple sorting algorithms.
 */

#include <iostream>
#include <ctime>
#include "../BubbleSort/BubbleSorts.h"
#include "../CocktailShakerSort/CocktailSorts.h"
#include "../InsertionSort/InsertionSort.h"
#include "../SelectionSort/SelectionSort.h"

using namespace std;

//Prototypes
void printArray(int[], int);

/**
 * Main Function.
 */
int main() {
    const int LENGTH = 5;                                                                          //Used to easily change/resize the array for testing with longer or shorter arrays
    int numbers[LENGTH];
    int numbers2[LENGTH];
    int numbers3[LENGTH];
    int numbers4[LENGTH];
    int numbers5[LENGTH];
    int numbers6[LENGTH];
    int numbers7[LENGTH];
    
    
    srand((int)time(0));                                                                            //Sets the seed to the current time
    
    //Fills the arrays with the same sequence of random numbers. (May include some duplicate numbers.)
    for(int i = 0; i < LENGTH; i++) {
        int rNum = rand() % 100 + 1;                                                                //Gets a random number between 1 and 100.
	    numbers[i] = rNum;
        numbers2[i] = rNum;
        numbers3[i] = rNum;
        numbers4[i] = rNum;
        numbers5[i] = rNum;
        numbers6[i] = rNum;
        numbers7[i] = rNum;
	}
    printArray(numbers, LENGTH);
    
    //Sorts each array using a different algorithm
    cout << "Sorting..." << endl;
    bubbleSort(numbers, LENGTH);
    bubbleSort1(numbers2, LENGTH);
    bubbleSort2(numbers3, LENGTH);
    cocktailSort(numbers4, LENGTH);
    cocktailSort2(numbers5, LENGTH);
    selectionSort(numbers6, LENGTH);
    insertionSort(numbers7, LENGTH);
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

