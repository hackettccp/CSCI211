/**
 *  Demonstrates how keys are distributed with hash functions.
 *  In these examples, all of the keys will be strings. 
 *  The program simply adds one at the index of the hashed key.
 */
#include<iostream>

using namespace std;

//Calculates a hash value for a string
//Multiplies by a prime number to reduce the number of factors.
int hashFunction(string key, int size) {
    int hash = 0;
    for(int i = 0; i < key.length(); i++) {
        //hash = hash + key[i];
        //hash = (17 * hash) + key[i];
        //hash = (31 * hash) + key[i];
        hash = (19 * hash) + key[i];
    }
    return hash % size;
}

//Keys generated: 03, 13, 23 ... 183, 193
//Array size: 10
void hashTest1() {
    int size = 10;
    int a[size] = {0};
    int h = hashFunction("DDD1", size);
    a[h]++;
    h = hashFunction("DCE1", size);
    a[h]++;
    h = hashFunction("DEC1", size);
    a[h]++;
    h = hashFunction("CED1", size);
    a[h]++;
    h = hashFunction("CDE1", size);
    a[h]++;
    h = hashFunction("ECD1", size);
    a[h]++;
    h = hashFunction("EDC1", size);
    a[h]++;
    h = hashFunction("DBF1", size);
    a[h]++;
    h = hashFunction("DFB1", size);
    a[h]++;
    h = hashFunction("BDF1", size);
    a[h]++;

    for(int i = 0; i < size; i++) {
        cout << "index " << i << " count = " << a[i] << endl;
    }
}

//Keys generated: 03, 13, 23 ... 183, 193
//Array size: 17
void hashTest2() {
    int size = 17;
    int a[size] = {0};
    int h = hashFunction("DDD1", size);
    a[h]++;
    h = hashFunction("DCE1", size);
    a[h]++;
    h = hashFunction("DEC1", size);
    a[h]++;
    h = hashFunction("CED1", size);
    a[h]++;
    h = hashFunction("CDE1", size);
    a[h]++;
    h = hashFunction("ECD1", size);
    a[h]++;
    h = hashFunction("EDC1", size);
    a[h]++;
    h = hashFunction("DBF1", size);
    a[h]++;
    h = hashFunction("DFB1", size);
    a[h]++;
    h = hashFunction("BDF1", size);
    a[h]++;

    for(int i = 0; i < size; i++) {
        cout << "index " << i << " count = " << a[i] << endl;
    }

}

int main() {
    hashTest1();
    cout << endl;
    hashTest2();
}