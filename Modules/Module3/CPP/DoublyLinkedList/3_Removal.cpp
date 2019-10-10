/**
 * Demonstrates removing nodes from a doubly linked list.
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
    Node *previous;             //Pointer to the previous node in the list
};

/**
 * Doubly Linked List
 */
class DLinkedList {
    private:
        Node *head;             //Pointer to the head of the list
        Node *tail;             //Pointer to the end of the list

    public:
        //Constructor. Sets the head and tail to NULL
        DLinkedList() {
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
                temp->previous = NULL;              //New node is the new head (already set next to null)
                head = temp;                        //Set the node as the head
                tail = temp;                        //Set the node as the tail
                return;
            }
            else {
                tail->next = temp;                  //Sets the current tail node to point to this new node as being next
                temp->previous = tail;              //Sets the new tail's previous pointer to the old tail
                tail = temp;                        //Sets the list's tail pointer to point to the new node (the new tail)
            }
        }

        //push_front method. Appends a new node to the front of the list.
        //Complexity = O(1)
        void push_front(int newData) {
            Node *temp = new Node;                  //Creates the new node to add
            temp->data = newData;                   //Assigns the parameter to the Node's data field
            temp->next = head;                      //Sets the node's next pointer to the current head
            temp->previous = NULL;                  //Sets the node's previous pointer to null, since it is the new head

            if(head != NULL) {                      //List is not empty
                head->previous = temp;              //Make current head's previous point to new node
            }
            head = temp;                            //Change the list's head to be the new node
            if(tail == NULL) {
                tail = temp;                        //If tail is null, then the list was empty. This node is both head and tail.
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

        //Traverses the list and prints the data of each node in reverse
        //Complexity = O(n)
        void printListDataReverse() {
            Node *tempPtr;                          //Temporary pointer
            tempPtr = tail;                         //Sets the temporary pointer to point to the tail
            while(tempPtr != NULL) {
                cout << tempPtr->data << " ";       //Print the node's data
                tempPtr = tempPtr->previous;        //Get the temporary pointer to point to the next node in the list
            }
            cout << endl;
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
                newNode->previous = temp;               //Point the node's previous field to where the current node
                
                temp->next->previous = newNode;         //Change the next node's previous pointer to the new node
                temp->next = newNode;                   //Change the current node's next pointer to point to the new node
            }
        }

        //Removes a node from the n'th position
        //Complexity = O(n)
        void erase(int index) {
            if(index < 0 || head == NULL) {
                return;                                         //Prevents removal of negative indexes; Checks if list is empty
            }
            Node *prev = head;                                  //Creates a pointer to the head (need to start at beginning of list)

            //Check if head is to be removed
            if(index == 0) { 
                head->next->previous = NULL;                    //Change the next node's previous pointer to null            
                head = prev->next;                              //Make the pointer to the next node be the new head
                free(prev);                                     //Free the old head
                return; 
            } 
  
            //Find node directly before the node to be deleted
            for(int i = 0; prev != NULL && i < index-1; i++) {
                prev = prev->next; 
            }
  
            if (prev == NULL || prev->next == NULL) {
                return;                                         //Tried to remove beyond the tail of the list
            }

            Node *after = prev->next->next;                     //Get the node AFTER the one to be removed
            
            //Check if removing the tail (after is null)
            if(after == NULL) {
                tail = prev;                                    //Set this node to be the new tail
                tail->next = NULL;
                free(prev->next);                               //Free the old tail
            }
            else {
                free(prev->next);                               //Free the node to be removed
                prev->next = after;                             //Points the previous node to the node after the now deleted node
                after->previous = prev;                         //Points the following node's previous pointer to the node before the now deleted node
            }
        }
};

/**
 * Main Function.
 */
int main() {
    DLinkedList list;
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