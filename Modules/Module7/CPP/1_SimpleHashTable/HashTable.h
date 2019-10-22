/**
 * Demonstrates the basics of a hash table with no collision resolution.
 */
#include<iostream>
#include<stdexcept>

using namespace std;

class KVP {
    private:
        int key;                                //The KVP's key
        string value;                           //The KVP's value
    
    public:       
        //Constructor
        KVP(int k, string v) {
            key = k;
            value = v;
        }

        //Getter for key
        int getKey() {
            return key;
        }

        //Getter for value
        string getValue() {
            return value;
        }

        //Setter for value (no setter for key as it should never change)
        void setValue(string v) {
            value = v;
        }
};

class HashTable {
    private:
        KVP **map;                                                      //Array of KVPs (Really an array of pointers to KVPs)
        const int SIZE = 10;                                            //Size of the array
    
    public:
        //Constructor. Instantiates the array and sets each KVP pointer to NULL
        HashTable() {
            map = new KVP*[SIZE];
            for(int i=0; i<SIZE; i++) {
                map[i] = NULL;
            }
        }

        //Destructor. Deletes each KVP in the array, then deletes the array.
        ~HashTable() {
            for(int i = 0; i < SIZE; i++) {
                delete map[i];
            }
            delete[] map;
        }

        //Adds a KVP to the Hash Table
        void put(int key, string value) {
            int hashValue = key % SIZE;                                 //Calculates the hash value
            if(map[hashValue] == NULL) {
                KVP *temp = new KVP(key, value);                        //Create the new KVP and put it in the array
                map[hashValue] = temp;
            }
            else if(map[hashValue]->getKey() == key) {
                map[hashValue]->setValue(value);                        //Replace value of existing KVP
            }
            else {
                __throw_invalid_argument("Hash Collision");             //A different KVP was already hashed to that location
            }
        }

        //Gets the value associated with the supplied key
        string get(int key) {
            int hashValue = key % SIZE;                                 //Calculates the hash value
            if(map[hashValue] != NULL) {
                return map[hashValue]->getValue();                      //Return the value of the KVP
            }
            else {
                __throw_invalid_argument("KVP not found");              //KVP not found
            }
        }

        //Removes a KVP, if it exists
        //(Doesn't need to return true/false but can be helpful to know if something was deleted or not)
        bool remove(int key) {
            int hashValue = key % SIZE;                                 //Calculates the hash value
            if(map[hashValue] != NULL) {
                delete map[hashValue];                                  //Delete the KVP
                map[hashValue] = NULL;                                  //Set the array position to NULL
                return true;
            }
            else {
                return false;                                           //KVP not there; Nothing to delete
            }
        }
};