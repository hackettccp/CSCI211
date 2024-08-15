package SimpleHashTable;

public class HTDemo {

    public static void main(String[] args) {
        HashTable ht = new HashTable(10);
        ht.put(3456, "ABC Corporation");        //Placed in index 6 (3456 % 10 = 6)
        ht.put(1313, "XYZ Associates");         //Placed in index 3
        ht.put(3765, "D&E Company");            //Placed in index 5

        System.out.println("Value for key 1313: " + ht.get(1313));    //Gets the value for this key (KVP in index 3)
        System.out.println("Value for key 3456: " + ht.get(3456));    //Gets the value for this key (KVP in index 6)

        try {
            ht.put(5513, "FGH Inc.");           //Tried to place in index 3, causing a collision
        }
        catch(IllegalArgumentException e) {
            System.out.println("Exception for key 5513: " + e.getMessage());
        }

        if(ht.remove(3456)) {
            System.out.println("KVP with key 3456 removed.");
        }
        else {
            System.out.println("KVP with key 3456 NOT removed.");
        }

        try {
            ht.get(3456);                       //Was just removed
        }
        catch(IllegalArgumentException e) {
            System.out.println("Exception for key 3456: " + e.getMessage());
        }

        if(ht.remove(9999)) {
            System.out.println("KVP with key 9999 removed.");
        }
        else {
            System.out.println("KVP with key 9999 NOT removed.");
        }
    }

}
