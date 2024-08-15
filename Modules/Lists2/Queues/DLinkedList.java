package Queues;

import java.util.NoSuchElementException;

/**
 * Implementation of a Doubly Linked List (for the Deque)
 */
public class DLinkedList {

    /**
     * Implementation of a Node in this Doubly Linked List
     */
    private class Node {
        int data;
        Node next;
        Node previous;
    }

    private Node head;      //Reference to the head of the list
    private Node tail;      //Reference to the tail of the list
    private Node current;   //Reference to the current element
    private int length;     //Keeps track of the number of nodes in the list

    /**
     * Constructor
     */
    public DLinkedList() {
        tail = new Node();          //Create tail
        current = tail;             //Current references the tail
        head = new Node();          //Create head
        head.next = tail;           //Link the two
        tail.previous = head;       //Link the two
        length = 0;
    }

    /**
     * Appends a new node to the end of the list.
     */
    public void push(int newData) {
        Node temp = new Node();                 //Creates the new node to add
        temp.data = newData;                    //Sets its data
        temp.previous = tail.previous;          //Sets its previous node
        temp.next = tail;                       //Sets its next node

        tail.previous = temp;                           //Update the tail's previous
        tail.previous.previous.next = tail.previous;    //Update the next reference of the tail's old previous node
        if(current == tail) {
            current = tail.previous;                    //Update current if it was referring to the tail
        }

        length++;                               //Increment the length
    }

    /**
     * Inserts a new node from the current position
     */
    public void insert(int newData) {
        Node temp = new Node();                 //Creates the new node to add
        temp.data = newData;                    //Sets its data
        temp.previous = current.previous;       //Sets its previous node
        temp.next = current;                    //Sets its next node

        current = temp;                         //Update current

        current.previous.next = current;        //Update previous node's next reference
        current.next.previous = current;        //Update next node's previous reference

        length++;                               //Increment the length
    }

    /**
     * Removes a node from the current position
     */
    public void remove() {
        if(current == tail) {
            // No current element
            throw new NoSuchElementException("No element at this index");
        }

        current.previous.next = current.next;       //Update previous node's next reference
        current.next.previous = current.previous;   //Update next node's previous reference
        current = current.next;                     //Update the current reference

        length--;                                   //Decrement the length
    }

    /**
     * Retrieves the data from the node at the current location
     */
    public int get() {
        if(current == tail) {
            // No current element
            throw new NoSuchElementException("No element at this index");
        }
        return current.data;
    }

    /**
     * Moves the current reference to the first node
     */
    public void moveToStart() {
        current = head.next;
    }

    /**
     * Moves the current reference to the last node
     */
    public void moveToEnd() {
        current = tail.previous;
    }

    /**
     * Retrieves the current length of the list
     */
    public int getLength() {
        return length;
    }



}
