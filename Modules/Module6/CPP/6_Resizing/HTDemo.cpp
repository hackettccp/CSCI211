/**
 * Demonstrates a hash table with linear probing (closed hashing) collision resolution.
 * The hash table is able to increase its size when 90% of the table is used and
 * decrease its size 25% if less than half of its space is used.
 * Keys = strings
 * Values = strings
 */
#include<iostream>
#include<stdexcept>
#include "HashTable.h"

using namespace std;

int main() {
    HashTable ht;
    cout << "Adding 200 KVPs" << endl;
    for(int i = 1; i < 201; i++) {
        ht.put(to_string(i), "");
    }
    cout << "Total KVPS = " << ht.getCount() << endl;

    cout << "Adding 200 more KVPs" << endl;
    for(int i = 201; i < 401; i++) {
        ht.put(to_string(i), "");
    }
    cout << "Total KVPS = " << ht.getCount() << endl;
    
    cout << "Adding 200 more KVPs" << endl;
    for(int i = 401; i < 601; i++) {
        ht.put(to_string(i), "");
    }
    cout << "Total KVPS = " << ht.getCount() << endl << endl;



    cout << "Removing 200 KVPs" << endl;
    for(int i = 401; i < 601; i++) {
        ht.remove(to_string(i));
    }
    cout << "Total KVPS = " << ht.getCount() << endl;

    cout << "Removing 200 more KVPs" << endl;
    for(int i = 201; i < 401; i++) {
        ht.remove(to_string(i));
    }
    cout << "Total KVPS = " << ht.getCount() << endl;

    cout << "Removing 200 more KVPs" << endl;
    for(int i = 1; i < 201; i++) {
        ht.remove(to_string(i));
    }
    cout << "Total KVPS = " << ht.getCount() << endl << endl;
  

    cout << "Done" << endl;

}