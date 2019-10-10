/**
 * Demonstrates inserting nodes into a circular linked list.
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

    cout << "List contents: ";
    list.printListData();

    list.insert(15, 2);
    cout << "List contents: ";
    list.printListData();
    
}