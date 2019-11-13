/**
 * Max-Heap Implementation
 * Size = 16 (15 usable spaces in the array)
 */
#include<iostream>
#include<stdexcept>
#include "Node.h"

class MaxHeap {
    private:
        const int SIZE = 16;                                                    //Max size of the heap/array
        Node *array[16] = {NULL};                                               //The array to store the heap's nodes
        int nextAvail;                                                          //Keeps track of the next index to store a node

        /**
         * Calculates and returns the parent index of an index 
         */
        int getParentIndex(int index) {
            return index / 2;
        }

        /**
         * Calculates and returns the left child index of an index 
         */
        int getLeftChildIndex(int index) {
            return index * 2;
        }

        /**
         * Calculates and returns the right child index of an index 
         */
        int getRightChildIndex(int index) {
            return index * 2 + 1;
        }

        /**
         * Determines if a node has any children 
         */
        bool hasChildren(int index) {
            int left = getLeftChildIndex(index);
            int right = getRightChildIndex(index);
            if(left >= SIZE) {
                return false;                                               //Left child index is beyond the array
            }
            else if(array[left] == NULL && array[right] == NULL) {
                return false;                                               //Both left and right children are null
            }
            else {
                return true;                                                //At least one child that is not null
            }
        }

        /**
         * Swaps the values of two nodes 
         */
        void swap(Node *n1, Node *n2) {
            int t = n1->value;
            n1->value = n2->value;
            n2->value = t;
        }

        /**
         * Readjusts the values of nodes after the node at the top of the heap was removed 
         */
        void fixHeap() {
            int i = 1;                                                      //Starts at the root node
            int v = array[i]->value;                                        //Gets its value
            while(hasChildren(i)) {
                Node *left = array[getLeftChildIndex(i)];
                Node *right = array[getRightChildIndex(i)];
                if(left != NULL) {
                    //At least a left child
                    if(right != NULL) {
                        //Has a left and right child
                        if(left->value > right->value) {
                            //Left child is the larger of the two
                            if(v < left->value) {                           //Value is less than the left child
                                swap(array[i], left);                       //Swap the values
                                i = getLeftChildIndex(i);                   //Set i to the left child index (where we swapped the parent's value to)
                                continue;
                            }
                            else {
                                break;                                      //Value was greater than the left child (or right child for that matter); We're done promoting children
                            }
                        }
                        else {
                            //Right child is the larger of the two
                            if(v < right->value) {                          //Value is less than the right child
                                swap(array[i], right);                      //Swap the values
                                i = getRightChildIndex(i);                  //Set i to the right child index (where we swapped the parent's value to)
                                continue;
                            }
                            else {
                                break;                                      //Value was greater than the right child (or left child for that matter); We're done promoting children
                            }
                        }
                        
                    }
                    //No right child
                    else {
                        if(v < left->value) {                               //Value is less than the left child
                            swap(array[i], left);                           //Swap the values
                            i = getLeftChildIndex(i);                       //Set i to the left child index (where we swapped the parent's value to)
                            continue;
                        }
                        else {
                            break;                                          //Value was greater than the left child; We're done promoting children
                        }
                    }
                }
                //No children (If no left child, then there is definitely no right child)
                else {
                    break;
                }
            }
        }

        /**
         * Clears out the array 
         */
        void clear() {
            for(int i = 1; i < SIZE; i++) {
                if(array[i] != NULL) {
                    delete array[i];
                    array[i] = NULL;
                }
                else {
                    break;
                }
            }
        }

    public:
        //Constructor
        MaxHeap() {
            nextAvail = 1;
        }

        //Destructor
        ~MaxHeap() {
            clear();
            free(array);
        }

        /**
         * Adds a new node into the heap
         */
        void add(int value) {
            if(nextAvail > SIZE-1) {
                return;                                     //Heap is full
            }
            array[nextAvail] = new Node(value);             //Puts a new node (with the value set) at the next available index

            int p = getParentIndex(nextAvail);              //Calculates the new node's parent
            int i = nextAvail;                              //Starting at this index
            while(p >= 1) {
                if(array[p]->value < value) {               //Parent's value is smaller
                    swap(array[p], array[i]);               //Swap the values
                }
                i = p;                                      //Replace i (this index) with p (the parents index)
                p = getParentIndex(p);                      //Replace p with it's parent's index
            }
            nextAvail++;                                    //Finally, nextAvail is incremented
        }

        /**
         * Gets/removes the value at the top of the heap
         */
        int remove() {
            if(array[1] == NULL) {
                return 0;                                       //Heap is empty
            }
            int r = array[1]->value;                            //Gets the value at the top of the heap
            
            nextAvail--;                                        //Decrements next available index
            if(nextAvail == 1) {
                array[nextAvail] = NULL;                        //Heap is now empty
            }
            else {
                array[1]->value = array[nextAvail]->value;      //Replace the root node with the most recently added node
                array[nextAvail] = NULL;                        //Set that index to null
                fixHeap();                                      //Fix the heap so that new node value is demoted to the correct spot
            }
            return r;                                           //Finally, return the value that was originally at the top of the heap
        }

        /**
         * Determines if the heap is empty
         */
        bool isEmpty() {
            return nextAvail == 1 ? true : false;
        }

        /**
         * Prints the contents (values) of the heap's array
         */
        void dumpHeap() {
            for(int i = 1; i < SIZE; i++) {
                if(array[i] == NULL) {
                    cout << "NULL ";
                }
                else {
                    cout << array[i]->value << " ";
                }
                
            }
            cout << endl;
        }

        
};