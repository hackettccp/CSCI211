import java.util.HashMap;

public class HashMapDemo {

    public static void main(String[] args) {
        //<Data type of key, Data type of value>
        HashMap<String, Integer> hm = new HashMap<String, Integer>();

        hm.put("ABC", 1);
        hm.put("DEF", 2);
        hm.put("GHI", 3);

        System.out.println(hm.get("DEF"));          //Returns 2
        System.out.println(hm.get("ABC"));          //Returns 3

        System.out.println(hm.get("ZZZ"));          //Returns null

        hm.put("ABC", 9);
        System.out.println(hm.get("ABC"));          //Returns 9

        //Allows one null key
        hm.put(null, 6);
        System.out.println(hm.get(null));           //Returns 6

        //Allows null values
        hm.put("XYZ", null);
        System.out.println(hm.get("XYZ"));          //Returns null
    }
}
