package SampleCode;

import java.util.Arrays;

public class ObjectSort2 {

    InventoryItem2[] items;

    /**
     * Constructor.
     */
    public ObjectSort2() {
        items = new InventoryItem2[5];
        items[0] = new InventoryItem2("Hammer", 5.99, 10);
        items[1] = new InventoryItem2("Wrench", 8.95, 6);
        items[2] = new InventoryItem2("Saw", 11.98, 18);
        items[3] = new InventoryItem2("Duct Tape", 3.99, 12);
        items[4] = new InventoryItem2("Pliers", 5.99, 11);
    }

    /**
     * Run Method.
     */
    public void run() {
        System.out.println("Unsorted objects: ");
        printArray(items);

        Arrays.sort(items, new sortByName());                               //Provides a Comparator (contained in InventoryItem2.java) to the Arrays.sort() method.
        System.out.println("Sorted objects (by name): ");
        printArray(items);

        Arrays.sort(items, new sortByPrice());
        System.out.println("Sorted objects (by price): ");
        printArray(items);

        Arrays.sort(items, new sortByQuantity());
        System.out.println("Sorted objects (by quantity): ");
        printArray(items);
    }

    /**
     * Prints the contents of an array
     */
    public void printArray(InventoryItem2[] a) {
        for(int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
        System.out.println();
    }

    /**
     * Main Method.
     */
    public static void main(String[] args) {
        ObjectSort2 os = new ObjectSort2();
        os.run();
    }

}
