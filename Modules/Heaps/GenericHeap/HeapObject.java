package GenericHeap;

public class HeapObject {

    /**
     * Object's only data field
     */
    private int data;

    /**
     * Constructor
     * @param d - data to set the field
     */
    public HeapObject(int d) {
        data = d;
    }

    /**
     * Replaces/updates the data field
     * @param d - New data
     */
    public void setData(int d) {
        data = d;
    }

    /**
     * Returns the data field
     * @return data
     */
    public int getData() {
        return data;
    }

}
