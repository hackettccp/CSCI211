/**
 * Demonstrates the basics (push, pop, and peek) of a stack.
 * (Implemented using a singly linked list)
 */
#include<iostream>
#include<stdexcept>

using namespace std;

/**
 * Node object to represent each place in the stack's linked list.
 * Contains one int value of data.
 * Contains a pointer to the next node in the list. 
 */
struct Node {
    int data;                   //The value stored in the node
    Node *next;                 //Pointer to the next node in the list
};

/**
 * Stack
 */
class StackList {
    private:
        int count;                                                  //Keeps track of the number of nodes
        Node *head;

    public:
        //Constructor.
        StackList() {
            count = 0;
            head = NULL;
        }

        //Destructor. 
        ~StackList() {
            Node *current = head;                                   //Starts at the head
            Node* next;
  
            while (current != NULL) {
                next = current->next;                               //Gets the next node
                free(current);                                      //Frees the current node
                current = next;                                     //Makes the next node the current node
            }
            head = NULL;                                            //Updates the head to NULL
        }

        //push method. Adds data to the top of the stack. (Head of the list)
        //Complexity = O(1)
        void push(int newData) {
            Node *temp = new Node;                                  //Create new node
            temp->data = newData;
            temp->next = head;                                      //Next is the current head
            head = temp;                                            //Make the new node the new head
            count++;                                                //Increase the count
        }

        //pop method. Removes and retrieves the data at the top of the stack.
        //Complexity = O(1)
        int pop() {
            if(head == NULL) {
                __throw_underflow_error("Stack Underflow");         //Checks if the stack is empty
            }
            int tempData = head->data;                              //Gets the data of the current head (top of stack)
            Node *tempNode = head;                                  //Temporary pointer to current head
            head = head->next;                                      //Make the next node the new head
            free(tempNode);                                         //Free the old head
            count--;                                                //Decrement the count
            return tempData;                                        //Return the value taken from the old head
        }

        //peek method. Retrieves (but does not remove) the data at the top of the stack.
        //Complexity = O(1)
        int peek() {
            if(head == NULL) {
                __throw_underflow_error("Stack Underflow");         //Checks if the stack is empty
            }
            return head->data;
        }

        //size method. Retrieves the current usage of the stack.
        int size() {
            return count;
        }

        //isEmpty method. Determines if the stack is empty.
        bool isEmpty() {
            return head == NULL ? true : false;                      //Returns true if head is NULL
        }

};

/**
 * Main Function.
 */
int main() {
    StackList s;
    cout << "Pushing 1, 2, 3, 4, and 5" << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Size: " << s.size() << endl;
    cout << "Peeking at top: " << s.peek() << endl;
    cout << "Popping from top: " << s.pop() << endl;
    cout << "Size: " << s.size() << endl;
    cout << "Peeking at top: " << s.peek() << endl;

    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    cout << "Peeking at top: " << s.peek() << endl;
    cout << "Size: " << s.size() << endl;

    while(!s.isEmpty()) {
        s.pop();
    }
    cout << "Size: " << s.size() << endl;
}