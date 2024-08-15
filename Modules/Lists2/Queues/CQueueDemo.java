package Queues;

public class CQueueDemo {

    public static void main(String[] args) {
        CQueue cq = new CQueue(5);
        System.out.println("Pushing 1, 2, and 3");
        cq.push(1);
        cq.push(2);
        cq.push(3);
        System.out.println("Queue length: " + cq.size());
        System.out.println("Peeking at top: " + cq.peek());
        System.out.println("Popping from top: " + cq.pop());
        System.out.println("Queue length: " + cq.size());
        System.out.println("Peeking at top: " + cq.peek());
        System.out.println();

        System.out.println("Pushing 4, 5, and 6");
        cq.push(4);
        cq.push(5);
        cq.push(6);
        System.out.println("Queue length: " + cq.size());
        System.out.println( "Peeking at top: " + cq.peek());
        int value = cq.pop();
        System.out.println("Popped from top: " + value);
        System.out.println("Queue length: " + cq.size());
        System.out.println("Peeking at top: " + cq.peek());
        System.out.println();

        System.out.println("Pushing 7");
        cq.push(7);

        System.out.println("Pushing 8");
        try {
            cq.push(8);
        }
        catch(RuntimeException e) {
            System.out.println("Exception handled - " + e.getMessage());
        }

        System.out.println("Queue length: " + cq.size());
        System.out.println("\nEmptying...");
        while(!cq.isEmpty()) {
            System.out.println("Popped " + cq.pop());
            System.out.println("Queue length: " + cq.size());
        }
        System.out.println("Done");

        System.out.println("Trying to pop the next item (there aren't any)");
        try {
            cq.pop();
        }
        catch(RuntimeException e) {
            System.out.println("Exception handled - " + e.getMessage());
        }
    }

}
