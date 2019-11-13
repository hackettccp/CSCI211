/**
 * Demonstrates using a Red-Black Tree
 */
#include<iostream>
#include<stdexcept>
#include "RBTree.h"

int main() {
    RBTree rbt;

    rbt.insert(19);
    rbt.insert(5);
    rbt.insert(2);
    rbt.insert(7);
    rbt.insert(15);
    rbt.insert(10);
    rbt.traverse(2);

    rbt.remove(19);
    rbt.traverse(2);
    
    rbt.remove(5);
    rbt.traverse(2);
    
    rbt.remove(2);
    rbt.traverse(2);

    rbt.remove(7);
    rbt.traverse(2);
    
    rbt.remove(15);
    rbt.traverse(2);

}