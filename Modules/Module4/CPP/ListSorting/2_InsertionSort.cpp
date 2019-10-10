/**
 * Demonstrates an insertion sort using a doubly linked list.
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

        void insertionSort() {
            if(head == NULL) {
                return;                                                 //Check if list is empty
            }
            int size = this->size();                                    //Get the size for the below loop
            Node *sort = head->next;                                    //Start with the element after the head (index 1 if this were an array)
            for(int i = 1; i < size; i++) {
                Node *temp = sort->previous;                            //Get the node before the node position we are sorting for
                int sortValue = sort->data;                             //Get the current value in the node position we are sorting for
                while(temp != NULL && temp->data > sortValue) {
                    int t = temp->data;                                 //Get the temporary node's value
                    temp->data = sortValue;                             //Swap this node's value with...
                    temp->next->data = t;                               //The node directly after it
                    temp = temp->previous;                              //Get the next node, going backwards
                }
                sort = sort->next;                                      //Get the next node position to sort for
            }
        }

};

/**
 * Main Function.
 */
int main() {
    DLinkedList list;
    list.push_back(13);
    list.push_back(9);
    list.push_back(11);
    list.push_back(5);
    list.push_back(7);

    cout << "List contents: ";
    list.printListData();

    list.insertionSort();

    cout << "List contents: ";
    list.printListData();

}