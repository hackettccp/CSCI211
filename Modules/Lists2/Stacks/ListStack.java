package Stacks;

import java.util.EmptyStackException;

/**
 * Implementation of a stack (as a list)
 */
public class ListStack {

    /**
     * Implementation of a Node in this Stack
     */
    private class Node {
        int data;
        Node next;
    }

    private Node top;
    private int size;

    /**
     * Constructor
     */
    public ListStack() {
        top = null;
        size = 0;
    }

    /**
     * push method. Adds data to the top of the stack.
     * @param newData - Data to push onto the stack
     */
    public void push(int newData) {
        Node temp = new Node();
        temp.data = newData;
        temp.next = top;
        top = temp;
        size++;
    }

    /**
     * pop method. Removes and retrieves the data at the top of the stack.
     * @return - Data at the top of the stack
     */
    public int pop() {
        if(size == 0) {
            throw new EmptyStackException();        //Stack is empty
        }
        int data = top.data;                        //Get the data at the top of the stack
        top = top.next;                             //Delete it from the stack
        size--;                                     //Decrement the size
        return data;                                //Return the data
    }

    /**
     * peek method. Retrieves (but does not remove) the data at the top of the stack.
     * @return - Data at the top of the stack
     */
    public int peek() {
        if(size == 0) {
            throw new EmptyStackException();        //Stack is empty
        }
        return top.data;                            //Return the data at the top of the stack
    }

    /**
     * size method. Retrieves the current usage of the stack
     * @return - Stack's utilization
     */
    public int getSize() {
        return size;
    }

    /**
     * isEmpty method. Determines if the stack is empty.
     * @return - True if stack is empty
     */
    public boolean isEmpty() {
        return size == 0 ? true : false;             //Returns true if stack is empty
    }

}
