package DoublyLinkedList;

import java.util.NoSuchElementException;

/**
 * Implementation of a Doubly Linked List
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
     * Inserts a new node at a specified index
     */
    public void insert(int newData, int index) {
        moveCurrent(index);           //Move to the insertion point
        this.insert(newData);         //Insert the new data here
    }

    /**
     * Inserts a new node at a specified index
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

        current.previous.next = current.next;       //Update previous node's next reference
        current.next.previous = current.previous;   //Update next node's previous reference
        current = current.next;                     //Update the current reference

        length--;                                   //Decrement the length
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
     * Move the current reference forward one node
     */
    public void next() {
        if(current != tail) {
            current = current.next;
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
     * Retrieves the current length of the list
     */
    public int getLength() {
        return length;
    }

    /**
     * Check if the current index is the head
     * @return
     */
    public boolean isAtStart() {
        return current == head.next;
    }

    /**
     * Check if the current index is the tail
     * @return
     */
    public boolean isAtEnd() {
        return current == tail;
    }

    /**
     * Prints the data in the list (forwards)
     */
    public void printListForward() {
        Node temp = head.next;
        while(temp != tail) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    /**
     * Prints the data in the list (reverse)
     */
    public void printListReverse() {
        Node temp = tail.previous;
        while(temp != head) {
            System.out.print(temp.data + " ");
            temp = temp.previous;
        }
        System.out.println();
    }


}
