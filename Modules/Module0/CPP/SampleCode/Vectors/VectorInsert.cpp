/**
 * Demonstrates the basic use of Vectors.
 */
#include <iostream>
#include <vector>

using namespace std;

//Prototype
void printVector(vector<int>);

/**
 * Main Function.
 */
int main() {
    vector<int> v;
    v.push_back(4);
    v.push_back(7);
    v.push_back(11);
    printVector(v);

    v.insert(v.begin(), 2);         //Inserts 2 at index 0
    printVector(v);

    v.insert(v.begin()+2, 99);      //Inserts 99 at index 2
    printVector(v);
}

/**
 * Simply prints the current values in the vector.
 */
void printVector(vector<int> v) {
    cout << "Current values in the vector: " << endl;
    for(int i = 0; i < v.size(); i++) {
	    cout << v[i] << " ";
	}
    cout << endl;
}