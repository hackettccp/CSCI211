/**
 * Demonstrates the basics of an n-ary tree and
 * inorder, preorder, and postorder traversals.
 */
#include<iostream>
#include<vector>
#include<queue>
#include "Node.h"

using namespace std;

//Performs an breadth-first traversal of the tree
void breadthfirst(Node *n) {
    if(n == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(n);
    while(!q.empty()) {
        int s = q.size();
        while(s > 0) {
            Node *t = q.front();
            q.pop();
            cout << t->getValue() << " ";
            for(int i=0; i < t->getChildrenSize(); i++) {
                q.push(t->getChild(i));
            }
            s--;
        }
    }
}        

//Performs a depth-first (using postorder) traversal of the tree
void depthfirst(Node *n) {
    if(n == NULL) {
        return;
    }

    for(int i=0; i < n->getChildrenSize(); i++) {
        depthfirst(n->getChild(i));
    }

    cout << n->getValue() << " ";
} 


//Main Function.
int main() {
    Node *root = new Node("A");                     //Root of the tree
    root->addChild("B");                            //Root's 0th child
    root->addChild("C");                            //Root's 1st child
    root->addChild("D");                            //Root's 2nd child

    root->getChild(0)->addChild("E");               //B's children
    root->getChild(0)->addChild("F");               //
    root->getChild(0)->addChild("G");               //
    root->getChild(0)->addChild("H");               //

    root->getChild(1)->addChild("I");               //C's child

    root->getChild(2)->addChild("J");               //D's children
    root->getChild(2)->addChild("K");               //
    root->getChild(2)->addChild("L");               //
    

    cout << "Breadth First Traversal: " << endl;
    breadthfirst(root);
    cout << endl << endl;

    cout << "Depth First Traversal: " << endl;
    depthfirst(root);
    cout << endl << endl;
}