/**
 * Demonstrates the basics of a binary tree and
 * inorder, preorder, and postorder traversals.
 */
#include<iostream>

using namespace std;

//Represents a node/vertex in a binary tree
struct Node {
    int value;                                  //Value stored in the node
    Node *left;                                 //Pointer to the left child
    Node *right;                                //Pointer to the right child
    
    //Constructor
    Node(int v) {
        value = v;                              //Sets the value
        left = NULL;                            //No left child yet
        right = NULL;                           //No right child yet
    }
};

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

//Main Function.
int main() {
    Node *root = new Node(10);                          //Create the root node (Node "A" in these comments)
    root->left = new Node(20);                          //Create a left child (Node "B" in these comments)
    root->right = new Node(30);                         //Create a right child (Node "C" in these comments)
    /*
                 10("A")
              /      \
            20("B")   30("C")
           /  \      /   \
        NULL  NULL NULL  NULL
    */

    root->left->right = new Node(40);                   //Create a right child (Node "D" in these comments) for Node B
    root->right->right = new Node(50);                  //Create a right child (Node "E" in these comments) for Node C
    /*
                 10("A")
              /         \
            20("B")      30("C")
           /  \          /    \
        NULL   40("D")  NULL    50("E")
             /    \      /       \
           NULL  NULL  NULL      NULL
    */

    root->left->right->left = new Node(60);         //Create a left child (Node "F" in these comments) for Node D
    root->right->right->left = new Node(70);        //Create a left child (Node "G" in these comments) for Node E
    /*
                  10("A")
              /         \
            20("B")      30("C")
           /  \          /    \
        NULL   40("D")  NULL    50("E")
              /     \          /      \
          60("F")   NULL     70("G")   NULL
           /  \               /  \
        NULL  NULL         NULL  NULL
    */

    cout << "Inorder Traversal/\"Infix\": ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal/\"Prefix\": ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal/\"Postfix\": ";
    postorder(root);
    cout << endl;

}