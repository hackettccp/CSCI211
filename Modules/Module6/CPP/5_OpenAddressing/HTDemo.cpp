/**
 * Demonstrates a hash table with linear probing (closed hashing) collision resolution.
 * Keys = strings
 * Values = strings
 */
#include<iostream>
#include<stdexcept>
#include "HashTable.h"

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
        ht.put("CBA1", "CBA Inc.");
    }
    catch(invalid_argument e) {
        cout << "Exception for key CBA1: " << e.what() << endl;
    }

    try {
        ht.get("ABC1");
    }
    catch(invalid_argument e) {
        cout << "Exception for key ABC1: " << e.what() << endl;
    }

    try {
        ht.get("CBA1");
    }
    catch(invalid_argument e) {
        cout << "Exception for key CBA1: " << e.what() << endl;
    }

    try {
        ht.get("BBB1");
    }
    catch(invalid_argument e) {
        cout << "Exception for key BBB1: " << e.what() << endl;
    }

    try {
        ht.put("ABC2", "ABC Corporation");
        ht.put("XYZ2", "XYZ Associates");
        ht.put("DE02", "D&E Company");
        ht.put("FGH2", "FGH Inc.");
        ht.put("ABC3", "ABC Corporation");
        ht.put("XYZ3", "XYZ Associates");
        ht.put("DE03", "D&E Company");
        ht.put("FGH3", "FGH Inc.");
    }
    catch(overflow_error e) {
        cout << "Exception: " << e.what() << endl;
    }

}