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
        //Called every time a new node is added or an existing node is removed.
        void fixTree(Node* n) {
            Node *p = NULL;            //Temporary pointer for a node's parent
            Node *gp = NULL;            //Temporary pointer for a node's grandparent
  
            while (n != root && n->color == 0  && n->parent->color == 0) {      //n is not the root, it is red, and its parent is red
                p = n->parent; 
                gp = n->parent->parent; 
  
                //If the parent of the node is left child of its parent
                if (p == gp->left) { 
                    Node *u = gp->right;   //Temporary pointer for a node's uncle
  
                    //Uncle is present and is red 
                    if (u != NULL && u->color == 0) { 
                        gp->color = 0;              //Update colors
                        p->color = 1;
                        u->color = 1;
                        n = gp;                     //Moving up the tree
                    }
                    else { 
                        //If the node is right child of its parent
                        if (n == p->right) { 
                            rotateLeft(p);         //Rotation needed for the parent
                            n = p;                 //Moving up the tree
                            p = n->parent;         //Moving up the tree
                        }
                        else {
                            //The node is left child of its parent
                            rotateRight(gp);                    //Rotation needed for the parent's parent
                            swap(p->color, gp->color);          //Swap the parent and parent's parent's colors
                            n = p;                              //Moving up the tree
                        }
                    } 
                } 
                else { 
                    //The parent of the node is right child of its parent
                    Node *u = gp->left;                         //Temporary pointer for a node's uncle
  
                    //Uncle is present and is red
                    if (u != NULL && u->color == 0) { 
                        gp->color = 0;                          //Update colors
                        p->color = 1; 
                        u->color = 1; 
                        n = gp;                                 //Moving up the tree
                    } 
                    else { 
                        //If the node is the left child of its parent
                        if (n == p->left) { 
                            rotateRight(p);                    //Rotation needed for the parent
                            n = p;                             //Moving up the tree
                            p = n->parent;                     //Moving up the tree
                        }
                        else {
                            //The node is the right child of its parent
                            rotateLeft(gp);                     //Rotation needed for the parent's parent
                            swap(p->color, gp->color);          //Swap the parent and parent's parent's colors
                            n = p;                              //Moving up the tree
                        }
                    } 
                } 
            } 
            root->color = 1;                                    //Ensure the root node is black
        }

        //Private function to recursively insert a new node
        //(Same as a normal BST)
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
                root = new Node(value, NULL);                       //Tree is empty. Create a new root node.
                fixTree(root);
            }
            else {
                Node *t = insert(root, value);                      //Call the class's private insert function
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