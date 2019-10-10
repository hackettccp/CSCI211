/**
 * Demonstrates the basics of a deque (double ended queue).
 * (Implemented using a doubly linked list)
 */
#include<iostream>
#include<stdexcept>

using namespace std;

/**
 * Node object to represent each place in the deque.
 * Contains one int value of data.
 * Contains pointers to the next and previous node in the deque.
 */
struct Node {
    int data;                   //The value stored in the node
    Node *next;                 //Pointer to the next node in the list
    Node *previous;             //Pointer to the previous node in the list
};

/**
 * Deque
 */
class Deque {
    private:
        int count;              //Keeps track of the number of nodes
        Node *front;            //Pointer to the front of the deque
        Node *back;             //Pointer to the back of the deque

    public:
        //Constructor.
        Deque() {
            count = 0;
            front = NULL;
            back = NULL;
        }

        //Destructor. 
        ~Deque() {
            clear();
        }

        //push_front method. Adds data to the front of the queue.
        //Complexity = O(1)
        void push_front(int newData) {
            Node *temp = new Node;                                  //Create new node
            temp->data = newData;                                   //Set its data
            temp->previous = NULL;                                  //Sets previous to NULL (since it is in the front)
            if(front == NULL) {
                front = temp;                                       //Check if queue is empty (new node is the front and back)
                back = temp;
                temp->next = NULL;                                  //Sets next to NULL (since it is also the back)
            }
            else {
                temp->next = front;                                 //Set the node's next pointer to the current front node
                front->previous = temp;                             //Set the current front node's previous pointer to the new node
                front = temp;                                       //Set the front pointer to point to the new node
            }
            count++;                                                //Increase the count
        }

        //push_back method. Adds data to the back of the queue.
        //Complexity = O(1)
        void push_back(int newData) {
            Node *temp = new Node;                                  //Create new node
            temp->data = newData;                                   //Set its data
            temp->next = NULL;                                      //Sets next to NULL (since it is in the back)
            if(back == NULL) {
                front = temp;                                       //Check if queue is empty (new node is the front and back)
                back = temp;
                temp->previous = NULL;                              //Sets previous to NULL (since it is also the front)
            }
            else {
                temp->previous = back;                              //Set the node's previous pointer to the current back node
                back->next = temp;                                  //Set the current back node's next pointer to the new node
                back = temp;                                        //Set the back pointer to point to the new node
            }
            count++;                                                //Increase the count
        }

        //pop_front method. Removes and retrieves the data at the front of the deque.
        //Complexity = O(1)
        int pop_front() {
            if(front == NULL) {
                __throw_underflow_error("Deque is empty");          //Checks if the deque is empty
            }
            int tempData = front->data;                             //Gets the data from the front of the deque
            Node *tempNode = front->next;                           //Temporary pointer to the node after the front
            free(front);                                            //Frees the front node
            if(tempNode != NULL) {
                tempNode->previous = NULL;                          //Updates the temp node's previous pointer to null (since it is now in front)
            }
            else {
            	back = tempNode;									//Deque is now empty									
			}
            front = tempNode;                                       //Update the front pointer
            count--;                                                //Decrease the count
            return tempData;                                        //Return the value from the node that was at the front
        }

        //pop_back method. Removes and retrieves the data at the back of the deque.
        //Complexity = O(1)
        int pop_back() {
            if(back == NULL) {
                __throw_underflow_error("Deque is empty");          //Checks if the deque is empty
            }
            int tempData = back->data;                              //Gets the data from the back of the deque
            Node *tempNode = back->previous;                        //Temporary pointer to the node before the back
            free(back);                                             //Frees the back node
            if(tempNode != NULL) {
                tempNode->next = NULL;                              //Updates the temp node's next pointer to null (since it is now in back)
            }
            else {
            	front = tempNode;									//Deque is now empty								
			}
            back = tempNode;                                        //Update the back pointer
            count--;                                                //Decrease the count
            return tempData;                                        //Return the value from the node that was at the back
        }

        //peek_front method. Retrieves (but does not remove) the data at the front of the deque.
        //Complexity = O(1)
        int peek_front() {
            if(front == NULL) {
                __throw_underflow_error("Deque is empty");          //Checks if the deque is empty
            }
            return front->data;
        }

        //peek_back method. Retrieves (but does not remove) the data at the back of the deque.
        //Complexity = O(1)
        int peek_back() {
            if(back == NULL) {
                __throw_underflow_error("Deque is empty");          //Checks if the deque is empty
            }
            return back->data;
        }

        //size method. Retrieves the length/number of nodes in the deque. (Same as a queue)
        int size() {
            return count;
        }

        //isEmpty method. Determines if the deque is empty. (Same as a queue)
        bool isEmpty() {
            return front == NULL ? true : false;                    //Returns true if front is NULL
        }

        //Resets the deque (Same as resetting a queue)
        //Complexity = O(n)
        void clear() {
            Node *current = front;                                  //Starts at the front
            Node* next;
  
            while (current != NULL) {
                next = current->next;                               //Gets the next node
                free(current);                                      //Frees the current node
                current = next;                                     //Makes the next node the current node
            }
            front = NULL;                                           //Updates the front to NULL
            back = NULL;                                            //Updates the back to NULL
        }

};

/**
 * Main Function.
 */
int main() {
    Deque d;
    cout << "Pushing 1, 2, and 3 to back" << endl;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    cout << "Pushing 4, 5, and 6 to front" << endl;
    d.push_front(4);
    d.push_front(5);
    d.push_front(6);
    cout << "Deque length: " << d.size() << endl;
    cout << "Peeking at front: " << d.peek_front() << endl;
    cout << "Peeking at back: " << d.peek_back() << endl;
    int frontValue = d.pop_front();
    cout << "Popped from front: " << frontValue << endl;
    int backValue = d.pop_back();
    cout << "Popped from back: " << backValue << endl;
    cout << "Deque length: " << d.size() << endl;
    cout << "Peeking at front: " << d.peek_front() << endl;
    cout << "Peeking at back: " << d.peek_back() << endl << endl;

    cout << "Deque length: " << d.size() << endl;
    cout << "\nEmptying..." << endl;
    while(!d.isEmpty()) {
        cout << "Popped from front: " << d.pop_front() << endl;
        cout << "Deque length: " << d.size() << endl;
    }
    cout << "Done" << endl << endl;

    cout << "Trying to pop the next item (there aren't any)" << endl;
    try {
        d.pop_front();
    }
    catch(underflow_error e) {
        cout << "Exception handled - " << e.what() << endl << endl;
    }
}
