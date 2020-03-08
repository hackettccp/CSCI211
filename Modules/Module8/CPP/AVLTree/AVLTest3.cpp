/**
 * Demonstrates using an AVL Tree
 */
#include<iostream>
#include<stdexcept>
#include "AVLTree.h"

int main() {
    AVLTree avl;

    avl.insert(2);
    avl.insert(5);
    avl.insert(7);
    avl.insert(10);
    avl.insert(15);
    avl.insert(19);

    avl.traverse(1);
    avl.traverse(2);
    avl.traverse(3);


    avl.remove(10);
    avl.traverse(1);
    avl.remove(19);
    avl.traverse(1);
    avl.remove(2);
    
    avl.traverse(1);
    avl.traverse(2);
    avl.traverse(3);

}