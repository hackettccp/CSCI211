/**
 *  Demonstrates how keys are distributed with hash functions.
 *  In these examples, all of the keys will end with 3. 
 *  The program simply adds one at the index of the hashed key.
 */
#include<iostream>

using namespace std;

//Keys generated: 03, 13, 23 ... 183, 193
//Array size: 10
void hashTest1() {
    int size = 10;
    int a[size] = {0};

    for(int i = 0; i < 20; i++) {
        int value = stoi(to_string(i) + to_string(3));
        int hash = value % size;
        a[hash]++;
    }
    for(int i = 0; i < size; i++) {
        cout << "index " << i << " count = " << a[i] << endl;
    }
}

//Keys generated: 03, 13, 23 ... 183, 193
//Array size: 17
void hashTest2() {
    int size = 17;
    int a[size] = {0};

    for(int i = 0; i < 20; i++) {
        int value = stoi(to_string(i) + to_string(3));
        int hash = value % size;
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