/**
 * Counting Sort Algorithm
 */
void countingSort(int a[], int length) {
    int result[length];                                 //Temporary array for sorting

	//Find the largest value in unsorted array "a"
	int max = a[0];
	for(int i = 1; i < length; i++) {
		if(a[i] > max) {
			max = a[i];
		}
	}

	//Create the counting array "c" and set all indexes to zero. (C++ doesn't do that automatically)
	int c[max + 1];
	for(int i = 0; i < max+1; i++) {
		c[i] = 0;
	}
	
	//For each value in "a", increment the corresponding index in "c"
	for(int i = 0; i < length; i++) {
		int value = a[i];
		c[value] += 1;
	}

	//Linearly sum the values in the array "c"
	for(int i = 1; i < max + 1; i++) {
		c[i] += c[i-1];
	}
	
	//For each value in "a", decrease the value at the corresponding index in "c", 
	//and put the value in the sorted array "r" at index "c[temp]"
	for(int i = 0; i < length; i++) {
		int temp = a[i];
		c[temp] -= 1;
		result[c[temp]] = temp;
	}

    //Copy each value in "result" (sorted) to the original array
	for(int i = 0; i < length; i++) {
		a[i] = result[i];
	}
}