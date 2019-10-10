/**
 * Demonstrates the bubble sort on a linked list.
 * (It's the same for doubly linked lists and circular linked lists)
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
        //Constructor. Sets the head and tail to NULL as the list is empty
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

        //Retrieves the data from the node in the n'th position
        //Complexity = O(n)
        int get(int index) {
            if(index < 0 || head == NULL) {
                return 0;                                      //Prevents retrieval of negative indexes; Checks if list is empty
            }
            Node *current = head;                              //Creates a pointer to the head (need to start at beginning of list)
  
            //Find node to be retrieved
            for(int i = 0; current != NULL && i < index; i++) {
                current = current->next;
            }
  
            if(current == NULL) {
                return 0;                                      //Tried to retrieve beyond the tail of the list
            }

            return current->data;                              //Returns the data of the current node
        }

        //Retrieves the size of the singly linked list
        //Complexity = O(n)
        int size() {
            int count = 0;                                      //Starts the counter at zero
            Node *temp = head;                                  //Start with the head
            while(temp != NULL) {                               //As long as the temp pointer is not null
                count++;                                        //Increment the counter
                temp = temp->next;                              //Get the next node
            }
            return count;                                       //Return the count/total
        }

        //Retrieves the middle node (Method 1)
        //Complexity = O(n)
        Node* middleOne() {
            int middle = this->size()/2;                        //Get the size and divide it by two to find the middle position
            Node *temp = head;                                  //Start at the head
            for(int i = 1; i <= middle; i++) {
                temp = temp->next;                              //Iterate up to the calculated middle position
            }
            return temp;                                        //Return the Node
        }

        //Retrieves the middle node (Method 2)
        //Complexity = O(n)
        Node* middleTwo() {
            if(head == NULL) {
                return NULL;                                    //List is empty
            }
            Node *oneStep = head;                               //Will advance by one each iteration (starts at head)
            Node *twoStep = head;                               //Will advance by two each iteration (starts at head)

            while(twoStep != tail) {
                twoStep = twoStep->next;                        //Advance twoStep once                       
                if(twoStep != tail) {
                    oneStep = oneStep->next;                    //Advance oneStep once
                    twoStep = twoStep->next;                    //Advance twoStep again
                }
            }
            return oneStep;                                     //Return the Node
        }

        //Performs a bubble sort for a linked list
        //Same for doubly linked lists and circular linked lists
        //Complexity = O(n^2)
        void bubbleSort() {
            Node *temp;
            int size = this->size();
            for(int i = 0; i < size-1; i++) {
                temp = head;
                for(int j = 0; j < size-i-1; j++) {
                    Node *t1 = temp;
                    Node *t2 = temp->next;
                    if(t1->data > t2->data) {
                        int t = t2->data;                       //Swap
                        t2->data = t1->data;
                        t1->data = t;
                    }
                    temp = temp->next;
                }
            }
        }

};

/**
 * Main Function.
 */
int main() {
    SLinkedList list;
    list.push_back(13);
    list.push_back(9);
    list.push_back(11);
    list.push_back(5);
    list.push_back(7);

    cout << "List contents: ";
    list.printListData();

    list.bubbleSort();

    cout << "List contents: ";
    list.printListData();

    
    
}