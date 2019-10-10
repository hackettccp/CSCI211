/**
 * Demonstrates a recursive binary search.
 */
#include<iostream>

using namespace std;

//Prototype
int binarySearch(int[], int, int, int);
void printArray(int[], int);

/**
 * Main Function.
 */
int main() {
	int numbers[] = {3, 7, 9, 15, 18, 24, 31, 45, 67, 82};                                          //Array must be sorted for a binary search to work.             
   const int LENGTH = sizeof(numbers)/4;                                                           //Calculates the length of the array
   printArray(numbers, LENGTH);                                                                    //Prints the current values in the array (Function defined below)
 
   int value = 0;
   cout << "Enter a value to search for (-99 to quit): ";
   cin >> value;
   while(value != -99) {
      int foundIndex = binarySearch(numbers, 0, LENGTH-1, value);
      if(foundIndex >= 0) {
         cout << "Found " << value << " at index " << foundIndex << endl;
      }
      else {
         cout << value << " was not found." << endl;
      }
      cout << "Enter a value to search for (-99 to quit): ";
      cin >> value;
   }
   return 0;
}

/**
 * Recursive Binary Search Algorithm
 */
int binarySearch(int array[], int first, int last, int value) {
   if(first > last) {
      return -1;                                                  //First base Case
   }
      
   int middle = (first + last) / 2;                               //Calculate the middle position.
       
   if(array[middle] == value) {
      return middle;                                              //Second base case
   }
   else if (array[middle] < value) {
      return binarySearch(array, middle + 1, last, value);        //Recursive case (Search upper partition/upper half)
   }
   else {
      return binarySearch(array, first, middle - 1, value);       //Recursive case (Search lower partition/lower half)
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

