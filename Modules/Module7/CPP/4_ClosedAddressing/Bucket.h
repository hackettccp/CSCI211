/**
 * Singly Linked List ("Bucket") of KVP objects for a hash table
 * using chaining for collision resolution.
 */
#include<iostream>
#include "KVP.h"

using namespace std;

class Bucket {
    private:
        KVP *head;             //Pointer to the first KVP in the Bucket
        KVP *tail;             //Pointer to the last KVP in the Bucket

    public:
        //Constructor. Sets the head and tail to NULL as the Bucket is empty
        Bucket() {
            head = NULL;
            tail = NULL;
        }

        //Destructor. Deletes all KVPS in the Bucket
        ~Bucket() {
            KVP *start = head;
            KVP *temp = NULL;
            while(start != NULL) {
                temp = start;
                start = start->getNext();
                delete temp;
            }
        }

        //Adds a new KVP to the Bucket
        void add(KVP* newKVP) {
            if(head == NULL) {                              //Bucket is empty
                head = newKVP;                              //The new KVP is the head and tail
                tail = newKVP;
            }
            else {
                KVP *temp = head;                           //Start at head
                
                //While the end of the bucket hasn't been reached and
                //we don't find the new KVP's key already in use...
                while(temp != NULL && (temp->getKey() != newKVP->getKey())) {
                    temp = temp->getNext();                 //Get the next KVP in the bucket
                }
                
                if(temp == NULL) {                          //NEW KVP (Unique Key)
                    tail->setNext(newKVP);                  //Sets the current tail's next pointer to this new KVP
                    tail = tail->getNext();                 //Sets the bucket's tail to point to the new KVP (the new tail)
                }
                else {                                      //EXISTING KEY
                    temp->setValue(newKVP->getValue());     //Replaces the original value of the existing KVP with the new KVP's value
                }
            }
        }

        //Removes a KVP based on the supplied key
        //Returns false if the key didn't match any KVPs in the bucket
        //Returns true if a KVP was successfully deleted
        //(Doesn't need to return true/false but can be helpful to know if something was deleted or not)
        bool remove(int key) {
            if(head == NULL) {
                return false;                               //Bucket is empty; Nothing to remove
            }
            
            KVP *current = head;                            //Start at the head
            
            //Check if head is to be removed
            if(current->getKey() == key) {
                head = current->getNext();                 //Update head
                delete current;                            //Delete the old head
                return true;
            }

            //Loop until the tail is reached
            while(current != tail) {
                //Look at the next KVP's key to see if it matches
                if(current->getNext()->getKey() == key) {
                    if(current->getNext() == tail) {                        //Check if deleting the tail
                        delete current->getNext();                          //Delete the KVP
                        tail = current;                                     //Update the tail
                    }
                    else {
                        KVP *after = current->getNext()->getNext();         //Get the KVP two steps ahead
                        delete current->getNext();                          //Delete the KVP after current
                        current->setNext(after);                            //Update current's next to the KVP that was two steps ahead
                    }
                    return true;                                            //No need to continue since we found/removed the KVP
                }
                current = current->getNext();                               //Get the next KVP
            }
            
            return false;                                                   //Didn't find that key for any KVP in the bucket
        }

        //Retrieves the KVP with that key
        KVP* get(int key) {
            KVP *current = head;                                            //Start at head
  
            //Find KVP to be retrieved
            while(current != NULL && current->getKey() != key) {
                current = current->getNext();
            }

            //Return the KVP 
            //(Will return NULL if bucket is empty or end of bucket was reached)
            return current;
        }

};