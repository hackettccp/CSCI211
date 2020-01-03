#include <vector>
#include <iostream>

using namespace std;

//Prototype
void insertionSort(vector<int>&, int);

/**
 * Bucket Sort Algorithm
 */
void bucketSort(int a[], int length, int numBuckets) {
    vector<int> buckets[numBuckets];                                //An array of vectors (the vectors will serve as buckets)
    
	//Calculate the max
	int max = a[0];
    for(int i = 1; i < length; i++) {
        if(a[i] > max) {
			max = a[i];
		}
	}

	//Distribute the array elements into different buckets
	for(int i = 0; i < length; i++) {
		int bIndex = (int)(a[i] * numBuckets / (max+1));            //Calculates bucket index
		buckets[bIndex].push_back(a[i]);							//Adds the element to the bucket
	}

	//Sort each bucket
	for(int i = 0; i < numBuckets; i++) {
		insertionSort(buckets[i], buckets[i].size());
	}

	//Move the elements from each bucket back into the original array 
	int index = 0;
	for (int i = 0; i < numBuckets; i++) {
		while(!buckets[i].empty()) {
			a[index++] = *(buckets[i].begin());						//Get the first value in the bucket and put it in the array
			buckets[i].erase(buckets[i].begin());					//Remove the value from the bucket
		}
	}
}

/**
 * Insertion Sort Algorithm
 */
void insertionSort(vector<int> &v, int length) {
    for(int i = 1; i < length; i++) {
		int value = v[i];
		int j = i-1;
		while(j >= 0 && v[j] > value) {
			v[j+1] =v[j];
			j--;
		}
		v[j+1] = value;
	}
}
