package Queues;

public class DequeDemo {

    public static void main(String[] args) {
        Deque d = new Deque();
        System.out.println("Pushing 1, 2, and 3 to back");
        d.pushBack(1);                                          // 1
        d.pushBack(2);                                          // 1 2
        d.pushBack(3);                                          // 1 2 3
        System.out.println("Pushing 4, 5, and 6 to front");
        d.pushFront(4);                                         // 4 1 2 3
        d.pushFront(5);                                         // 5 4 1 2 3
        d.pushFront(6);                                         // 6 5 4 1 2 3
        System.out.println("Deque length: " + d.size());
        System.out.println("Peeking at front: " + d.peekFront());
        System.out.println("Peeking at back: " + d.peekBack());
        int frontValue = d.popFront();
        System.out.println("Popped from front: " + frontValue);
        int backValue = d.popBack();
        System.out.println("Popped from back: " + backValue);
        System.out.println("Deque length: " + d.size());
        System.out.println("Peeking at front: " + d.peekFront());
        System.out.println("Peeking at back: " + d.peekBack());
        System.out.println();

        System.out.println("Deque length: " + d.size());
        System.out.println("\nEmptying...");
        while(!d.isEmpty()) {
            System.out.println("Popped from front: " + d.popFront());
            System.out.println("Deque length: " + d.size());
        }
        System.out.println("Done");
        System.out.println();

        System.out.println("Trying to pop the next item (there aren't any)");
        try {
            d.popFront();
        }
        catch(RuntimeException e) {
            System.out.println("Exception handled - " + e.getMessage());
        }
    }

}
