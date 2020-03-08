/**
 * BST Implementation
 */
#include<iostream>
#include<stdexcept>
#include "Traversal.h"

class BST {
    private:
        Node *root;     //Pointer to the root of the BST. It's private, hence all of the private functions needed.

        //Private function to recursively insert a new node
        void insert(Node *n, int value) {
            if(value > n->value) {                              //Value is greater than the current node's value; Needs to be inserted down the right branch
                if(n->right != NULL) {                          //A right child is present
                    insert(n->right, value);                        //Use recursion to insert down the right side
                }
                else {
                    n->right = new Node(value, n);                  //No right child. Add this new node there.
                }
            }
            else if(value < n->value) {                         //Value is less than the current node's value; Needs to be inserted down the left branch
                if(n->left != NULL) {                           //A left child is present
                    insert(n->left, value);                         //Use recursion to insert down the left side
                }
                else {
                    n->left = new Node(value, n);                   //No left child. Add this new node there
                }
            }
            else {
                __throw_runtime_error("Value already exists in the BST");   //Can't have duplicate values in the BST
            }
        }

        //Private function to recursively search the BST
        Node* search(Node *n, int value) {
            if(value > n->value) {                              //Value to find is greater than the current node's value; Need to search down the right branch
                if(n->right != NULL) {                          //A right child is present
                    return search(n->right, value);                 //Use recursion to search down the right side
                }
                else {
                    return NULL;                                    //Value does not exist in the BST
                }
            }
            else if(value < n->value) {                         //Value to find is less than the current node's value; Need to search down the left branch
                if(n->left != NULL) {                           //A left child is present
                    return search(n->left, value);                  //Use recursion to search down the left side
                }
                else {
                    return NULL;                                    //Value does not exist in the BST
                }
            }
            else {
                return n;                                       //Value found
            }
        }

        //Private function to recursively find the smallest value in the BST
        //(The left-most node)
        Node* findMin(Node *n) {
            if(n->left == NULL) {                               //No left child
                return n;                                           //Return this node
            }
            else {
                return findMin(n->left);                        //Recursively go down the left side
            }
        }

        //Private function to recursively find the largest value in the BST
        //(The right-most node)
        Node* findMax(Node *n) {
            if(n->right == NULL) {                              //No right child
                return n;                                           //Return this node
            }
            else {
                return findMax(n->right);                       //Recursively go down the right side
            }
        }

        //Removes a node from the BST and (if necessary) replaces it with a successor
        Node* remove(Node *n, int v) {
            if(n == NULL) {
               return n;                                            //Nothing to remove
            }
            else if(v < n->value) {                                 //Go down left branch
                n->left = remove(n->left, v);
            }
            else if(v > n->value) {                                 //Go down right branch
                n->right = remove(n->right, v);
            }
            else {                                                  //Found the value to remove
                if(n->left == NULL && n->right == NULL) {           //NO CHILDREN
                    if(n == n->parent->right) {
                        n->parent->right = NULL;                        //This is(was) its parent's right child
                    }
                    else if(n == n->parent->left) {
                        n->parent->left = NULL;                         //This is(was) its parent's left child
                    }
                    delete n;                                           //Delete the node
                    n = NULL;                                           //Set the pointer to null
                }
                else if(n->left == NULL && n->right != NULL) {      //RIGHT child, NO LEFT child
                    Node *t = n->right;
                    delete n;
                    return t;
                }
                else if(n->right == NULL && n->left != NULL) {      //LEFT child, NO RIGHT child
                    Node *t = n->left;
                    delete n;
                    return t;
                }
                else {                                              //Has a LEFT AND RIGHT child
                    Node *t = findMin(n->right);                        //Find the successor (smallest value down the right branch)
                    n->value = t->value;                                //Copy the successor's value
                    n->right = remove(n->right, t->value);              //Update the right branch to find and delete the successor
                }
            }
            return n;                                               //Return the n pointer
        }

        //Performs a recursive postorder traversal to clear the BST
        void clear(Node *n) {
            if(n == NULL) {
                return;
            }
            clear(n->left);
            clear(n->right);
            delete n;
        }

    public:
        //Constructor
        BST() {
            root = NULL;
        }

        //Destructor
        ~BST() {
            clear(root);
        }

        //Traverse the BST and print the value of each node
        //(Functions are from Traversal.h)
        //Arguments:
        //1 = Inorder Traversal
        //2 = Preorder Traversal
        //3 = Postorder Traversal
        void traverse(int type) {
            if(type == 1) {
                cout << "Inorder Traversal/\"Infix\": ";
                inorder(root);
            }
            else if(type == 2) {
                cout << "Preorder Traversal/\"Prefix\": ";
                preorder(root);
            }
            else if(type == 3) {
                cout << "Postorder Traversal/\"Postfix\": ";
                postorder(root);
            }
            cout << endl;
        }

        //Public insert function.
        //Inserts a new node into the BST
        void insert(int value) {
            if(root == NULL) {
                root = new Node(value, NULL);                       //BST is empty. Create a new root node.
            }
            else {
                insert(root, value);                                //Call the class's private insert function
            }
        }

        //Public search function
        //Returns true if it finds the value in the BST
        bool search(int value) {
            if(root == NULL) {
                return false;                                       //BST is empty, no need to search
            }
            else {
                return search(root, value);                         //Call the class's private search function
            }
        }

        //Public findMin function
        //Returns the smallest value in the BST
        int findMin() {
            if(root == NULL) {
                __throw_runtime_error("BST is empty.");             //BST is empty
            }                             
            return findMin(root)->value;                            //Call the class's private findMin function to get the node with the smallest value
        }

        //Public findMax function
        //Returns the largest value in the BST
        int findMax() {
            if(root == NULL) {
                __throw_runtime_error("BST is empty.");             //BST is empty
            }                             
            return findMax(root)->value;                            //Call the class's private findMax function to get the node with the largest value
        }

        //Public remove function
        //Removes a node from the BST
        void remove(int value) {
            root = remove(root, value);                             //Call the class's private remove function, starting the search with the root node
        }
};