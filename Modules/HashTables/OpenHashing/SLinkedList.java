package OpenHashing;

import java.util.NoSuchElementException;

/**
 * Implementation of a Singly Linked List
 */
public class SLinkedList {

    /**
     * Implementation of a Node in this Singly Linked List
     */
    private class Node {
        KVP data;
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
     * Appends a new node/KVP to the end of the list.
     */
    public void push(KVP newKVP) {
        Node temp = head.next;

        while(temp != tail && (temp.data.getKey() != newKVP.getKey())) {
            temp = temp.next;                       //Get the next KVP in the bucket
        }

        if(temp == tail) {                          //NEW KVP (Unique Key)
            Node newNode = new Node();
            tail.next = newNode;
            tail.data = newKVP;
            tail = tail.next;                       //Sets the bucket's tail to point to the new KVP (the new tail)
        }
        else {                                      //EXISTING KEY
            temp.data = newKVP;                     //Replaces the existing KVP with the new KVP
        }

        length++;                                   //Increment the length
    }

    /**
     * Retrieves the data from the node with the specified key/KVP
     */
    public String get(int key) {
        current = head.next;

        while(current != tail && (current.data.getKey() != key)) {
            current = current.next;                       //Get the next KVP in the bucket
        }

        if(current == tail) {                          //Key doesn't match any existing KVPs
            throw new NoSuchElementException("No KVP for the key: " + key);
        }

        return current.data.getValue();
    }

    /**
     * Removes a node containing a specified key/KVP
     */
    public void remove(int key) {
        current = head.next;

        while(current != tail && (current.data.getKey() != key)) {
            current = current.next;                       //Get the next KVP in the bucket
        }

        if(current == tail) {                          //Key doesn't match any existing KVPs
            throw new NoSuchElementException("No KVP for the key: " + key);
        }

        current.data = current.next.data;           //Pull forward the next node's data
        if(current.next == tail) {
            tail = current;                         //Removed the last element
        }
        current.next = current.next.next;           //Point around the removed node
        length--;

    }

    /**
     * Retrieves the current length of the list
     */
    public int getLength() {
        return length;
    }

}
