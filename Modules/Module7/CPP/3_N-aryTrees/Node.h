/**
 * A node in an n-ary tree 
 */
#include<iostream>
#include<vector>

using namespace std;

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