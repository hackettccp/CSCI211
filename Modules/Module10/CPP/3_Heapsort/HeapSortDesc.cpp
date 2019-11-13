/**
 * Demonstrates using a Max-Heap for a Heapsort (Descending order)
 */
#include<iostream>
#include<stdexcept>
#include "MaxHeap.h"

int main() {
    int numbers[] = {7, 3, 5, 2, 6, 1, 4};
    MaxHeap h;

    //Add each value to the heap
    for(int i = 0; i < 7; i++) {
        h.add(numbers[i]);
    }

    //Move the values in the heap back to the array
    for(int i = 0; i < 7; i++) {
        numbers[i] = h.remove();
    }

    //Prints the array to show it is sorted
    for(int i = 0; i < 7; i++) {
        cout << numbers[i] << endl;
    }

}