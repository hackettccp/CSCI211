/**
 * A node in a AVL Tree
 */
#include<iostream>
#include<stdexcept>

using namespace std;

//Represents a node/vertex in a binary tree
struct Node {
    int value;                                  //Value stored in the node
    int height;                                 //The height/level of this node
    Node *left;                                 //Pointer to the left child
    Node *right;                                //Pointer to the right child
    Node *parent;                               //Pointer to the node's parent
    
    //Constructor
    Node(int v, Node *p) {
        value = v;                              //Sets the value
        left = NULL;                            //No left child yet
        right = NULL;                           //No right child yet
        parent = p;                             //Sets the node's parent
        height = 0;                             //Sets the node's height to one
    }
};