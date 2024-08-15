package ClosedHashing;

/**
 * Hash Table with collision resolution (open addressing)
 */
public class HashTable {

    private KVP[] map;                     //Array of KVPs
    private final int SIZE;                //Size of the array/table

    /**
     * Constructor
     * @param sizeIn Table size
     */
    public HashTable(int sizeIn) {
        SIZE = sizeIn;
        map = new KVP[SIZE];
    }

    /**
     * Calculates the index for the supplied key
     * @param key Key to hash
     * @return Hashed index
     */
    public int hashFunction(String key) {
        int hash = 0;
        for(int i = 0; i < key.length(); i++) {
            hash = hash + key.charAt(i);
        }
        return hash % SIZE;
    }

    /**
     * Puts (or updates) a KVP in the table
     * @param key
     * @param value
     */
    public void put(String key, String value) {
        int hashValue = hashFunction(key);                         //Calculates the hash value
        System.out.println("Putting " + key + ":" + value +
                           " at hash/index " + hashValue);
        int start = hashValue;                                     //Starts looking at the computed hash value/index
        while(map[hashValue] != null && !map[hashValue].getKey().equals(key)) {
            hashValue = (hashValue + 1) % SIZE;
            System.out.println("Collision. New hash/index to try " + hashValue);
            System.out.println("Putting " + key + ":" + value + " at hash/index " + hashValue);
            if(start == hashValue) {
               throw new RuntimeException("Table is full.");
            }
        }
        map[hashValue] = new KVP(key, value);                               //Place the new KVP
    }

    /**
     * Retrieves the value for a key
     * @param key
     * @return Value associated with the specified key
     */
    public String get(String key) {
        int hashValue = hashFunction(key);                                //Calculates the hash value
        System.out.println("Getting key " + key + " at hash/index " + hashValue);
        int start = hashValue;                                              //Starts looking at the computed hash value/index
        while(map[hashValue] != null && !map[hashValue].getKey().equals(key)) {
            hashValue = (hashValue + 1) % SIZE;
            System.out.println("Not there. New hash/index to try " + hashValue);
            if(start == hashValue) {
                throw new RuntimeException("Key not found.");
            }
        }
        if(map[hashValue] == null) {
            throw new RuntimeException("Key not found.");
        }
        return map[hashValue].getValue();
    }

    /**
     * Removes a KVP from the table
     * @param key
     */
    public void remove(String key) {
        int hashValue = hashFunction(key);                                //Calculates the hash value
        int start = hashValue;
        boolean found = false;

        do {
            if(map[hashValue] != null && map[hashValue].getKey().equals(key)) {
                found = true;
                break;
            }
            hashValue = (hashValue + 1) % SIZE;
        } while (start != hashValue);


        if(map[hashValue] != null && found == true) {
            map[hashValue] = null;
        }
    }

}
