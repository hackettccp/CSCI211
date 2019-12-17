#include <iostream>

using namespace std;

/**
 * Insertion Sort Algorithm
 */
void insertionSort(int a[], int length) {
    int compareCount = 0;
    for(int i = 1; i < length; i++) {
		int value = a[i];
		int j = i-1;
        compareCount++;                         //Always at least 1 comparison
		while(j >= 0 && a[j] > value) {
			a[j+1] = a[j];
			j--;
            compareCount++;                     //Next comparison
		}
        if(j < 0) {
            compareCount--;                     //Adjust if the last comparison expected didn't actually happen (because j went negative)
        }
		a[j+1] = value;
	}
    cout << "Insertion Sort Total Comparisons: " << compareCount << endl;
}