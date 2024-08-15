package HashingFunctions;

public class HashFunctionDemo {

    public static void main(String[] args) {
        //RUN EITHER test1 OR test2
        test1();
        //test2();
    }

    /**
     * Keys: 100 through 119
     */
    public static void test1() {
        SimpleHashTable.HashTable origTable = new SimpleHashTable.HashTable(20);  //Simple Hash Table
        HashTable newTable = new HashTable(20);                                   //Hash Table w/ hash function

        //Keep track of collisions
        int origCollisions = 0;
        int newCollisions = 0;

        //Do a put for each key to both tables
        for(int i = 100; i < 120; i++) {
            try {
                origTable.put(i, "test");
            } catch(IllegalArgumentException e) {
                origCollisions++;
            }
            try {
                newTable.put(String.valueOf(i), "test");
            } catch(IllegalArgumentException e) {
                newCollisions++;
            }
        }

        //Print total collisions
        System.out.println("Collisions with original table: " + origCollisions);
        System.out.println("Collisions with new table: " + newCollisions);
    }

    /**
     * Keys: 100, 110, 120, 130 ... 270, 280, 290
     */
    public static void test2() {
        SimpleHashTable.HashTable origTable = new SimpleHashTable.HashTable(20);  //Simple Hash Table
        HashTable newTable = new HashTable(20);                                   //Hash Table w/ hash function

        //Keep track of collisions
        int origCollisions = 0;
        int newCollisions = 0;

        //Do a put for each key to both tables
        for(int i = 100; i < 300; i += 10) {
            try {
                origTable.put(i, "test");
            } catch(IllegalArgumentException e) {
                origCollisions++;
            }
            try {
                newTable.put(String.valueOf(i), "test");
            } catch(IllegalArgumentException e) {
                newCollisions++;
            }
        }

        //Print total collisions
        System.out.println("Collisions with original table: " + origCollisions);
        System.out.println("Collisions with new table: " + newCollisions);
    }



}
