package HashingFunctions;

/**
 * Simple hash table with no collision resolution
 */
public class HashTable {

    private KVP[] map;             //Array of KVPs
    private final int SIZE;        //Size of the array/table

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
            hash = (31 * hash) + key.charAt(i);
        }
        return hash % SIZE;
    }

    /**
     * Puts a value into the array at the hashed index
     * @param key - Key to hash
     * @param value - Value to be stored
     */
    public void put(String key, String value) {
        int hashValue = hashFunction(key);                         //Calculates the hash value
        if(map[hashValue] == null) {
            KVP temp = new KVP(key, value);                        //Create the new KVP and put it in the array
            map[hashValue] = temp;
        }
        else if(map[hashValue].getKey() == key) {
            map[hashValue].setValue(value);                        //Replace value of existing KVP
        }
        else {
            throw new IllegalArgumentException("Hash Collision");  //A different KVP was already hashed to that location
        }
    }

    /**
     * Retrieves a value based on the key
     * @param key - Key to hash
     * @return Value associated with that key
     */
    public String get(String key) {
        int hashValue = hashFunction(key);                                //Calculates the hash value
        if(map[hashValue] != null) {
            if(map[hashValue].getKey() == key) {
                return map[hashValue].getValue();                  //Return the value of the KVP
            }
        }
        throw new IllegalArgumentException("KVP not found");       //KVP not found
    }

    /**
     * Removes a key-value pair
     * @param key - Key to hash
     * @return true if the KVP was successfully removed
     */
    public boolean remove(String key) {
        int hashValue = hashFunction(key);                                //Calculates the hash value
        if(map[hashValue] != null) {
            if(map[hashValue].getKey() == key) {
                map[hashValue] = null;                             //Set the array position to NULL
                return true;
            }
        }
        return false;                                              //KVP not there; Nothing to delete
    }

}
