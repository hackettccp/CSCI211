package Queues;

/**
 * Implementation of a circular queue (using an array)
 */
public class CQueue {

    private int max;                   //Queue's capacity
    private int front;                 //References the array index of the front element
    private int back;                  //References the array index of the back element
    private int[] a;                   //The array the queue will use
    private int count;                 //Number of items in the queue

    /**
     * Constructor
     * @param sizeIn
     */
    public CQueue(int sizeIn) {
        max = sizeIn;                   //Sets the capacity
        a = new int[max];               //Instantiates the array
        front = -1;
        back = -1;
        count = 0;
    }

    /**
     * push method. Adds data to the back of the queue.
     * @param newData - Data to add to the queue
     */
    public void push(int newData) {
        if(count == max) {
            throw new RuntimeException("Queue is full");    //Checks if the queue is full
        }
        else if(front == -1) {
            front = 0;                                      //Checks if the queue is empty
            back = 0;
        }
        else if(back == max-1) {
            back = 0;                                       //Check if the queue needs to wrap the back around to index 0
        }
        else {
            back++;                                         //Increment the back index
        }
        a[back] = newData;                                  //Store the data
        count++;                                            //Increment the count
    }

    /**
     * pop method. Removes and retrieves the data at the front of the queue.
     * @return - Data at the front of the queue.
     */
    public int pop() {
        if(front == -1) {
            throw new RuntimeException("Queue is empty");   //Checks if the queue is empty
        }
        int temp = a[front];                                //Gets the data from the front
        if(front == back) {
            front = -1;                                     //Queue will now be empty
            back = -1;
        }
        else if(front == max-1) {
            front = 0;                                      //Wrap the front around to index 0
        }
        else {
            front++;                                        //Increment the front index
        }
        count--;                                            //Decrement the count
        return temp;                                        //Return the data
    }

    /**
     * peek method. Retrieves (but does not remove) the data at the front of the queue.
     * @return - Data at the front of the queue.
     */
    public int peek() {
        if(front == -1) {
            throw new RuntimeException("Queue is empty");      //Checks if the queue is empty
        }
        return a[front];
    }

    /**
     * isEmpty method. Determines if the queue is empty.
     * @return - True if the queue is empty
     */
    public boolean isEmpty() {
        return front == -1 ? true : false;
    }

    /**
     * isFull method. Determines if the queue is full.
     * @return - True if the queue is full
     */
    public boolean isFull() {
        return count == max ? true : false;
    }

    /**
     * size method. Retrieves the number of items in the queue.
     * @return - Number of elements in the queue
     */
    public int size() {
        return count;
    }

    /**
     * Resets the queue
     * Doesn't need to clear the contents because the array takes up the same space regardless
     */
    public void clear() {
        front = -1;
        back = -1;
        count = 0;
    }

}
