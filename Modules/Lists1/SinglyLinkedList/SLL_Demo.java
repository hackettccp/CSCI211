package SinglyLinkedList;

public class SLL_Demo {

    public static void main(String[] args) {
        SLinkedList s = new SLinkedList();
        s.push(3);                      // 3
        s.push(5);                      // 3 5
        s.push(7);                      // 3 5 7
        s.push(9);                      // 3 5 7 9
        s.printList();

        s.insert(22, 2);                // 3 5 22 7 9
        s.printList();

        s.remove(3);                    // 3 5 22 9
        s.printList();

        for(int i = 0; i < s.getLength(); i++) {
            System.out.println(s.get(i));
        }
        System.out.println();

        s.moveCurrent(0);
        do {
            System.out.println(s.get());
            s.next();
        } while(!s.isAtEnd());

    }

}
