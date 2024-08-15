package Sorting;

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
     * Insertion Sort Algorithm
     */
    public void insertionSort() {
        if(length <= 1) {
            return;                                                //Check if list can be sorted
        }
        Node sort = head.next.next;                                //Start with index 1
        for(int i = 1; i < length; i++) {
            Node temp = sort.previous;                             //Get the node before the node position we are sorting for
            int sortValue = sort.data;                             //Get the current value in the node position we are sorting for
            while(temp != head && temp.data > sortValue) {
                int t = temp.data;                                 //Get the temporary node's value
                temp.data = sortValue;                             //Swap this node's value with...
                temp.next.data = t;                                //The node directly after it
                temp = temp.previous;                              //Get the next node, going backwards
            }
            sort = sort.next;                                      //Get the next node position to sort for
        }
    }

}
