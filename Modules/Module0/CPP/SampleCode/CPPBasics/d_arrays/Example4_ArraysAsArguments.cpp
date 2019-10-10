/**
 *  Demonstrates passing an array as an argument.
 */

#include <iostream>
using namespace std;

//Prototypes
int getSmallest(int[], int);
int getLargest(int[], int);

/**
 * Main Function.
 */
int main() {
    
    int numbers[5];
    cout << "Enter 5 numbers" << endl;

    //Iterates using a traditional for loop and prompts for the 5 numbers
    for(int i = 0; i < 5; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    cout << "The smallest number is " << getSmallest(numbers, 5) << endl;
    cout << "The largest number is " << getLargest(numbers, 5) << endl;

    return 0;
}

/**
 * Function that accepts an array of ints as an argument and the size of the array.
 * Determines and returns the smallest number in the list.
 * We need to provide the size because the parameter is an unsized array (a[]).
 * We'll see other ways to pass arrays as arguments later in the semester.
 */
int getSmallest(int a[], int size) {
    int smallest = a[0];
    for(int i = 1; i < size; i++) {
        if(a[i] < smallest) {
            smallest = a[i];
        }
    }
    return smallest;
}

/**
 * Function that accepts an array of ints as an argument and the size of the array.
 * Determines and returns the largest number in the list.
 */
int getLargest(int a[], int size) {
    int largest = a[0];
    for(int i = 1; i < size; i++) {
        if(a[i] > largest) {
            largest = a[i];
        }
    }
    return largest;
}