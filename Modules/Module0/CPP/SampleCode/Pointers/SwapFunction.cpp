/**
 * Demonstrates a function with pointer arguments.
 */
#include <iostream>

using namespace std;

//Prototypes
void swap(int*, int*);
void printArray(int[], int);

/**
 * Main Function.
 */
int main() {
    int num1 = 18;
    int num2 = 5;
    cout << "num1 = " << num1 << " | num2 = " << num2 << endl;
    swap(num1, num2);                                                   //Will change the references of num1 and num2 back here in the main function
    cout << "num1 = " << num1 << " | num2 = " << num2 << endl;

    int a[] = {4, 5, 6, 7};
    printArray(a, 4);
    swap(a[1], a[2]);
    printArray(a, 4);
}

/**
 * Uses pointer arguments to swap the values of two ints 
 */
void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
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