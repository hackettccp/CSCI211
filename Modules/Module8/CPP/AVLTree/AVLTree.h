/**
 * AVL Tree Implementation
 */
#include<iostream>
#include<stdexcept>
#include "Traversal.h"

class AVLTree {
    private:
        Node *root;     //Pointer to the root of the tree. It's private, hence all of the private functions needed.

        //Finds the max of two values.
        //Used when determining the height of a node
        int max(int value1, int value2) {
            return value1 > value2 ? value1 : value2;
        }

        //Returns -1 if the node is null (signifying an absent child), otherwise returns the node's height
        //(Helps to prevent null pointer exceptions for absent children)
        int height(Node* n) {
            return n == NULL ? -1 : n->height;
        }

        //Returns -1 if the node is null (signifying an absent child), otherwise returns the difference between the childrens' heights
        int balanceFactor(Node* n) {
            return n == NULL ? -1 : height(n->left) - height(n->right); 
        }

        //Rotates a node's left subtree with itself
        void rotateRight(Node* n) {
            Node *t1 = n->left;                                             //Temporary pointer to the node's left subtree
            Node *t2 = t1->right;                                           //Temporary pointer to the node's left subtree's right subtree

            t1->right = n;                                                  //Sets the left subtree's right pointer to the node
            n->left = NULL;                                                 //Sets the node's left subtree to null (we still have it in t1)

            
            if(n->parent != NULL) {                                         //If the original node had a parent
                if(n == n->parent->left) {                                  //If it was the left child
                    n->parent->left = t1;                                   //The original left subtree is now its left child
                }
                if(n == n->parent->right) {                                 //If it was the right child
                    n->parent->right = t1;                                  //The original left subtree is now its right child
                }
            }

            t1->parent = n->parent;                                         //The original left subtree's parent is now the original node's parent
            n->parent = t1;                                                 //The original node's parent is now the original left subtree
            n->left = t2;                                                   //The left child of the original node is now its old left subtree's right subtree
            if(t2 != NULL) {
                t2->parent = n;                                             //If it wasn't null, its parent now the original node
            }
            
            if(root == n) {
                root = t1;                                                  //If this node was the root, update the root pointer
            }

            n->height = max(height(n->left), height(n->right)) + 1;         //Calculate the node's new height
            t1->height = max(height(t1->left), height(t1->right)) + 1;      //Calculate the temporary pointer's (original left subtree's) new height
        }

        //Rotates a node's right subtree with itself
        void rotateLeft(Node* n) {
            Node *t1 = n->right;                                            //Temporary pointer to the node's right subtree
            Node *t2 = t1->left;                                            //Temporary pointer to the node's right subtree's left subtree

            t1->left = n;                                                   //Sets the right subtree's left pointer to the node
            n->right = NULL;                                                //Sets the node's right subtree to null (we still have it in t1)

            
            if(n->parent != NULL) {                                         //If the original node had a parent
                if(n == n->parent->left) {                                  //If it was the left child
                    n->parent->left = t1;                                   //The original right subtree is now its left child
                }
                if(n == n->parent->right) {                                 //If it was the right child
                    n->parent->right = t1;                                  //The original right subtree is now its right child
                }
            }
            
            t1->parent = n->parent;                                          //The original right subtree's parent is now the original node's parent
            n->parent = t1;                                                  //The original node's parent is now the original right subtree
            n->right = t2;                                                   //The right child of the original node is now its old right subtree's left subtree
            if(t2 != NULL) {
                t2->parent = n;                                              //If it wasn't null, its parent now the original node
            }
            
            if(root == n) {
                root = t1;                                                   //If this node was the root, update the root pointer
            }

            n->height = max(height(n->left), height(n->right)) + 1;         //Calculate the node's new height
            t1->height = max(height(t1->left), height(t1->right)) + 1;      //Calculate the temporary pointer's (original right subtree's) new height
        }

