package Sorting;

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

    /**
     * Bubble Sort Algorithm
     */
    public void bubbleSort() {
        Node temp;
        for(int i = 0; i < length-1; i++) {
            temp = head.next;
            for(int j = 0; j < length-i-1; j++) {
                Node t1 = temp;
                Node t2 = temp.next;
                if(t1.data > t2.data) {
                    int t = t2.data;                       //Swap
                    t2.data = t1.data;
                    t1.data = t;
                }
                temp = temp.next;
            }
        }
    }

}
