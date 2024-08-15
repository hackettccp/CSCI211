package SinglyLinkedList;

import java.util.NoSuchElementException;

/**
 * Implementation of a Singly Linked List
 */
public class SLinkedList {

    /**
     * Implementation of a Node in this Singly Linked List
     */
    private class Node {
        int data;
        Node next;
    }

    private Node head;      //Reference to the head of the list
    private Node tail;      //Reference to the tail of the list
    private Node current;   //Reference to the current element
    private int length;     //Keeps track of the number of nodes in the list

    /**
     * Constructor
     */
    public SLinkedList() {
        tail = new Node();          //Create tail
        current = tail;             //Current references the tail
        head = new Node();          //Create head
        head.next = tail;           //Link the two
        length = 0;
    }

    /**
     * Appends a new node to the end of the list.
     */
    public void push(int newData) {
        Node temp = new Node();       //Creates the new node to add
        tail.next = temp;             //Old tail will have a new next
        tail.data = newData;          //Put new data in old tail
        tail = tail.next;             //Set the new tail
        length++;                     //Increment the length
    }

    /**
     * Inserts a new node at a specified index
     */
    public void insert(int newData, int index) {
        moveCurrent(index);           //Move to the insertion point
        this.insert(newData);         //Insert the new data here
    }

    /**
     * Inserts a new node at the current index
     */
    public void insert(int newData) {
        Node temp = new Node();       //Create a new node
        temp.data = current.data;     //Place the current node's data to the new node
        temp.next = current.next;     //Make the new node point to the current node

        current.next = temp;          //Make the current node point to this node
        current.data = newData;       //Place the new data in the current node

        if(tail == current) {
            tail = current.next;      //Update the tail reference if necessary
        }
        length++;
    }

    /**
     * Moves the current reference to the desired node
     * @param index
     */
    public void moveCurrent(int index) {
        //Check if valid index
        if(index < 0 || index > length) {
            throw new IndexOutOfBoundsException("Index " + index + " of out bounds.");
        }
        current = head.next;                            //Start at head
        for(int i=0; i<index; i++) {
            current = current.next;                     //Iterate to desired node
        }
    }

    /**
     * Move the current reference back one node
     */
    public void back() {
        if (head.next == current) {
            return;                             // No previous element
        }
        Node temp = head;                       //Start at head
        while(temp.next != current) {
            temp = temp.next;                   //Keep going until the current node is reached
        }
        current = temp;                         //Update current
    }

    /**
     * Move the current reference forward one node
     */
    public void next() {
        if(current != tail) {
            current = current.next;
        }
    }

    /**
     * Removes a node from a specified index
     */
    public void remove(int index) {
        moveCurrent(index);           //Move to the removal point
        this.remove();
    }

    /**
     * Removes a node from a specified index
     */
    public void remove() {
        if(current == tail) {
            // No current element
            throw new NoSuchElementException("No element at this index");
        }
        current.data = current.next.data;           //Pull forward the next node's data
        if(current.next == tail) {
            tail = current;                         //Removed the last element
        }
        current.next = current.next.next;           //Point around the removed node
        length--;
    }

    /**
     * Retrieves the data from the node at the current location
     */
    public int get(int index) {
        this.moveCurrent(index);
        return this.get();
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
     * Retrieves the current length of the list
     */
    public int getLength() {
        return length;
    }

    /**
     * Check if the current index is the tail
     * @return
     */
    public boolean isAtEnd() {
        return current == tail;
    }

    /**
     * Prints the data in the list
     */
    public void printList() {
        Node temp = head.next;
        while(temp != tail) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

}
