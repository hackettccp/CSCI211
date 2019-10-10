/**
 * Demonstrates two ways to get the middle element of a linked list.
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
    list.push_back(13);

    cout << "List contents: ";
    list.printListData();

    Node *middle = list.middleOne();
    cout << "Middle Value (middleOne method): " << middle->data << endl;

    middle = list.middleTwo();
    cout << "Middle Value (middleTwo method): " << middle->data << endl;
    
}