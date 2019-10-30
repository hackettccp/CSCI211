/**
 * Demonstrates the basics of an n-ary tree and
 * inorder, preorder, and postorder traversals.
 */
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//Represents a node/vertex in an n-ary tree
class Node {
    private:
        string value;                                   //Value stored in the node
        vector<Node*> children;                         //A vector (or linked list or similar) for containing the child nodes
    
    public:
        //Constructor
        Node(string v) {
            value = v;                                  //Sets the value
        }

        //Adds a child to the nodes vector of children
        void addChild(string value) {
            Node *t = new Node(value);
            children.push_back(t);
        }

        //Returns the value of the node
        string getValue() {
            return value;
        }

        //Returns a child node, specified by index
        Node* getChild(int index) {
            return children[index];
        }

        //Returns the number of children
        int getChildrenSize() {
            return children.size();
        }
};

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
    Node *root = new Node("A");
    root->addChild("B");
    root->addChild("C");
    root->addChild("D");

    root->getChild(0)->addChild("E");
    root->getChild(0)->addChild("F");
    root->getChild(0)->addChild("G");
    root->getChild(0)->addChild("H");

    root->getChild(1)->addChild("I");

    root->getChild(2)->addChild("J");
    root->getChild(2)->addChild("K");
    root->getChild(2)->addChild("L");
    

    cout << "Breadth First Traversal: " << endl;
    breadthfirst(root);
    cout << endl << endl;

    cout << "Depth First Traversal: " << endl;
    depthfirst(root);
    cout << endl << endl;
}