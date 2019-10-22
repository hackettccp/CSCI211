/**
 * Demonstrates a hash table with no collision resolution.
 * Keys = strings
 * Values = strings
 */
#include<iostream>
#include<stdexcept>
#include "HashTableSKeys.h"

using namespace std;

int main() {
    HashTable ht;
    ht.put("ABC1", "ABC Corporation");
    ht.put("XYZ1", "XYZ Associates");
    ht.put("DE01", "D&E Company");
    ht.put("FGH1", "FGH Inc.");

    cout << ht.get("XYZ1") << endl;
    cout << ht.get("ABC1") << endl;

    try {
        ht.put("ACB1", "ACB Inc.");
        cout << "Added KVP ACB1:ACB Inc." << endl;
    }
    catch(invalid_argument e) {
        cout << "Exception for key ACB1: " << e.what() << endl;
    }

    if(ht.remove("ABC1")) {
        cout << "KVP with key ABC1 removed." << endl;
    }
    else {
        cout << "KVP with key ABC1 NOT removed." << endl;
    }

    try {
        ht.get("ABC1");
    }
    catch(invalid_argument e) {
        cout << "Exception for key ABC1: " << e.what() << endl;
    }

    if(ht.remove("BBB1")) {
        cout << "KVP with key BBB1 removed." << endl;
    }
    else {
        cout << "KVP with key BBB1 NOT removed." << endl;
    }
}