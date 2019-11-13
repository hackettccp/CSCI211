/**
 * Red Black Tree Implementation
 */
#include<iostream>
#include<stdexcept>
#include "Traversal.h"

class RBTree {
    private:
        Node *root;     //Pointer to the root of the tree. It's private, hence all of the private functions needed.

        //Private function to recursively find the smallest value in the BST
        //(The left-most node)
        Node* findMin(Node *n) {
            if(n->left == NULL) {                               //No left child
                return n;                                       //Return this node
            }
            else {
                return findMin(n->left);                        //Recursively go down the left side
            }
        }

        //Rotates a node's left subtree with itself
        void rotateRight(Node* n) {
            Node *temp = n->left;                               //Get the left subtree
  
            n->left = temp->right;                              //Set the left subtree to the temp node's right subtree
  
            if (n->left != NULL) {                              //New left subtree not empty
                n->left->parent = n;                            //This node is now the left node's parent
            }
  
            temp->parent = n->parent;                           //Copy the parent
  
            if (n->parent == NULL) {                            //No parent == root
               root = temp;
            }
            else if (n == n->parent->left) {                    //Node is its parent's left child
                n->parent->left = temp;                         //Change it to the temp node (old left subtree)
            }
            else {                                              //Node is its parent's right child
                n->parent->right = temp;                        //Change it to the temp node (old left subtree)
            }
  
            temp->right = n;                                    //The original node is now the temporary nodes right child
            n->parent = temp;                                   //The temporary node is now the original node's parent
        }

        //Rotates a node's right subtree with itself
        void rotateLeft(Node* n) {
            Node *temp = n->right;                              //Get the right subtree

            n->right = temp->left;                              //Set the right subtree to the temp node's left subtree
  
            if(n->right != NULL) {                              //New right subtree not empty
                n->right->parent = n;                           //This node is now the right node's parent
            }
  
            temp->parent = n->parent;                           //Copy the parent
  
            if(n->parent == NULL) {                             //No parent == root
                root = temp;
            }
            else if(n == n->parent->left) {                     //Node is its parent's left child
                n->parent->left = temp;                         //Change it to the temp node (old right subtree)
            }
            else {                                              //Node is its parent's right child
                n->parent->right = temp;                        //Change it to the temp node (old right subtree)
            }
  
            temp->left = n;                                     //The original node is now the temporary nodes left child
            n->parent = temp;                                   //The temporary node is now the original node's parent
        }

        //Ensures the tree adheres to the rules of the Red Black Tree.
        //Runs every time a new node is added or an existing node is removed.
        void fixTree(Node* n) {
            Node *t1 = NULL;            //Temporary node
            Node *t2 = NULL;            //Temporary node
  
            while (n != root && !n->isBlack  && !n->parent->isBlack) { 
                t1 = n->parent; 
                t2 = n->parent->parent; 
  
                //If the parent of the node is left child of its parent
                if (t1 == t2->left) { 
                    Node *t3 = t2->right;   //The sibling of the parent
  
                    //Parent's sibling is also red 
                    if (t3 != NULL && !t3->isBlack) { 
                        t2->isBlack = false;        //Update colors
                        t1->isBlack = true;
                        t3->isBlack = true;
                        n = t2;                     //Node is replaced by its parent's parent
                    }
                    else { 
                        //If the node is right child of its parent
                        if (n == t1->right) { 
                            rotateLeft(t1);         //Rotation needed for the parent
                            n = t1;                 //Node is replaced by its parent
                            t1 = n->parent;         //Parent is replaced by its parent
                        }
                        else {
                            //The node is left child of its parent
                            rotateRight(t2);                    //Rotation needed for the parent's parent
                            swap(t1->isBlack, t2->isBlack);     //Swap the parent and parent's parent's colors
                            n = t1;                             //Node is replaced by its parent
                        }
                    } 
                } 
                else { 
                    //The parent of the node is right child of its parent
                    Node *t3 = t2->left;                        //The sibling of the parent
  
                    //Parent's sibling is also red 
                    if (t3 != NULL && !t3->isBlack) { 
                        t2->isBlack = false;                    //Update colors
                        t1->isBlack = true; 
                        t3->isBlack = true; 
                        n = t2;                                 //Node is replaced by its parent's parent
                    } 
                    else { 
                        //If the node is the left child of its parent
                        if (n == t1->left) { 
                            rotateRight(t1);                    //Rotation needed for the parent
                            n = t1;                             //Node is replaced by its parent
                            t1 = n->parent;                     //Parent is replaced by its parent
                        }
                        else {
                            //The node is the right child of its parent
                            rotateLeft(t2);                     //Rotation needed for the parent's parent
                            swap(t1->isBlack, t2->isBlack);     //Swap the parent and parent's parent's colors
                            n = t1;                             //Node is replaced by its parent
                        }
                    } 
                } 
            } 
            root->isBlack = true;                               //Ensure the root node is black
        }

        //Private function to recursively insert a new node
        //The first if-elseif-else is the same as the BST
        Node* insert(Node *n, int value) {
            if(value > n->value) {                              //Value is greater than the current node's value; Needs to be inserted down the right branch
                if(n->right != NULL) {                          //A right child is present
                    return insert(n->right, value);             //Use recursion to insert down the right side
                }
                else {
                    n->right = new Node(value, n);              //No right child. Add this new node there.
                    return n->right;
                }
            }
            else if(value < n->value) {                         //Value is less than the current node's value; Needs to be inserted down the left branch
                if(n->left != NULL) {                           //A left child is present
                    return insert(n->left, value);              //Use recursion to insert down the left side
                }
                else {
                    n->left = new Node(value, n);               //No left child. Add this new node there
                    return n->left;
                }
            }
            else {
                __throw_runtime_error("Value already exists in the BST");   //Can't have duplicate values in the BST
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
                    n = NULL;                                       //Set the pointer to null
                }
                else if(n->left == NULL && n->right != NULL) {      //Has a RIGHT child, no NO LEFT child
                    Node *t = n->right;
                    delete n;
                    return t;
                }
                else if(n->right == NULL && n->left != NULL) {      //Has a LEFT child, but NO RIGHT child
                    Node *t = n->left;
                    delete n;
                    return t;
                }
                else {                                              //Has a LEFT AND RIGHT child
                    Node *t = findMin(n->right);                    //Find the successor (smallest value down the right branch)
                    n->value = t->value;                            //Copy the successor's value
                    n->right = remove(n->right, t->value);          //Recursively update the right branch to find and delete the successor
                }
            }
            return n;                                               //Return the n pointer
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
        RBTree() {
            root = NULL;
        }

        //Destructor
        ~RBTree() {
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
                root = new Node(value, NULL);                       //Tree is emny. Create a new root node.
                fixTree(root);
            }
            else {
                Node *t = insert(root, value);                                //Call the class's private insert function
                fixTree(t);
            }
        }

        //Public remove function
        //Removes a node from the tree
        void remove(int value) {
            root = remove(root, value);                             //Call the class's private remove function, starting the search with the root node
            fixTree(root);
        }
};