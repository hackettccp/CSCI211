/**
 * Demonstrates a hash table with no collision resolution.
 * Keys = ints
 * Values = strings
 */
#include<iostream>
#include<stdexcept>
#include "HashTable.h"

using namespace std;

int main() {
    HashTable ht;
    ht.put(3456, "ABC Corporation");        //Placed in index 6 (3456 % 10 = 6)
    ht.put(1313, "XYZ Associates");         //Placed in index 3
    ht.put(3765, "D&E Company");            //Placed in index 5

    cout << ht.get(1313) << endl;           //Gets the value for this key (KVP in index 3)
    cout << ht.get(3456) << endl;           //Gets the value for this key (KVP in index 6)

    try {
        ht.put(5513, "FGH Inc.");           //Tried to place in index 3, causing a collision
    }
    catch(invalid_argument e) {
        cout << "Exception for key 5513: " << e.what() << endl;
    }

    if(ht.remove(3456)) {
        cout << "KVP with key 3456 removed." << endl;
    }
    else {
        cout << "KVP with key 3456 NOT removed." << endl;
    }

    try {
        ht.get(3456);                       //Was just removed
    }
    catch(invalid_argument e) {
        cout << "Exception for key 3456: " << e.what() << endl;
    }

    if(ht.remove(9999)) {
        cout << "KVP with key 9999 removed." << endl;
    }
    else {
        cout << "KVP with key 9999 NOT removed." << endl;
    }
}