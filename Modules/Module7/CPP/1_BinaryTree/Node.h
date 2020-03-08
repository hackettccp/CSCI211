/**
 * Represents a node/vertex in a binary tree
 */
#include<iostream>

struct Node {
    int value;                                  //Value stored in the node
    Node *left;                                 //Pointer to the left child
    Node *right;                                //Pointer to the right child
    
    //Constructor
    Node(int v) {
        value = v;                              //Sets the value
        left = NULL;                            //No left child yet
        right = NULL;                           //No right child yet
    }
};