/**
 *  Demonstrates how keys are distributed with hash functions.
 *  In these examples, they will be distributed evenly since there
 *  is one spot/index for every key. The program simply adds one at the index
 *  of the hashed key.
 */
#include<iostream>

using namespace std;

//Keys generated in the for loop: 0-19
//Array size: 10
void hashTest1() {
    int size = 10;
    int a[size] = {0};

    for(int i = 0; i < 20; i++) {
        int hash = i % size;
        a[hash]++;
    }
    for(int i = 0; i < size; i++) {
        cout << "index " << i << " count = " << a[i] << endl;
    }

}

//Keys generated in the for loop: 0-19
//Array size: 20
void hashTest2() {
    int size = 20;
    int a[size] = {0};

    for(int i = 0; i < 20; i++) {
        int hash = i % size;
        a[hash]++;
    }
    for(int i = 0; i < size; i++) {
        cout << "index " << i << " count = " << a[i] << endl;
    }

}

int main() {
    hashTest1();
    cout << endl;
    hashTest2();
}