/**
 * Demonstrates the basics of a hash table with linear probing (open addressing) collision resolution.
 */
#include<iostream>
#include<stdexcept>

using namespace std;

class KVP {
    private:
        string key;                                //The KVP's key
        string value;                              //The KVP's value
    
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
            int hashValue = hashFunction(key);                                  //Calculates the hash value
            cout << "Putting " << key << ":" << value << " at hash/index " << hashValue << endl;
            int start = hashValue;                                              //Starts looking at the computed hash value/index
            while(map[hashValue] != NULL && 
                  map[hashValue]->getKey().compare(key) != 0) {
                hashValue = (hashValue + 1) % SIZE;
                cout << "Collision. New hash/index to try " << hashValue << endl;
                if(start == hashValue) {
                    __throw_overflow_error("Table is full.");
                }
            }
            if(map[hashValue] != NULL) {
                delete map[hashValue];                                          //Delete the existing KVP, if it exists
            }
            map[hashValue] = new KVP(key, value);                               //Place the new KVP
        }

        //Gets the value associated with the supplied key
        string get(string key) {
            int hashValue = hashFunction(key);                                  //Calculates the hash value
            cout << "Getting key " << key << " at hash/index " << hashValue << endl;
            int start = hashValue;                                              //Starts looking at the computed hash value/index
            while(map[hashValue] != NULL && 
                  map[hashValue]->getKey().compare(key) != 0) {
                hashValue = (hashValue + 1) % SIZE;
                cout << "Not there. New hash/index to try " << hashValue << endl;
                if(start == hashValue) {
                    __throw_overflow_error("Key not found.");
                }
            }
            if(map[hashValue] == NULL) {
                __throw_invalid_argument("Key not found.");
            }
            return map[hashValue]->getValue();
        }

        //Removes a KVP, if it exists
        //(Doesn't need to return true/false but can be helpful to know if something was deleted or not)
        bool remove(string key) {
            int hashValue = hashFunction(key);                                 //Calculates the hash value
            cout << "Getting key " << key << " at hash/index " << hashValue << endl;
            int start = hashValue;
            while(map[hashValue] != NULL && 
                  map[hashValue]->getKey().compare(key) != 0) {
                hashValue = (hashValue + 1) % SIZE;
                cout << "Not there. New hash/index to try " << hashValue << endl;
                if(start == hashValue) {
                   return false;                                                //Went through the entire table without finding it
                }
            }
            if(map[hashValue] == NULL) {
                return false;                                                   //Nothing was at the computed hash value/index
            }
            else {
                delete map[hashValue];
                return true;
            }
        }
};