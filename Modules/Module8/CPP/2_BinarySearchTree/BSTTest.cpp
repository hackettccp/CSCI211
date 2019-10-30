/**
 * Demonstrates using a BST
 */
#include<iostream>
#include<stdexcept>
#include "BST.h"

int main() {
    BST bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(19);
    bst.insert(2);
    bst.insert(7);
    bst.insert(15);

    bst.traverse(1);
    bst.traverse(2);
    bst.traverse(3);

    if(bst.search(15)) {
        cout << "15 is in the BST" << endl;
    }
    else {
        cout << "15 is not in the BST" << endl;
    }

    if(bst.search(2)) {
        cout << "2 is in the BST" << endl;
    }
    else {
        cout << "2 is not in the BST" << endl;
    }

    if(bst.search(16)) {
        cout << "16 is in the BST" << endl;
    }
    else {
        cout << "16 is not in the BST" << endl;
    }



    cout << "The smallest value is " << bst.findMin() << endl;
    cout << "The largest value is " << bst.findMax() << endl;




    bst.remove(5);
    bst.remove(7);
    bst.remove(10);
    bst.remove(15);
    
    bst.traverse(1);
    bst.traverse(2);
    bst.traverse(3);

}