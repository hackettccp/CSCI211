/**
 * A node in a Heap
 */
#include<iostream>
#include<stdexcept>

using namespace std;

//Represents a node/vertex in a heap
struct Node {
    int value;                                  //Value stored in the node

    Node(int v) {
        value = v;
    }
};