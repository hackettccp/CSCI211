package Resizing;

/**
 * Hash Table with collision resolution (open addressing) and resize capability
 */
public class HashTable {

    private KVP[] map;                 //Array of KVPs
    private int size;                  //Size of the array/table
    private int count;                 //Table utilization
    private boolean skip = false;      //Flag for skipping resize checks when rehashing

    /**
     * Constructor
     * @param sizeIn Table size
     */
    public HashTable(int sizeIn) {
        size = sizeIn;
        map = new KVP[size];
        count = 0;
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
        return hash % size;
    }

    /**
     * Puts (or updates) a KVP in the table
     * @param key
     * @param value
     */
    public void put(String key, String value) {
        int hashValue = hashFunction(key);                         //Calculates the hash value
        int start = hashValue;                                     //Starts looking at the computed hash value/index
        while(map[hashValue] != null && !map[hashValue].getKey().equals(key)) {
            hashValue = (hashValue + 1) % size;
            if(start == hashValue) {
               throw new RuntimeException("Table is full.");
            }
        }
        map[hashValue] = new KVP(key, value);                               //Place the new KVP

        count++;
        if(!skip && count > size * .90) {                                   //If more than 90% full
            rehash(false);                                                  //Grow the table
        }
    }

    /**
     * Retrieves the value for a key
     * @param key
     * @return Value associated with the specified key
     */
    public String get(String key) {
        int hashValue = hashFunction(key);                                //Calculates the hash value
        int start = hashValue;                                              //Starts looking at the computed hash value/index
        //System.out.println("Getting key " + key + " at hash/index " + hashValue);
        while(map[hashValue] != null && !map[hashValue].getKey().equals(key)) {
            hashValue = (hashValue + 1) % size;
            //System.out.println("Not there. New hash/index to try " + hashValue);
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
            hashValue = (hashValue + 1) % size;
        } while (start != hashValue);

        if(map[hashValue] != null && found == true) {
            map[hashValue] = null;
            count--;
            if(size > 127 && count < (size * .50)) {                        //If more than 50% empty
                rehash(true);                                               //Shrink the table
            }
        }
    }

    /**
     * Resizes the table
     * @param shrink true indicates shrink
     */
    public void rehash(boolean shrink) {
        int oldSize = size;                                          //Get the old size
        KVP[] temp = map;                                            //Reference to the existing map

        System.out.println("Count: " + count);
        if(shrink) {
            size -= (int)(size * .25);                                       //Decrease by 25%
            if(size < 127) {
                size = 127;
            }
            System.out.println("Old size: " + oldSize);
            System.out.println("Resizing/Shrinking to: " + size);
        }
        else {
            size = size * 2;                                                //Double the size
            System.out.println("Old size: " + oldSize);
            System.out.println("Resizing/Growing to: " + size);
        }

        map = new KVP[size];                                               //Create a new map/array of KVPs
        count = 0;

        //Move the elements from the old map to the new one
        //The put function will rehash the KVPs into the new map
        skip = true;   //Stop checking size/utilization while rehashing
        for(int i = 0; i < oldSize; i++) {
            if(temp[i] != null) {
                put(temp[i].getKey(), temp[i].getValue());          //Put the existing KVP into the new map
            }
        }
        skip = false;  //Start checking size/utilization again after rehashing
    }

    /**
     * Returns the table utilization/count
     * @return count
     */
    public int getCount() {
        return count;
    }

}
