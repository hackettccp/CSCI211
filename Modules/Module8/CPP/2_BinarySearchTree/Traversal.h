/**
 * Collection of functions to traverse a binary tree
 */
#include "Node.h"

//(Recursively) Performs an inorder traversal of the tree
void inorder(Node *n) {
    if(n == NULL) {
        return;
    }
    inorder(n->left);
    cout << n->value << " ";
    inorder(n->right);
}

//(Recursively) Performs a postorder traversal of the tree
void postorder(Node *n) {
    if(n == NULL) {
        return;
    }
    postorder(n->left);
    postorder(n->right);
    cout << n->value << " ";
}

//(Recursively) Performs a preorder traversal of the tree
void preorder(Node *n) {
    if(n == NULL) {
        return;
    }
    cout << n->value << " ";
    preorder(n->left);
    preorder(n->right);
}