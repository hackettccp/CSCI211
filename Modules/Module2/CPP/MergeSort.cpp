/**
 * Demonstrates the merge sort.
 */
#include<iostream>
#include<ctime>

using namespace std;

//Prototypes
void mergesort(int[], int, int);
void merge(int[], int, int, int);
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
	mergesort(numbers, 0, LENGTH-1);
    cout << "Done." << endl;
    printArray(numbers, LENGTH);
	
	return 0;
}

/**
 * Merge Sort Algorithm 
 */
void mergesort(int array[], int left, int right) {
    //Check that the left boundary of the partition is less than the right boundary of the partition
    if(left < right) { 
        int middle = (left+right)/2;            //Calculate the middle index
  
        mergesort(array, left, middle);         //Recursively break down the lower partition
        mergesort(array, middle+1, right);      //Recursively break down the upper partition

        merge(array, left, middle, right);      //Merge the partitions
    } 
} 

/**
 * Merges two partitions of an array together, in the correct order. 
 */
void merge(int array[], int left, int middle, int right) { 
    int lowerCounter = 0;                                               //Working index of the lower partition 
    int upperCounter = 0;                                               //Working index of the upper partition 
    int mergeCounter = left;                                            //Working index of the entire (lower and upper) parition
    
    int lowerSize = middle - left + 1;                                  //Calculate size of the lower partition
    int upperSize = right - middle;                                     //Calculate size of the upper partition
  
    //Two temporary arrays that will be used in the merge process
    int tempLower[lowerSize];
	int tempUpper[upperSize]; 
  
    //Copy elements into the temporary arrays
    for(int i = 0; i < lowerSize; i++) {
        tempLower[i] = array[left + i]; 
    }
	for(int i = 0; i < upperSize; i++) {
        tempUpper[i] = array[middle + 1 + i]; 
    }
  
    //Copy the elements of the temp arrays back into array
    //Effectively, this "merges" the temporary elements into the actual array
    while(lowerCounter < lowerSize && upperCounter < upperSize) { 
        
        //The smaller element is put in the actual array at index "mergeCounter"
        if(tempLower[lowerCounter] <= tempUpper[upperCounter]) { 
            array[mergeCounter] = tempLower[lowerCounter];
            lowerCounter++;                                                         //Increment the lower partition index
        } 
        else { 
            array[mergeCounter] = tempUpper[upperCounter];
            upperCounter++;                                                         //Increment the upper partition index
        } 
        
        //Increment index to place the next value from the two partitions
        mergeCounter++; 
    } 

    //**Only one of the two partitions might still have values left over, so we have to check both with the below while loops**

    //Copy the remaining elements of tempLower, if there are any 
    while(lowerCounter < lowerSize) { 
        array[mergeCounter] = tempLower[lowerCounter]; 
        lowerCounter++; 
        mergeCounter++; 
    } 
  
    //Copy the remaining elements of tempUpper, if there are any
    while(upperCounter < upperSize) { 
        array[mergeCounter] = tempUpper[upperCounter]; 
        upperCounter++; 
        mergeCounter++; 
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
  
