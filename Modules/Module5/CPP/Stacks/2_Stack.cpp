/**
 * Demonstrates the additional common functions (isEmpty, isFull, and size) of a stack.
 * (Implemented using an array of ints)
 */
#include<iostream>
#include<stdexcept>

using namespace std;

/**
 * Stack
 */
class StackArray {
    private:
        int max;                                                //Stack's capacity
        int top;                                                //References the array index of the top element
        int *a;                                                 //The array the stack will use

    public:
        //Constructor.
        StackArray(int sizeIn) {
            max = sizeIn;                                       //Sets the capacity
            a = new int[max];                                   //Instantiates the array
            top = -1;                                           //Sets top to -1 (signifying the stack is empty)
        }

        //Destructor. 
        ~StackArray() {
            free(a);                                            //Frees the array
        }

        //push method. Adds data to the top of the stack.
        //Complexity = O(1)
        void push(int newData) {
            if(top >= max-1) {
                __throw_overflow_error("Stack Overflow");       //Checks if the stack is full
            }
            a[++top] = newData;                                 //Increments top before adding the data to the stack
        }

        //pop method. Removes and retrieves the data at the top of the stack.
        //Complexity = O(1)
        int pop() {
            if(top < 0) {
                __throw_underflow_error("Stack Underflow");     //Checks if the stack is empty
            }
            return a[top--];                                    //Returns the value at the top before decrementing top
        }

        //peek method. Retrieves (but does not remove) the data at the top of the stack.
        //Complexity = O(1)
        int peek() {
            if(top < 0) {
                __throw_underflow_error("Stack Underflow");     //Check if the stack is empty
            }
            return a[top];                                      //Returns the value at the top
        } 

        //size method. Retrieves the current usage of the stack
        int size() {
            return top + 1;
        }

        //capacity method. Retrieves the stack's capacity
        int capacity() {
            return max;
        }

        //isEmpty method. Determines if the stack is empty.
        bool isEmpty() {
            return top < 0 ? true : false;                      //Returns true if top is -1
        }

        //isFull method. Determines if the stack is full.
        bool isFull() {
            return top == max - 1 ? true : false;               //Returns true if top is equal to the last index of the array
        }
};

/**
 * Main Function.
 */
int main() {
    StackArray s(10);
    cout << "Pushing 1, 2, 3, 4, and 5" << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Size: " << s.size() << endl;
    cout << "Capacity: " << s.capacity() << endl;
    
    while(!s.isFull()) {
        s.push(6);
    }
    cout << "Size: " << s.size() << endl;

    while(!s.isEmpty()) {
        s.pop();
    }
    cout << "Size: " << s.size() << endl;
}