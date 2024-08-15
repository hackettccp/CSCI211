package OpenHashing;

/**
 * Hash Table with collision resolution (closed addressing)
 */
public class HashTable {

    private SLinkedList[] buckets;             //Array of KVPs
    private final int SIZE;                    //Size of the array/table

    /**
     * Constructor
     * @param sizeIn Table size
     */
    public HashTable(int sizeIn) {
        SIZE = sizeIn;
        buckets = new SLinkedList[SIZE];
        for(int i = 0; i < buckets.length; i++) {
            buckets[i] = new SLinkedList();
        }
    }

    /**
     * Calculates the index for the supplied key
     * @param key Key to hash
     * @return Hashed index
     */
    public int hashFunction(int key) {
        return key % SIZE;
    }

    /**
     * Puts (or updates) a KVP into the appropriate bucket
     * @param key
     * @param value
     */
    public void put(int key, String value) {
        int hashValue = hashFunction(key);                         //Calculates the hash value
        KVP temp = new KVP(key, value);                            //Create the new KVP
        buckets[hashValue].push(temp);                             //Push it to that bucket (push function checks for duplicate keys)
    }

    /**
     * Retrieves a KVP from the appropriate bucket
     * @param key
     * @return Value associated with that key
     */
    public String get(int key) {
        int hashValue = hashFunction(key);                                //Calculates the hash value
        return buckets[hashValue].get(key);
    }

    /**
     * Removes a KVP from the appropriate bucket
     * @param key
     */
    public void remove(int key) {
        int hashValue = hashFunction(key);                                //Calculates the hash value
        buckets[hashValue].remove(key);
    }

}
