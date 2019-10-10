/**
 * Demonstrates a recursive bubble sort.
 */
#include<iostream>
#include<ctime>

using namespace std;

//Prototype
void bubbleSort(int[], int);
void printArray(int[], int);

/**
 * Main Function.
 */
int main() {
	const int LENGTH = 10;                                                                          //Used to easily change/resize the array for testing with longer or shorter arrays
    int numbers[LENGTH];             
    
    srand((int)time(0));                                                                            //Sets the seed to the current time
    
    //Fills the array with random numbers. (May include some duplicate numbers.)
    for(int i = 0; i < LENGTH; i++) {
	    numbers[i] = rand() % 100 + 1;                                                              //Puts a random number between 1 and 100 at each index of the array.
	}
	
    printArray(numbers, LENGTH);                                                                    //Prints the current values in the array (Function defined below)
    cout << "Sorting..." << endl;
	bubbleSort(numbers,LENGTH);
    cout << "Done." << endl;
    printArray(numbers, LENGTH);
	
	return 0;
}

/**
 * Recursive Bubble Sort Algorithm
 */
void bubbleSort(int a[], int length) {
	//BASE CASE
    if(length == 1) {
		return;                                                                                     //Sorting for index 0 (length of sorting space is 1)
	}
	
    //RECURSIVE CASE
	for(int i = 0; i < length-1; i++) {                                                             //Swaps remaining unsorted values in the array
		if(a[i] > a[i+1]) {
			int temp = a[i+1];
			a[i+1] = a[i];
			a[i] = temp;
		}
	}
	bubbleSort(a, length-1);
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

