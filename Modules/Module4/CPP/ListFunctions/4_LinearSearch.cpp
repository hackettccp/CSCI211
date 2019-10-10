/**
 * Demonstrates a linear search of a linked list.
 * (It's the same for doubly linked lists)
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

        //Performs a linear search of the list
        //Complexity = O(n)
        Node* linearSearch(int searchVal) {
            Node *temp = head;                                  //Start at head
            if(temp == NULL) {
                return NULL;                                    //List is empty
            }
            do {
                if(temp->data == searchVal) {
                    return temp;                                //Return the node with the matching data
                }
                temp = temp->next;                              //Get the next node
            } while(temp != NULL);                              //REPLACE NULL WITH head FOR A CIRCULAR LINKED LIST
            return NULL;                                        //Value was not found in any node
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

    int value = 0;
    cout << "Enter a value to search for (-99 to quit): ";
    cin >> value;
    while(value != -99) {
        Node *node = list.linearSearch(value);
        if(node != NULL) {
            cout << "Found " << node->data << endl;
        }
        else {
            cout << value << " was not found." << endl;
        }
        cout << "Enter a value to search for (-99 to quit): ";
        cin >> value;
    }
    
    
}