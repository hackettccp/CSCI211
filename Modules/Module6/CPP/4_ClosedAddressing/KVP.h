/**
 * A Key-Value Pair object
 * Contains the object's key, value, and 
 * a pointer to the next object in the bucket.
 * 
 */
#include<iostream>

using namespace std;

class KVP {
    private:
        int key;                    //The KVP's key
        string value;               //The KVP's value
        KVP *next;                  //The next KVP in the bucket
    
    public:
        //Constructor
        KVP(int k, string v) {
            key = k;
            value = v;
            next = NULL;
        }

        //Getters
        int getKey() {
            return key;
        }
        
        string getValue() {
            return value;
        }

        KVP* getNext() {
            return next;
        }
        
        //Setters (Key will never change so no setter for it)
        void setValue(string v) {
            value = v;
        }

        void setNext(KVP *e) {
            next = e;
        }
};