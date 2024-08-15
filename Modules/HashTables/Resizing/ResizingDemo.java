package Resizing;

public class ResizingDemo {

    public static void main(String[] args) {
        HashTable ht = new HashTable(127);
        System.out.println("Adding 200 KVPs");
        for(int i = 1; i < 201; i++) {
            ht.put(String.valueOf(i), "VALUE" + i);
        }
        System.out.println("Total KVPS = " + ht.getCount());
        System.out.println("\n");

        System.out.println("Adding 200 more KVPs");
        for(int i = 201; i < 401; i++) {
            ht.put(String.valueOf(i), "VALUE" + i);
        }
        System.out.println("Total KVPS = " + ht.getCount());
        System.out.println("\n");

        System.out.println("Adding 200 more KVPs");
        for(int i = 401; i < 601; i++) {
            ht.put(String.valueOf(i), "VALUE" + i);
        }
        System.out.println("Total KVPS = " + ht.getCount());
        System.out.println("\n");



        System.out.println("Removing 200 KVPs");
        for(int i = 401; i < 601; i++) {
            ht.remove(String.valueOf(i));
        }
        System.out.println("Total KVPS = " + ht.getCount());
        System.out.println("\n");

        System.out.println("Removing 200 more KVPs");
        for(int i = 201; i < 401; i++) {
            ht.remove(String.valueOf(i));
        }
        System.out.println("Total KVPS = " + ht.getCount());
        System.out.println("\n");

        System.out.println("Removing 200 more KVPs");
        for(int i = 1; i < 201; i++) {
            ht.remove(String.valueOf(i));
        }
        System.out.println("Total KVPS = " + ht.getCount());
        System.out.println("\n");

    }

}
