/**
 * Demonstrates the basics of a hash table with linear probing (open addressing) collision resolution.
 * Has the ability to grow in size when the load reaches 90% and shrink when the load is less than 50%.
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
        int SIZE;                                                 //Initial size of the array
        int count;                                                  //Total number of KVPs
        bool skip = false;
    
    public:
        //Constructor. Instantiates the array and sets each KVP pointer to NULL
        HashTable() {
            SIZE = 127;
            count = 0;
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

        int getCount() {
            return count;
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
            int start = hashValue;                                              //Starts looking at the computed hash value/index
            while(map[hashValue] != NULL && 
                  map[hashValue]->getKey().compare(key) != 0) {
                hashValue = (hashValue + 1) % SIZE;
                if(start == hashValue) {
                    __throw_overflow_error("Table is full.");
                }
            }
            if(map[hashValue] != NULL) {
                delete map[hashValue];                                          //Delete the existing KVP, if it exists
            }
            map[hashValue] = new KVP(key, value);                               //Place the new KVP
            count++;
            if(!skip && count > SIZE * .90) {                                   //If more than 90% full
                rehash(false);                                                  //Grow the table
            }
        }

        //Gets the value associated with the supplied key
        string get(string key) {
            int hashValue = hashFunction(key);                                  //Calculates the hash value
            int start = hashValue;                                              //Starts looking at the computed hash value/index
            while(map[hashValue] != NULL && 
                  map[hashValue]->getKey().compare(key) != 0) {
                hashValue = (hashValue + 1) % SIZE;
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
            int start = hashValue;
            bool found = false;

            do {
                if(map[hashValue] != NULL && map[hashValue]->getKey().compare(key) == 0) {
                    found = true;
                    break;
                }
                hashValue = (hashValue + 1) % SIZE;

            } while (start != hashValue);

            if(map[hashValue] == NULL || found == false) {
                return false;                                                   //Nothing was at the computed hash value/index
            }
            else {
                delete map[hashValue];
                map[hashValue] = NULL;
                count--;
                if(SIZE > 127 && count < (SIZE * .50)) {                          //If more than 50% empty
                    rehash(true);                                               //Shrink the table
                }
                return true;
            }
        }

        //Resizes the table/map
        void rehash(bool shrink) {
            int oldSize = SIZE;                                                 //Get the old size
            KVP **temp = map;                                                   //Pointer to the existing map
            
            cout << "Count: " << count << endl;
            if(shrink) {
                SIZE -= (int)(SIZE * .25);                                       //Decrease by 25%
                if(SIZE < 127) {
                    SIZE = 127;
                }
                cout << "Old size: " << oldSize << endl;
                cout << "Resizing/Shrinking to: " << SIZE << endl;
            }
            else {
                SIZE = SIZE * 2;                                                //Double the size
                cout << "Old size: " << oldSize << endl;
                cout << "Resizing/Growing to: " << SIZE << endl;
            }
            
            map = new KVP*[SIZE];                                               //Create a new map/array of KVPs
            for(int i=0; i<SIZE; i++) {
                map[i] = NULL;                                                  //Set each position to NULL
            }

            count = 0;

            //Move the elements from the old map to the new one
            //The put function will rehash the KVPs into the new map
            skip = true;
            for(int i=0; i < oldSize; i++) {
                if(temp[i] != NULL) {
                    put(temp[i]->getKey(), temp[i]->getValue());          //Put the existing KVP into the new map
                    delete temp[i];                                             //Delete the old KVP
                }
            }
            skip = false;
            delete[] temp;                                                      //Delete the old map
        }
};