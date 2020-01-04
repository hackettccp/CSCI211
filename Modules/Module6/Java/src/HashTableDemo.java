import java.util.Hashtable;

public class HashTableDemo {

    public static void main(String[] args) {
        //<Data type of key, Data type of value>
        Hashtable<String, Integer> ht = new Hashtable<String, Integer>();

        ht.put("ABC", 1);
        ht.put("DEF", 2);
        ht.put("GHI", 3);

        System.out.println(ht.get("DEF"));          //Returns 2
        System.out.println(ht.get("ABC"));          //Returns 3

        System.out.println(ht.get("ZZZ"));          //Returns null

        ht.put("ABC", 9);
        System.out.println(ht.get("ABC"));          //Returns 9

        //No null keys
        try {
            ht.put(null, 6);                        //Null Pointer Exception
            System.out.println(ht.get(null));
        }
        catch (NullPointerException e) {
            System.out.println("Null keys not allowed.");
        }

        //No null values
        try {
            ht.put("XYZ", null);                    //Null Pointer Exception
            System.out.println(ht.get("XYZ"));
        } catch (NullPointerException e) {
            System.out.println("Null values not allowed.");
        }
    }
}
