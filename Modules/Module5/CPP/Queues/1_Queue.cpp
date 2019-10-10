/**
 * Demonstrates the basics of a queue.
 * (Implemented using a singly linked list)
 */
#include<iostream>
#include<stdexcept>

using namespace std;

/**
 * Node object to represent each place in the queue.
 * Contains one int value of data.
 * Contains a pointer to the next node in the queue.
 */
struct Node {
    int data;                   //The value stored in the node
    Node *next;                 //Pointer to the next node in the list
};

/**
 * Queue
 */
class Queue {
    private:
        int count;              //Keeps track of the number of nodes
        Node *front;            //Pointer to the front of the queue
        Node *back;             //Pointer to the back of the queue

    public:
        //Constructor.
        Queue() {
            count = 0;
            front = NULL;
            back = NULL;
        }

        //Destructor. 
        ~Queue() {
            clear();
        }

        //push method. Adds data to the back of the queue.
        //Complexity = O(1)
        void push(int newData) {
            Node *temp = new Node;                                  //Create new node
            temp->data = newData;                                   //Set its data
            temp->next = NULL;                                      //Its next pointer will point to NULL (since it will be at the back)
            if(back == NULL) {
                front = temp;                                       //Check if queue is empty (new node is in the front)
            }
            else {
                back->next = temp;                                  //Have the current back node point to the new node
            }
            back = temp;                                            //Make the back pointer point to the new node
            count++;                                                //Increase the count
        }

        //pop method. Removes and retrieves the data at the front of the queue.
        //Complexity = O(1)
        int pop() {
            if(front == NULL) {
                __throw_underflow_error("Queue is empty");          //Checks if the queue is empty
            }
            int tempData = front->data;                             //Gets the data from the front of the queue
            Node *tempNode = front->next;                                 //Temporary pointer to the front of the queue
            free(front);
            front = tempNode;
            count--;                                         
            return tempData;                                        //Return the value from the node that was at the front
        }

        //peek method. Retrieves (but does not remove) the data at the front of the queue.
        //Complexity = O(1)
        int peek() {
            if(front == NULL) {
                __throw_underflow_error("Queue is empty");          //Checks if the queue is empty
            }
            return front->data;
        }

        //size method. Retrieves the length/number of nodes in the queue.
        int size() {
            return count;
        }

        //isEmpty method. Determines if the queue is empty.
        bool isEmpty() {
            return front == NULL ? true : false;                    //Returns true if front is NULL
        }

        //Resets the queue
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
    Queue q;
    cout << "Pushing 1, 2, and 3" << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Queue length: " << q.size() << endl;
    cout << "Peeking at top: " << q.peek() << endl;
    cout << "Popping from top: " << q.pop() << endl;
    cout << "Queue length: " << q.size() << endl;
    cout << "Peeking at top: " << q.peek() << endl << endl;

    cout << "Pushing 4, 5, and 6" << endl;
    q.push(4);
    q.push(5);
    q.push(6);
    cout << "Queue length: " << q.size() << endl;
    cout << "Peeking at top: " << q.peek() << endl;
    int value = q.pop();
    cout << "Popped from top: " << value << endl;
    cout << "Queue length: " << q.size() << endl;
    cout << "Peeking at top: " << q.peek() << endl << endl;
    
    cout << "Pushing 7 and 8" << endl;
    q.push(7);
    q.push(8);

    cout << "Queue length: " << q.size() << endl;
    cout << "\nEmptying..." << endl;
    while(!q.isEmpty()) {
        cout << "Popped " << q.pop() << endl;
        cout << "Queue length: " << q.size() << endl;
    }
    cout << "Done" << endl << endl;

    cout << "Trying to pop the next item (there aren't any)" << endl;
    try {
        q.pop();
    }
    catch(underflow_error e) {
        cout << "Exception handled - " << e.what() << endl << endl;
    }
}