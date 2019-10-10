/**
 * Demonstrates the basics of a circular queue.
 * (Implemented using an array of ints)
 */
#include<iostream>
#include<stdexcept>

using namespace std;

/**
 * Circular Queue
 */
class CQueue {
    private:
        int max;                                                //Queue's capacity
        int front;                                              //References the array index of the front element
        int back;                                               //References the array index of the back element
        int *a;                                                 //The array the queue will use
        int count;                                              //Number of items in the queue

    public:
        //Constructor.
        CQueue(int sizeIn) {
            max = sizeIn;                                       //Sets the capacity
            a = new int[max];                                   //Instantiates the array
            front = -1;
            back = -1;
            count = 0;
        }

        //Destructor. 
        ~CQueue() {
            free(a);                                            //Frees the array
        }

        //push method. Adds data to the back of the queue.
        //Complexity = O(1)
        void push(int newData) {
            if(count == max) {
                __throw_overflow_error("Queue is full");        //Checks if the queue is full
            }
            else if(front == -1) {
                front = 0;                                      //Checks if the queue is empty
                back = 0;
            }
            else if(back == max-1) {
                back = 0;                                       //Check if the queue needs to wrap the back around to index 0
            }
            else {
                back++;                                         //Increment the back index
            }
            a[back] = newData;                                  //Store the data
            count++;                                            //Increment the count
        }

        //pop method. Removes and retrieves the data at the front of the queue.
        //Complexity = O(1)
        int pop() {
            if(front == -1) {
                __throw_underflow_error("Queue is empty");      //Checks if the queue is empty
            }
            int temp = a[front];                                //Gets the data from the front
            if(front == back) {
                front = -1;                                     //Queue will now be empty
                back = -1;
            }
            else if(front == max-1) {
                front = 0;                                      //Wrap the front around to index 0
            }
            else {
                front++;                                        //Increment the front index
            }
            count--;                                            //Decrement the count
            return temp;                                        //Return the data
        }

        //peek method. Retrieves (but does not remove) the data at the front of the queue.
        //Complexity = O(1)
        int peek() {
            if(front == -1) {
                __throw_underflow_error("Queue is empty");      //Checks if the queue is empty
            }
            return a[front];
        }

        //isEmpty method. Determines if the queue is empty.
        bool isEmpty() {
            return front == -1 ? true : false;
        }
        
        //isFull method. Determines if the queue is full.
        bool isFull() {
            return count == max ? true : false;
        }

        //size method. Retrieves the number of items in the queue.
        int size() {
            return count;
        }

        //Resets the queue
        //Doesn't need to clear the contents because the array takes up the same space regardless
        //Complexity = O(1)
        void clear() {
            front = -1;
            back = -1;
            count = 0;
        }

};

/**
 * Main Function.
 */
int main() {
    CQueue cq(5);
    cout << "Pushing 1, 2, and 3" << endl;
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cout << "Queue length: " << cq.size() << endl;
    cout << "Peeking at top: " << cq.peek() << endl;
    cout << "Popping from top: " << cq.pop() << endl;
    cout << "Queue length: " << cq.size() << endl;
    cout << "Peeking at top: " << cq.peek() << endl << endl;

    cout << "Pushing 4, 5, and 6" << endl;
    cq.push(4);
    cq.push(5);
    cq.push(6);
    cout << "Queue length: " << cq.size() << endl;
    cout << "Peeking at top: " << cq.peek() << endl;
    int value = cq.pop();
    cout << "Popped from top: " << value << endl;
    cout << "Queue length: " << cq.size() << endl;
    cout << "Peeking at top: " << cq.peek() << endl << endl;
    
    cout << "Pushing 7" << endl;
    cq.push(7);
    
    cout << "Pushing 8" << endl;
    try {
        cq.push(8);
    }
    catch(overflow_error e) {
        cout << "Exception handled - " << e.what() << endl;
    }

    cout << "Queue length: " << cq.size() << endl;
    cout << "\nEmptying..." << endl;
    while(!cq.isEmpty()) {
        cout << "Popped " << cq.pop() << endl;
        cout << "Queue length: " << cq.size() << endl;
    }
    cout << "Done" << endl << endl;

    cout << "Trying to pop the next item (there aren't any)" << endl;
    try {
        cq.pop();
    }
    catch(underflow_error e) {
        cout << "Exception handled - " << e.what() << endl << endl;
    }

}
