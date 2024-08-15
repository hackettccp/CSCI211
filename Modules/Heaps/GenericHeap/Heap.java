package GenericHeap;

/**
 * Generic Heap Class
 * Extended by MinHeap and MaxHeap classes
 */
public abstract class Heap {

    /**
     * Adds an object to the heap
     * Defined by the extending class
     * How objects are added depends on if it is a max or min heap
     * @param data
     */
    abstract public void add(HeapObject data);

    /**
     * Reorganizes the heap after a removal
     * Defined by the extending class
     * How objects are reorganized depends on if it is a max or min heap
     */
    abstract protected void fixHeap();

    /**
     * Maximum size of the heap
     */
    protected final int SIZE;

    /**
     * The heap's array
     */
    protected HeapObject[] array;

    /**
     * Keeps track of the next available index to store a new object
     */
    protected int nextAvail;

    /**
     * Constructor
     * @param s - heap size
     */
    public Heap(int s) {
        SIZE = s;
        array = new HeapObject[SIZE];
        nextAvail = 1;
    }

    /**
     * Removes the object at the top of the heap
     * @return Object at the top of the heap
     * @throws Exception Empty heap
     */
    public HeapObject remove() throws Exception {
        if(array[1] == null) {
            throw new Exception("Heap is empty");
        }

        HeapObject r = array[1];                //Store the root
        nextAvail--;                            //Decrement the index for next available
        if(nextAvail == 1) {
            //Heap is now empty
            array[nextAvail] = null;
        }
        else {
            array[1] = array[nextAvail];        //Put the most recently added object at the root
            array[nextAvail] = null;
            fixHeap();                          //Reorganize/Promote children
        }

        //Return the removed node
        return r;
    }

    /**
     * Returns if the heap is empty or not
     * @return true/false
     */
    public boolean isEmpty() {
        return nextAvail == 1 ? true : false;
    }

    /**
     * Helper function to calculate the index of an object's parent
     * @param i - object's index in the heap
     * @return parent's index
     */
    protected int getParentIndex(int i) {
        return i / 2;
    }

    /**
     * Helper function to swap two objects in the heap's array
     * @param i - index of object 1
     * @param j - index of object 2
     */
    protected void swap(int i, int j) {
        HeapObject temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    /**
     * Helper function to calculate an object's left child's index
     * @param i - index
     * @return left child's index
     */
    protected int getLeftChildIndex(int i) {
        return i * 2;
    }

    /**
     * Helper function to calculate an object's right child's index
     * @param i - index
     * @return right child's index
     */
    protected int getRightChildIndex(int i) {
        return i * 2 + 1;
    }

    /**
     * Helper function to determine if an object has children
     * @param i object's index
     * @return true/false
     */
    protected boolean hasChildren(int i) {
        int left = getLeftChildIndex(i);
        int right = getRightChildIndex(i);
        if(left >= SIZE) {
            return false;
        }
        else if(array[left] == null && array[right] == null) {
            return false;
        }
        else {
            return true;
        }
    }

}
