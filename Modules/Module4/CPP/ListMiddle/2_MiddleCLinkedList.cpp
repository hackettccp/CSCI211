/**
 * Demonstrates getting the size/length of a circular linked list.
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
 * Circular Linked List
 */
class CLinkedList {
    private:
        Node *head;             //Pointer to the head of the list
        Node *tail;             //Pointer to the end of the list

    public:
        //Constructor. Sets the head to NULL and tail to point to head
        CLinkedList() {
            head = NULL;
            tail = head;
        }

        //push_back method. Appends a new node to the end of the list.
        //Complexity = O(1)
        void push_back(int newData) {
            Node *temp = new Node;                  //Creates the new node to add
            temp->data = newData;                   //Assigns the parameter to the Node's data field
            temp->next = head;                      //Sets the next node to head (since it will be the new tail)

            if(head == NULL) {                      //List is empty
                head = temp;                        //New node is the head and tail
                tail = temp;
            }
            else {
                tail->next = temp;                  //Sets the current tail node to point to this new node as being next
                tail = temp;                        //Sets the list's tail pointer to point to the new node (the new tail)
            }
        }

        //push_front method. Appends a new node to the front of the list.
        //Complexity = O(1)
        void push_front(int newData) {
            Node *temp = new Node;                  //Creates a new node
            temp->data = newData;                   //Assigns the parameter to the node's data field

            if(head == NULL) {                      //List is empty
                head = temp;                        //New node is the head and tail
                tail = temp;
            }
            else {
                temp->next = head;                  //Sets new node's next pointer to the current head
                tail->next = temp;                  //Sets the current tail's next pointer to point to the new node
                head = temp;                        //Sets the list's head pointer to point to the new node
            }
        }

        //Traverses the list and prints the data of each node
        //Complexity = O(n)
        void printListData() {
            Node *tempPtr;                          //Temporary pointer
            tempPtr = head;                         //Sets the temporary pointer to point to the head
            do {
                cout << tempPtr->data << " ";       //Print the node's data
                tempPtr = tempPtr->next;            //Get the temporary pointer to point to the next node in the list
            } while(tempPtr != head);
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
            while(counter < index-1 && temp != tail) {
                temp = temp->next;                      //Replaces the current node with the next node
                counter++;                              //Increments the counter
            } 

            if(temp == NULL || temp == tail) {
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
                tail->next = head;                              //Update the tail's next to the new head
                free(previous);                                 //Free the old head
                return; 
            } 
  
            //Find node directly before the node to be deleted
            for(int i = 0; previous != tail && i < index-1; i++) {
                previous = previous->next; 
            }
  
            if (previous == tail) {
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
            
            if(index == 0) {
                return head->data;
            }

            Node *current = head->next;                        //Creates a pointer to second value (already checked index 0)
  
            //Find node to be retrieved
            for(int i = 1; current != head && i < index; i++) {
                current = current->next;
            }
  
            if(current == head) {
                return 0;                                      //Tried to retrieve beyond the tail of the list (looped back around to the head)
            }

            return current->data;                              //Returns the data of the current node
        }

        //Retrieves the size of the circular linked list
        //Complexity = O(n)
        int size() {
            int count = 0;                                      //Starts the counter at zero
            Node *temp = head;                                  //Start with the head
            
            if(temp == NULL) {
                return count;                                   //List is empty; returns 0
            }
            
            do {                               
                count++;                                        //Increment the counter
                temp = temp->next;                              //Get the next node
            } while(temp != head);                              //Keep going as long as the temp pointer did not wrap back around

            return count;                                       //Return the count/total
        }

        //Retrieves the middle node (Method 1)
        //Complexity = O(n)
        Node* middleOne() {
            int middle = this->size()/2;
            Node *temp = head;
            for(int i = 1; i <= middle; i++) {
                temp = temp->next;
            }
            return temp;
        }

        //Retrieves the middle node (Method 2)
        //Complexity = O(n)
        Node* middleTwo() {
            if(head == NULL) {
                return NULL;
            }
            Node *oneStep = head;
            Node *twoStep = head;

            while(twoStep != tail) {
                twoStep = twoStep->next;
                if(twoStep != tail) {
                    oneStep = oneStep->next;
                    twoStep = twoStep->next;
                }
            }
            return oneStep;
        }

};

/**
 * Main Function.
 */
int main() {
    CLinkedList list;
    list.push_back(5);
    list.push_back(7);
    list.push_back(9);
    list.push_back(11);
    list.push_back(13);

    cout << "List contents: ";
    list.printListData();

    Node *middle = list.middleOne();
    cout << "Middle Value (middleOne method): " << middle->data << endl;

    middle = list.middleTwo();
    cout << "Middle Value (middleTwo method): " << middle->data << endl;
}