/**
 * Demonstrates the basics (push, pop, and peek) of a stack.
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
    cout << "Peeking at top: " << s.peek() << endl;
    cout << "Popping from top: " << s.pop() << endl;
    cout << "Peeking at top: " << s.peek() << endl;

    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    cout << "Peeking at top: " << s.peek() << endl;
    int value = s.pop();
    cout << "Popped from top: " << value << endl;
    cout << "Peeking at top: " << s.peek() << endl;

    s.push(12);
    s.push(13);
}