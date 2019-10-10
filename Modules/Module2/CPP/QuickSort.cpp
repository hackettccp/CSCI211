/**
 * Demonstrates the quick sort.
 */
#include<iostream>
#include<ctime>

using namespace std;

//Prototypes
void quicksort(int[], int, int);
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
 * Quick Sort Algorithm 
 */
void quicksort(int array[], int start, int end) {
    int lower = start;                                //Index for inserting in the lower partition
    int upper = end;                                  //Index for inserting in the upper partition
    int temp;                                         //Used when swapping values
    int pivot = array[(lower + upper) / 2];           //Uses the middle element as the pivot value

    //Partitioning
    //Moves numbers less than the pivot to the lower partition, numbers greater than to the pivot to the upper partition
    while(lower <= upper) {
        while(array[lower] < pivot) {
            lower++;                                  //Increment the lower insert index as long as values are less than the pivot value
        }
        while(array[upper] > pivot) {
            upper--;                                  //Decrement the upper insert index as long as values are greater than the pivot value
        }
        if(lower <= upper) {
            //Swap the elements at index "lower" and index "upper" (the indexes where the above while loops needed to stop)                                    
            temp = array[lower];
            array[lower] = array[upper];
            array[upper] = temp;
            lower++;                                  //Increment the lower insert index
            upper--;                                  //Decrement the upper insert index 
        }
    }

    //Recursively partition the lower and upper partitions
    if(start < upper) {
        quicksort(array, start, upper);               //Lower partition (Start index through where upper left off)
    }
    if(lower < end) {
        quicksort(array, lower, end);                 //Upper partition (Where lower left off through the ending index)
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
