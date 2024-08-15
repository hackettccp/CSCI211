package ClosedHashing;

public class OpenAddressingDemo {

    public static void main(String[] args) {
        HashTable ht = new HashTable(10);
        ht.put("ABC1", "ABC Corporation");
        ht.put("XYZ1", "XYZ Associates");
        ht.put("DE01", "D&E Company");
        ht.put("FGH1", "FGH Inc.");

        System.out.println("Key:XYZ1 Value:" + ht.get("XYZ1"));
        System.out.println("Key:ABC1 Value:" + ht.get("ABC1"));
        System.out.println("\n");

        //Collides with ABC1
        ht.put("CBA1", "CBA Inc.");
        System.out.println();
        System.out.println("Key:ABC1 Value:" + ht.get("ABC1"));
        System.out.println("Key:CBA1 Value:" + ht.get("CBA1"));
        System.out.println("\n");

        //Non-existent KVP
        try {
            ht.get("BBB1");
        }
        catch(RuntimeException e) {
            System.out.println("Exception: " + e.getMessage());
        }
        System.out.println("\n");

        //Fills the table (last KVP causes an overflow)
        try {
            ht.put("ABC2", "ABC Corporation");
            ht.put("XYZ2", "XYZ Associates");
            ht.put("DE02", "D&E Company");
            ht.put("FGH2", "FGH Inc.");
            ht.put("ABC3", "ABC Corporation");
            ht.put("XYZ3", "XYZ Associates");
            ht.put("DE10", "D&E Company");
            ht.put("FG1H", "FGH Inc.");
        }
        catch(RuntimeException e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }

}
