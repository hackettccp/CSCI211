/**
 * Demonstrates removing a node from a singly linked list.
 */
#include<iostream>

using namespace std;

/**
 * Node object to represent each place in the linked list.
 * Contains one int value of data.
 * Contains a pointer to the next node in the list. 
 */
struct Node {
    int data;                   //The value stored in the node
    Node *next;                 //Pointer to the next node in the list
};

/**
 * Singly Linked List
 */
class SLinkedList {
    private:
        Node *head;             //Pointer to the head of the list
        Node *tail;             //Pointer to the end of the list

    public:
        //Constructor. Sets the head and tail to NULL
        SLinkedList() {
            head = NULL;
            tail = NULL;
        }

        //push_back method. Appends a new node to the end of the list.
        //Complexity = O(1)
        void push_back(int newData) {
            Node *temp = new Node;                  //Creates the new node to add
            temp->data = newData;                   //Assigns the parameter to the Node's data field
            temp->next = NULL;                      //Sets the next node to null (since it is at the end of the list)

            if(head == NULL) {                      //List is empty
                head = temp;                        //New node is the head and tail
                tail = temp;
            }
            else {
                tail->next = temp;                  //Sets the current tail node to point to this new node as being next
                tail = tail->next;                  //Sets the list's tail pointer to point to the new node (the new tail)
            }
        }

        //Traverses the list and prints the data of each node
        //Complexity = O(n)
        void printListData() {
            Node *tempPtr;                          //Temporary pointer
            tempPtr = head;                         //Sets the temporary pointer to point to the head
            while(tempPtr != NULL) {
                cout << tempPtr->data << " ";       //Print the node's data
                tempPtr = tempPtr->next;            //Get the temporary pointer to point to the next node in the list
            }
            cout << endl;
        }

        //push_front method. Adds a new node to the beginning of the list.
        //Complexity = O(1)
        void push_front(int newData) {
            Node *temp = new Node;                  //Creates a new node
            temp->data = newData;                   //Assigns the parameter to the node's data field
            temp->next = head;                      //Point the node's next field to point to the current head
            head = temp;                            //Change the head pointer to point to the new node
            if(tail == NULL) {
                tail = temp;                        //If tail is null, then the list was empty. This node is both head and tail.
            }
        }

        //Inserts a new node in the n'th position
        //Complexity = O(n)
        void insert(int newData, int index) {
            if(index <= 0) {
                return;                                 //Prevents insertion at negative indexes or zero (use push_front for zero)
                //push_front(newData);                  //ALTERNATIVE TO RETURNING
            }
            Node *temp = head;                          //Creates a pointer to the head (need to start at beginning of list)
            int counter = 0;                            //Keeps track of how many nodes we visited in the loop below
            while(counter < index-1 && temp != NULL) {
                temp = temp->next;                      //Replaces the current node with the next node
                counter++;                              //Increments the counter
            }

            if(temp == NULL || temp->next == NULL) {
                return;                                 //Tried to insert beyond the tail of the list; use push_back instead
                //push_back(newData);                   //ALTERNATIVE TO RETURNING
            }
            else {
                Node *newNode = new Node;               //Create new node
                newNode->data = newData;                //Assigns the parameter to the node's data field
                newNode->next = temp->next;             //Point the node's next field to point to where the current node's next field points
                temp->next = newNode;                   //Change the current node's next pointer to point to the new node
            }
            
        }

        //Removes a node from the n'th position
        //Complexity = O(n)
        void erase(int index) {
            if(index < 0 || head == NULL) {
                return;                                         //Prevents removal of negative indexes; Checks if list is empty
            }
            Node *previous = head;                              //Creates a pointer to the head (need to start at beginning of list)

            //Check if head is to be removed
            if(index == 0) { 
                head = previous->next;                          //Make the pointer to the node after the current head to be the new head
                free(previous);                                 //Free the old head
                return; 
            } 
  
            //Find node directly before the node to be deleted
            for(int i = 0; previous != NULL && i < index-1; i++) {
                previous = previous->next; 
            }
  
            if (previous == NULL || previous->next == NULL) {
                return;                                         //Tried to remove beyond the tail of the list
            }

            Node *after = previous->next->next;                 //Get the node AFTER the one to be removed
            free(previous->next);                               //Free the node to be removed
            previous->next = after;                             //Points the previous node to the node after the now deleted node
        }

};

/**
 * Main Function.
 */
int main() {
    SLinkedList list;
    list.push_back(5);
    list.push_back(7);
    list.push_back(9);
    list.push_back(11);

    cout << "List contents: ";
    list.printListData();

    list.erase(2);
    cout << "List contents: ";
    list.printListData();
    
}