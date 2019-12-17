#include <iostream>

using namespace std;

/**
 * Original Bubble Sort Algorithm
 */
void bubbleSort(int a[], int length) {
    int compareCount = 0;
    for(int i = 0; i < length; i++) {
		for(int j = 1; j < length; j++) {
            compareCount++;
			if(a[j-1] > a[j]) {
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		} 
	}
    cout << "Original Bubble Sort Total Comparisons: " << compareCount << endl;
}

/**
 * Bubble Sort Algorithm Improvement 1
 */
void bubbleSort1(int a[], int length) {
    bool sorted;
    int compareCount = 0;
	do {
		sorted = true;
		for(int i = 0; i < length-1; i++) {
            compareCount++;
			if(a[i] > a[i+1]) {
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				sorted = false;
			}
		} 
	} while(!sorted);
    cout << "Bubble Sort Improvement 1 Total Comparisons: " << compareCount << endl;
}

/**
 * Bubble Sort Algorithm Improvement 2
 */
void bubbleSort2(int a[], int length) {
    int compareCount = 0;
    for(int i = 0; i < length; i++) {
		for(int j = 1; j < length - i; j++) {
            compareCount++;
			if(a[j-1] > a[j]) {
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		} 
	}
    cout << "Bubble Sort Improvement 2 Total Comparisons: " << compareCount << endl;
}