package OpenHashing;

import java.util.NoSuchElementException;

public class ClosedAddressingDemo {

    public static void main(String[] args) {
        HashTable ht = new HashTable(100);
        ht.put(3456, "ABC Corporation");        //Placed in Bucket 56 (3456 % 100 = 56)
        ht.put(1313, "XYZ Associates");         //Placed in Bucket 13
        ht.put(3765, "D&E Company");            //Placed in Bucket 65
        ht.put(5513, "FGH Inc.");               //Placed in Bucket 13

        System.out.println("Value for key 1313: " + ht.get(1313));       //Gets the value for this key (KVP in bucket 13)
        System.out.println("Value for key 5513: " + ht.get(5513));       //Gets the value for this key (KVP in bucket 13)
        System.out.println();
        ht.put(1313, "WXYZ Associates");                                 //Will replace the value of existing key 1313
        System.out.println("Value for key 1313: " + ht.get(1313));       //Gets the value for this key (KVP in bucket 13)

        System.out.println();
        try {
            System.out.println("Value for key 1234: " + ht.get(1234));   //Tries to get a value for a key that does not exist
        }
        catch(NoSuchElementException e) {
            System.out.println("Exception: " + e.getMessage());
        }


        //Removing a KVP
        System.out.println();
        try {
            System.out.println("Value for key 3456: " + ht.get(3456));
            System.out.println("Removing value for key 3456");
            ht.remove(3456);                                                //Removes the KVP
        }
        catch(NoSuchElementException e) {
            System.out.println("Exception: " + e.getMessage());
        }

        try {
            System.out.println("Value for key 3456: " + ht.get(3456));     //Tries to get the value for the KVP just removed
        }
        catch(NoSuchElementException e) {
            System.out.println("Exception: " + e.getMessage());
        }


        //Trying to remove a non-existent KVP
        System.out.println();
        try {
            ht.remove(9999);
        }
        catch(NoSuchElementException e) {
            System.out.println("Exception: " + e.getMessage());
        }

    }

}
