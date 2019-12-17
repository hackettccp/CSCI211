#include <iostream>

using namespace std;

/**
 * Original Cocktail Shaker Sort Algorithm
 */
void cocktailSort(int a[], int length) {
    int compareCount = 0;
    bool sorted;
	do {
		sorted = true;
		for(int i = 1; i < length; i++) {
            compareCount++;
			if(a[i-1] > a[i]) {
				int temp = a[i-1];
				a[i-1] = a[i];
				a[i] = temp;
				sorted = false;
			}
		}
		if(sorted) {
			break;
		}
		for(int j = length-1; j > 0; j--) {
            compareCount++;
			if(a[j] < a[j-1]) {
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
				sorted = false;
			}
		}
	} while(!sorted);
    cout << "Original Cocktail Shaker Sort Total Comparisons: " << compareCount << endl;
}

/**
 * Improved Cocktail Shaker Sort Algorithm
 */
void cocktailSort2(int a[], int length) {
    int compareCount = 0;
    int lowBound = 0;
    int highBound = length - 1;

    while(lowBound < highBound) {
        //Forward
        for(int i = lowBound; i < highBound; i++) {
            compareCount++;
            if(a[i] > a[i+1]) {
			    int temp = a[i+1];
			    a[i+1] = a[i];
			    a[i] = temp;
		    }
        }
        highBound--;
        
        //Reverse
        for(int i = highBound; i > lowBound; i--) {
            compareCount++;
            if(a[i-1] > a[i]) {
			    int temp = a[i-1];
			    a[i-1] = a[i];
			    a[i] = temp;
		    }
        }
        lowBound++;
    }
    cout << "Improved Cocktail Shaker Sort Total Comparisons: " << compareCount << endl;
}