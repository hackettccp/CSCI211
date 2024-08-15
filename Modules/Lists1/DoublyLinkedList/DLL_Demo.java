package DoublyLinkedList;

public class DLL_Demo {

    public static void main(String[] args) {
        DLinkedList d = new DLinkedList();
        d.push(3);                          // 3
        d.push(5);                          // 3 5
        d.push(7);                          // 3 5 7
        d.push(9);                          // 3 5 7 9
        d.printListForward();
        d.printListReverse();

        d.insert(22, 2);                    // 3 5 22 7 9
        d.printListForward();
        d.printListReverse();

        d.remove(1);                        // 3 22 7 9
        d.printListForward();
        d.printListReverse();
        System.out.println();


        for(int i = 0; i < d.getLength(); i++) {
            System.out.println(d.get(i));
        }
        System.out.println();


        for(int i = d.getLength()-1; i >= 0; i--) {
            System.out.println(d.get(i));
        }
        System.out.println();


        d.moveCurrent(0);
        do {
            System.out.println(d.get());
            d.next();
        } while(!d.isAtEnd());
        System.out.println();


        d.moveCurrent(d.getLength()-1);
        while(!d.isAtStart()) {
            System.out.println(d.get());
            d.back();
        }

    }

}
