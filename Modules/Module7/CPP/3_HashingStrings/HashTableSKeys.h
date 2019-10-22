/**
 * A basic hash table with no collision resolution.
 * KVPs are string keys and string values
 */
#include<iostream>
#include<stdexcept>

using namespace std;

class KVP {
    private:
        string key;                             //The KVP's key
        string value;                           //The KVP's value
    
    public:       
        //Constructor
        KVP(string k, string v) {
            key = k;
            value = v;
        }

        //Getter for key
        string getKey() {
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
        const int SIZE = 127;                                           //Size of the array
    
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

        //Calculates a hash value for a string
        //Multiplies by a prime number to reduce the number of factors.
        int hashFunction(string key) {
            int hash = 0;
            for(int i = 0; i < key.length(); i++) {
                hash = (17 * hash) + key[i];
            }
            return hash % SIZE;
        }

        //Adds a KVP to the Hash Table
        void put(string key, string value) {
            int hashValue = hashFunction(key);                          //Calculates the hash value
            if(map[hashValue] == NULL) {
                KVP *temp = new KVP(key, value);                        //Create the new KVP and put it in the array
                map[hashValue] = temp;
            }
            else if(map[hashValue]->getKey().compare(key) == 0) {
                map[hashValue]->setValue(value);                        //Replace value of existing KVP
            }
            else {
                __throw_invalid_argument("Hash Collision");             //A different KVP was already hashed to that location
            }
        }

        //Gets the value associated with the supplied key
        string get(string key) {
            int hashValue = hashFunction(key);                          //Calculates the hash value
            if(map[hashValue] != NULL) {
                return map[hashValue]->getValue();                      //Return the value of the KVP
            }
            else {
                __throw_invalid_argument("KVP not found");              //KVP not found
            }
        }

        //Removes a KVP, if it exists
        //(Doesn't need to return true/false but can be helpful to know if something was deleted or not)
        bool remove(string key) {
            int hashValue = hashFunction(key);                          //Calculates the hash value
            if(map[hashValue] != NULL) {
                if(map[hashValue]->getKey().compare(key) == 0) {
                    delete map[hashValue];                                  //Delete the KVP
                    map[hashValue] = NULL;                                  //Set the array position to NULL
                    return true;
                }
            }
            return false;                                           //KVP not there; Nothing to delete
        }
};