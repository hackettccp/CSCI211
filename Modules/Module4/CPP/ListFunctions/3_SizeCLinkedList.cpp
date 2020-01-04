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

    int size = list.size();
    cout << "Size of List: " << size << endl;
}