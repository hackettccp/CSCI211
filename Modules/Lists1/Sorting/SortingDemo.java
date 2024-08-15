package Sorting;

public class SortingDemo {

    public static void main(String[] args) {
        SLinkedList s = new SLinkedList();
        s.push(11);
        s.push(7);
        s.push(3);
        s.push(5);
        s.push(1);
        s.push(9);

        System.out.println("Unsorted:");
        s.printList();
        s.bubbleSort();
        System.out.println("Sorted:");
        s.printList();

        System.out.println();

        DLinkedList d = new DLinkedList();
        d.push(11);
        d.push(7);
        d.push(3);
        d.push(5);
        d.push(1);
        d.push(9);

        System.out.println("Unsorted:");
        d.printListForward();
        d.insertionSort();
        System.out.println("Sorted:");
        d.printListForward();

    }



}
