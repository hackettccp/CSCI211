package SimpleHashTable;

public class KVP {

    private int key;            //The Key
    private String value;       //The Value

    /**
     * Constructor
     * @param k - Key
     * @param v - Value
     */
    public KVP(int k, String v) {
        key = k;
        value = v;
    }

    /**
     * Accessor for the key
     * @return key
     */
    public int getKey() {
        return key;
    }

    /**
     * Accessor for the value
     * @return value
     */
    public String getValue() {
        return value;
    }

    /**
     * Mutator for the value
     * @param v - New value
     */
    public void setValue(String v) {
        value = v;
    }
}
