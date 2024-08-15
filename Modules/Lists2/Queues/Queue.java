package Queues;

/**
 * Implementation of a queue (as a list)
 */
public class Queue {

    /**
     * Implementation of a Node in this Queue
     */
    private class Node {
        int data;
        Node next;
    }

    private Node front;             //Reference to the front of the queue
    private Node back;              //Reference to the back of the queue
    private int size;               //Current size of the queue

    /**
     * Constructor
     */
    public Queue() {
        front = null;
        back = null;
        size = 0;
    }

    /**
     * push method. Adds data to the back of the queue.
     * @param newData - Data to push onto the queue
     */
    public void push(int newData) {
        Node temp = new Node();       //Creates the new node to add
        temp.data = newData;
        if(size == 0) {
            front = temp;             //Only node in the queue
            back = temp;
        }
        else {
            back.next = temp;         //Add the new node to the back
            back = back.next;         //Update the back reference
        }
        size++;                       //Increment the size
    }

    /**
     * pop method. Removes and retrieves the data at the front of the queue.
     * @return - Data at the top of the queue
     */
    public int pop() {
        if(size == 0) {
            throw new RuntimeException("Queue is empty.");      //Queue is empty
        }
        int data = front.data;                                  //Get the data at the front of the queue
        front = front.next;                                     //Update the front reference
        size--;                                                 //Decrement the size
        if(size == 0) {
            back = null;                                        //The last element in the queue was just removed
        }
        return data;                                            //Return the data
    }

    /**
     * peek method. Retrieves (but does not remove) the data at the front of the queue.
     * @return - Data at the top of the queue
     */
    public int peek() {
        if(size == 0) {
            throw new RuntimeException("Queue is empty.");       //Queue is empty
        }
        return front.data;                                       //Return the data at the front of the queue
    }

    /**
     * size method. Retrieves the current usage of the queue
     * @return - Queue's utilization
     */
    public int getSize() {
        return size;
    }

    /**
     * isEmpty method. Determines if the queue is empty.
     * @return - True if queue is empty
     */
    public boolean isEmpty() {
        return size == 0;      //Returns true if list is empty
    }

}