        //Private function to recursively insert a new node
        //The first if-elseif-else is the same as the BST
        void insert(Node *n, int value) {
            if(value > n->value) {                                          //Value is greater than the current node's value; Needs to be inserted down the right branch
                if(n->right != NULL) {                                      //A right child is present
                    insert(n->right, value);                                //Use recursion to insert down the right side
                }
                else {
                    n->right = new Node(value, n);                          //No right child. Add this new node there.
                }
            }
            else if(value < n->value) {                                     //Value is less than the current node's value; Needs to be inserted down the left branch
                if(n->left != NULL) {                                       //A left child is present
                    insert(n->left, value);                                 //Use recursion to insert down the left side
                }
                else {
                    n->left = new Node(value, n);                           //No left child. Add this new node there
                }
            }
            else {
                __throw_runtime_error("Value already exists in the BST");   //Can't have duplicate values in the BST
            }

            n->height = 1 + max(height(n->left), height(n->right));                 //Adjusts the height for the node

            int b = balanceFactor(n);                                               //Calculates the balance factor

            if((b > 1 || b < -1) && height(n->left) > height(n->right)) {
                rotateRight(n);                                                     //Node needs a right rotation
            }
            else if((b > 1 || b < -1) && height(n->right) > height(n->left)) {
                rotateLeft(n);                                                      //Node needs a left rotation
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
            else {                                                  //Found the value
                if(n->left == NULL && n->right == NULL) {           //NO children
                    if(n == n->parent->right) {
                        n->parent->right = NULL;                    //If this node is its parent's right child
                    }
                    else if(n == n->parent->left) {
                        n->parent->left = NULL;                     //If this node is its parent's left child
                    }
                    delete n;                                       //Delete the node
                    n = NULL;
                }
                else if(n->left == NULL && n->right != NULL) {      //Has a RIGHT child, no NO LEFT child
                    Node *t = n->right;
                    if(n->parent != NULL) {
                        if(n->parent->left == n) {
                            n->parent->left = t;
                        }
                        else if(n->parent->right == n) {
                            n->parent->right = t;
                        }
                    }
                    t->parent = n->parent;
                    delete n;
                    n = t;
                }
                else if(n->right == NULL && n->left != NULL) {      //Has a LEFT child, but NO RIGHT child
                    Node *t = n->left;
                    if(n->parent != NULL) {
                        if(n->parent->left == n) {
                            n->parent->left = t;
                        }
                        else if(n->parent->right == n) {
                            n->parent->right = t;
                        }
                    }
                    t->parent = n->parent;
                    delete n;
                    n = t;
                }
                else {                                              //Has a LEFT AND RIGHT child
                    Node *t = findMin(n->right);                    //Find the successor (smallest value down the right branch)
                    n->value = t->value;                            //Copy the successor's value
                    n->right = remove(n->right, t->value);          //Recursively update the right branch to find and delete the successor
                }
            }

            if(n != NULL) {
                int b = balanceFactor(n);                                               //Calculates the balance factor
                if((b > 1 || b < -1) && height(n->left) > height(n->right)) {
                    rotateRight(n);                                                     //Node needs a right rotation
                }
                else if((b > 1 || b < -1) && height(n->right) > height(n->left)) {
                    rotateLeft(n);                                                      //Node needs a left rotation
                }
            }

            return n;                                               //Return the n pointer
        }

        //Private function to recursively search the tree
        //No different from a regular BST
        Node* search(Node *n, int value) {
            if(value > n->value) {                              //Value to find is greater than the current node's value; Need to search down the right branch
                if(n->right != NULL) {                          //A right child is present
                    return search(n->right, value);             //Use recursion to search down the right side
                }
                else {
                    return NULL;                                //Value does not exist in the tree
                }
            }
            else if(value < n->value) {                         //Value to find is less than the current node's value; Need to search down the left branch
                if(n->left != NULL) {                           //A left child is present
                    return search(n->left, value);              //Use recursion to search down the left side
                }
                else {
                    return NULL;                                //Value does not exist in the tree
                }
            }
            else {
                return n;                                       //Value found
            }
        }

        //Private function to recursively find the smallest value in the tree
        //(The left-most node)
        //No different from a regular BST
        Node* findMin(Node *n) {
            if(n->left == NULL) {                               //No left child
                return n;                                       //Return this node
            }
            else {
                return findMin(n->left);                        //Recursively go down the left side
            }
        }

        //Private function to recursively find the largest value in the tree
        //(The right-most node)
        //No different from a regular BST
        Node* findMax(Node *n) {
            if(n->right == NULL) {                              //No right child
                return n;                                       //Return this node
            }
            else {
                return findMax(n->right);                       //Recursively go down the right side
            }
        }

        

        //Performs a recursive postorder traversal to clear the tree
        //No different from a regular BST
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
        AVLTree() {
            root = NULL;
        }

        //Destructor
        ~AVLTree() {
            clear(root);
        }

        //Traverse the tree and print the value of each node
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
        //Inserts a new node into the tree
        void insert(int value) {
            if(root == NULL) {
                root = new Node(value, NULL);                       //Tree is empty. Create a new root node.
            }
            else {
                insert(root, value);                                //Call the class's private insert function
            }
        }

        //Public search function
        //Returns true if it finds the value in the tree
        bool search(int value) {
            if(root == NULL) {
                return false;                                       //Tree is empty, no need to search
            }
            else {
                return search(root, value);                         //Call the class's private search function
            }
        }

        //Public findMin function
        //Returns the smallest value in the tree
        int findMin() {
            if(root == NULL) {
                __throw_runtime_error("Tree is empty.");             //Tree is empty
            }                             
            return findMin(root)->value;                            //Call the class's private findMin function to get the node with the smallest value
        }

        //Public findMax function
        //Returns the largest value in the tree
        int findMax() {
            if(root == NULL) {
                __throw_runtime_error("Tree is empty.");             //Tree is empty
            }                             
            return findMax(root)->value;                            //Call the class's private findMax function to get the node with the largest value
        }

        //Public remove function
        //Removes a node from the tree
        void remove(int value) {
            remove(root, value);                                    //Call the class's private remove function, starting the search with the root node
        }
};