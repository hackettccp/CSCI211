package Queues;

public class QueueDemo {

    public static void main(String[] args) {
        Queue q = new Queue();
        System.out.println("Pushing 1, 2, and 3");
        q.push(1);
        q.push(2);
        q.push(3);
        System.out.println("Queue length: " + q.getSize());
        System.out.println("Peeking at front: " + q.peek());
        System.out.println("Popping from front: " + q.pop());
        System.out.println("Queue length: " + q.getSize());
        System.out.println("Peeking at front: " + q.peek());
        System.out.println();

        System.out.println("Pushing 4, 5, and 6");
        q.push(4);
        q.push(5);
        q.push(6);
        System.out.println("Queue length: " + q.getSize());
        System.out.println( "Peeking at front: " + q.peek());
        int value = q.pop();
        System.out.println("Popped from front: " + value);
        System.out.println("Queue length: " + q.getSize());
        System.out.println("Peeking at front: " + q.peek());
        System.out.println();

        System.out.println("Pushing 7 and 8");
        q.push(7);
        q.push(8);

        System.out.println("Queue length: " + q.getSize());
        System.out.println("\nEmptying...");
        while(!q.isEmpty()) {
            System.out.println("Popped " + q.pop());
            System.out.println("Queue length: " + q.getSize());
        }
        System.out.println("Done");

        System.out.println("Trying to pop the next item (there aren't any)");
        try {
            q.pop();
        }
        catch(RuntimeException e) {
            System.out.println("Exception handled - " + e.getMessage());
        }
    }

}
