package Queues;

/**
 * Implementation of a double-ended queue using a doubly-linked list.
 */
public class Deque {

    private DLinkedList dequeList;     //The linked list used to store the deque's data

    /**
     * Constructor
     */
    public Deque() {
        dequeList = new DLinkedList();
    }

    /**
     * push method. Adds data to the back of the deque.
     * @param newData - Data to push onto the deque
     */
    public void pushBack(int newData) {
        dequeList.moveToEnd();
        dequeList.push(newData);
    }

    /**
     * push method. Adds data to the front of the deque.
     * @param newData - Data to push onto the deque
     */
    public void pushFront(int newData) {
        dequeList.moveToStart();
        dequeList.insert(newData);
    }

    /**
     * pop method. Removes and retrieves the data from the back of the deque.
     * @return - Data at the back of the deque
     */
    public int popBack() {
        if(dequeList.getLength() == 0) {
            throw new RuntimeException("Deque is empty.");       //Deque is empty
        }
        dequeList.moveToEnd();
        int data = dequeList.get();                              //Get the data at the back of the deque
        dequeList.remove();                                      //Remove it
        return data;                                             //Return the data
    }

    /**
     * pop method. Removes and retrieves the data at the front of the deque.
     * @return - Data at the front of the deque
     */
    public int popFront() {
        if(dequeList.getLength() == 0) {
            throw new RuntimeException("Deque is empty.");       //Deque is empty
        }
        dequeList.moveToStart();
        int data = dequeList.get();                              //Get the data at the front of the deque
        dequeList.remove();                                      //Remove it
        return data;                                             //Return the data
    }

    /**
     * peek method. Retrieves the data from the back of the deque.
     * @return - Data at the back of the deque
     */
    public int peekBack() {
        if(dequeList.getLength() == 0) {
            throw new RuntimeException("Deque is empty.");       //Deque is empty
        }
        dequeList.moveToEnd();
        return dequeList.get();        //Return the data at the back of the deque
    }

    /**
     * peek method. Retrieves the data at the front of the deque.
     * @return - Data at the front of the deque
     */
    public int peekFront() {
        if(dequeList.getLength() == 0) {
            throw new RuntimeException("Deque is empty.");       //Deque is empty
        }
        dequeList.moveToStart();
        return dequeList.get();        //Get the data at the front of the deque
    }

    /**
     * size method. Retrieves the current usage of the queue
     * @return - Queue's utilization
     */
    public int size() {
        return dequeList.getLength();
    }

    /**
     * isEmpty method. Determines if the queue is empty.
     * @return - True if queue is empty
     */
    public boolean isEmpty() {
        return dequeList.getLength() == 0 ? true : false;      //Returns true if list is empty
    }

}
