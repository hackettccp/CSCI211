package SimpleHashTable;

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
     * Puts a value into the array at the hashed index
     * @param key - Key to hash
     * @param value - Value to be stored
     */
    public void put(int key, String value) {
        int hashValue = key % SIZE;                                //Calculates the hash value
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
    public String get(int key) {
        int hashValue = key % SIZE;                                //Calculates the hash value
        if(map[hashValue] != null) {
            //Check the keys match
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
    public boolean remove(int key) {
        int hashValue = key % SIZE;                                //Calculates the hash value
        if(map[hashValue] != null) {
            if(map[hashValue].getKey() == key) {
                map[hashValue] = null;                             //Set the array position to null
                return true;
            }
        }
        return false;                                              //KVP not there; Nothing to delete
    }

}
