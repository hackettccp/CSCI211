package SampleCode;

import java.util.Arrays;

public class ObjectSort {

    InventoryItem[] items;

    /**
     * Constructor.
     */
    public ObjectSort() {
        items = new InventoryItem[5];
        items[0] = new InventoryItem("Hammer", 5.99, 10);
        items[1] = new InventoryItem("Wrench", 8.95, 6);
        items[2] = new InventoryItem("Saw", 11.98, 18);
        items[3] = new InventoryItem("Duct Tape", 3.99, 12);
        items[4] = new InventoryItem("Pliers", 5.99, 11);
    }

    /**
     * Run Method.
     */
    public void run() {
        System.out.println("Unsorted objects: ");
        printArray(items);

        Arrays.sort(items);

        System.out.println("Sorted objects (by quantity): ");
        printArray(items);
    }

    /**
     * Prints the contents of an array
     */
    public void printArray(InventoryItem[] a) {
        for(int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
        System.out.println();
    }

    /**
     * Main Method.
     */
    public static void main(String[] args) {
        ObjectSort os = new ObjectSort();
        os.run();
    }

}
