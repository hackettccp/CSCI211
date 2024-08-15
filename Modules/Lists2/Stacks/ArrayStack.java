package Stacks;

import java.util.EmptyStackException;

/**
 * Implementation of a stack (using an array)
 */
public class ArrayStack {

    private int max;        //Stack's capacity
    private int top;        //References the array index of the top element
    private int[] a;        //The array the stack will use

    /**
     * Constructor
     * @param sizeIn - Stack size
     */
    public ArrayStack(int sizeIn) {
        max = sizeIn;                         //Sets the capacity
        a = new int[max];                     //Instantiates the array
        top = -1;                             //Sets top to -1 (signifying the stack is empty)
    }

    /**
     * push method. Adds data to the top of the stack.
     * @param newData - Data to push onto the stack
     */
    public void push(int newData) {
        if(top >= max-1) {
            throw new StackOverflowError("Stack Overflow");  //Stack is full
        }
        a[++top] = newData;                   //Increments top before adding the data to the stack
    }

    /**
     * pop method. Removes and retrieves the data at the top of the stack.
     * @return - Data at the top of the stack
     */
    public int pop() {
        if(top < 0) {
            throw new EmptyStackException();   //Stack is empty
        }
        return a[top--];                       //Returns the value at the top before decrementing top
    }

    /**
     * peek method. Retrieves (but does not remove) the data at the top of the stack.
     * @return - Data at the top of the stack
     */
    public int peek() {
        if(top < 0) {
            throw new EmptyStackException();   //Stack is empty
        }
        return a[top];                         //Returns the value at the top
    }

    /**
     * size method. Retrieves the current usage of the stack
     * @return - Stack's utilization
     */
    public int size() {
        return top + 1;
    }

    /**
     * capacity method. Retrieves the stack's capacity
     * @return - Stack's maximum capacity
     */
    public int capacity() {
        return max;
    }

    /**
     * isEmpty method. Determines if the stack is empty.
     * @return - True if stack is empty
     */
    public boolean isEmpty() {
        return top < 0 ? true : false;             //Returns true if top is -1
    }

    /**
     * isFull method. Determines if the stack is full.
     * @return - True if stack is full
     */
    public boolean isFull() {
        return top == max - 1 ? true : false;      //Returns true if top is equal to the last index of the array
    }

}
