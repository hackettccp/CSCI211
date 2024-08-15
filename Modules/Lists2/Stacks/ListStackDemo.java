package Stacks;

public class ListStackDemo {

    public static void main(String[] args) {
        ListStack s = new ListStack();

        s.push(5);
        s.push(75);
        s.push(23);
        s.push(12);
        s.push(44);
        System.out.println("Peeking at top: " + s.peek());
        System.out.println("Popping from top: " + s.pop());
        System.out.println("Peeking at top: " + s.peek());

        s.push(56);
        s.push(65);
        s.push(11);
        s.push(9);
        s.push(45);
        s.push(8);

        System.out.println("Peeking at top: " + s.peek());
        int value = s.pop();
        System.out.println("Popping from top: " + value);
        System.out.println("Peeking at top: " + s.peek());

        System.out.println();

        System.out.println("Utilization: " + s.getSize());

        while(!s.isEmpty()) {
            System.out.println("Popped value: " + s.pop());
            System.out.println("Utilization: " + s.getSize());
        }

    }

}
