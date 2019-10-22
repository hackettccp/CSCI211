/**
 * Demonstrates a hash table that uses chaining (open hashing) to resolve collisions.
 */
#include<iostream>
#include<stdexcept>
#include "HashTableChaining.h"

using namespace std;

int main() {
    HashTable ht;
    ht.put(3456, "ABC Corporation");        //Placed in Bucket 56 (3456 % 100 = 56)
    ht.put(1313, "XYZ Associates");         //Placed in Bucket 13
    ht.put(3765, "D&E Company");            //Placed in Bucket 65
    ht.put(5513, "FGH Inc.");               //Placed in Bucket 13

    cout << ht.get(1313) << endl;           //Gets the value for this key (KVP in bucket 13)
    cout << ht.get(5513) << endl;           //Gets the value for this key (KVP in bucket 13)

    ht.put(1313, "WXYZ Associates");        //Will replace the value of existing key 1313
    cout << ht.get(1313) << endl;           //Gets the value for this key (KVP in bucket 13)

    try {
        cout << ht.get(1234) << endl;       //Tries to get a value for a key that does not exist
    }
    catch(invalid_argument e) {
        cout << "Exception for key 1234: " << e.what() << endl;
    }

    if(ht.remove(3456)) {
        cout << "KVP with key 3456 removed." << endl;
    }
    else {
        cout << "KVP with key 3456 NOT removed." << endl;
    }

    if(ht.remove(9999)) {
        cout << "KVP with key 9999 removed." << endl;
    }
    else {
        cout << "KVP with key 9999 NOT removed." << endl;
    }
}