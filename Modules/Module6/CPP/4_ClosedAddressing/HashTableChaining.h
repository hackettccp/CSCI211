/**
 * A hash table that uses chaining (closed addressing) to resolve collisions.
 * Implemented with an array of singly linked lists.
 * Size of Array = 100
 */
#include<iostream>
#include<stdexcept>
#include "Bucket.h"

using namespace std;

class HashTable {
    private:
        Bucket **map;                                               //Array of Buckets (Really an array of pointers to Buckets)
        const int SIZE = 100;                                       //Size of the array
    
    public:
        //Constructor. Instantiates the array and sets each Bucket pointer to NULL
        HashTable() {
            map = new Bucket*[SIZE];
            for(int i = 0; i < SIZE; i++) {
                map[i] = NULL;
            }
        }

        //Destructor. Deletes each Bucket in the array.
        ~HashTable() {
            for(int i = 0; i < SIZE; i++) {
                if(map[i] != NULL) {
                    delete map[i];
                }
            }
            delete[] map;
        }

        //Gets the value associated with the supplied key
        string get(int key) {
            int hashValue = key % SIZE;                         //Calculate the hash value (array index)
            if(map[hashValue] == NULL) {
                __throw_invalid_argument("Key not found");      //No bucket at that index
            }
            KVP *e = map[hashValue]->get(key);                  //Try to get the KVP in the Bucket (if it exists)
            if(e == NULL) {
                __throw_invalid_argument("Key not found");      //KVP not found
            }
            else {
                return e->getValue();                           //KVP found; returns the KVP's value
            }
        }

        //Adds a KVP to the Hash Table
        void put(int key, string value) {
            int hashValue = key % SIZE;                         //Calculate the hash value
            KVP *newEntry = new KVP(key, value);                //Create the new KVP
            
            if(map[hashValue] == NULL) {
                Bucket *newList = new Bucket;                   //Create a new Bucket first, if needed
                map[hashValue] = newList;                       
            }
            
            map[hashValue]->add(newEntry);                      //Add the KVP to the Bucket
        }

        //Removes a KVP, if it exists
        //(Doesn't need to return true/false but can be helpful to know if something was deleted or not)
        bool remove(int key) {
            int hashValue = key % SIZE;                         //Calculate the hash value
            if(map[hashValue] != NULL) {
                return map[hashValue]->remove(key);              //Try to delete the KVP, if it exists
            }
            return false;                                       //Bucket was empty/non-existant; Nothing to remove
        }
};