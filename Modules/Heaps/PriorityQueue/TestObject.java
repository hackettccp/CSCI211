package PriorityQueue;

/**
 * Object used in a priority queue.
 */
public class TestObject implements Comparable<TestObject> {

    public int value;                               //Some arbitrary value stored in the object

    /**
     * Constructor
     */
    public TestObject(int v) {
        value = v;
    }

    /**
     * Compares this objects value to another object's
     * Negative result = less than
     * Positive result = greater than
     * Zero result = equal to
     */
    @Override
    public int compareTo(TestObject t) {
        return value - t.value;
    }

}
