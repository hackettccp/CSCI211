#include <vector>
#include <iostream>

using namespace std;

//Prototype
void insertionSort(vector<double>&, int);

/**
 * Bucket Sort Algorithm
 */
void bucketSort(double a[], int length) {
    vector<double> buckets[length];                                 //An array of vectors (the vectors will serve as buckets)
    
    //Distribute the array elements into different buckets 
    for (int i=0; i<length; i++) { 
       int bucketindex = int(a[i] * length);                        //Calculates bucket index
       buckets[bucketindex].push_back(a[i]);                        //Adds the element to the bucket
    } 
  
    //Sort each bucket
    for (int i=0; i<length; i++) {
        insertionSort(buckets[i], buckets[i].size());
    }
  
    //Move the elements from each bucket back into the original array 
    int index = 0;                                                  //Index to place the next element back into the original array
    for (int i = 0; i < length; i++) {
        while(!buckets[i].empty()) {
            a[index++] = *(buckets[i].begin());
            buckets[i].erase(buckets[i].begin());
        }
    }
} 

/**
 * Insertion Sort Algorithm
 */
void insertionSort(vector<double> &v, int length) {
    for(int i = 1; i < length; i++) {
		double value = v[i];
		int j = i-1;
		while(j >= 0 && v[j] > value) {
			v[j+1] =v[j];
			j--;
		}
		v[j+1] = value;
	}
}