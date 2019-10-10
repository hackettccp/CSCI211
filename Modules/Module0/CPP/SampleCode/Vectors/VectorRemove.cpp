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
    v.push_back(99);
    v.push_back(32);
    v.push_back(19);
    printVector(v);

    v.erase(v.begin());             //Removes the value at index 0
    printVector(v);

    v.erase(v.begin() + 2);         //Removes the value at index 2
    printVector(v);

    v.pop_back();                   //Removes the last value in the vector
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