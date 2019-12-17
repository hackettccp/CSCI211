#include <iostream>

using namespace std;

/**
 * Selection Sort Algorithm
 */
void selectionSort(int a[], int length) {
    int compareCount = 0;
    for(int i = 0; i < length-1; i++) {
		int smallest = i;
		for(int j = i+1; j < length; j++) {
            compareCount++;
			if(a[j] < a[smallest]) {
				smallest = j;
			}
		}
		if(smallest != i) {
			int temp = a[smallest];
			a[smallest] = a[i];
			a[i] = temp;
		}
	}
    cout << "Selection Sort Total Comparisons: " << compareCount << endl;
}