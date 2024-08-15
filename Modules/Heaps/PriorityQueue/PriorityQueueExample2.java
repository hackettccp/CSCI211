package PriorityQueue;

import java.util.Iterator;
import java.util.PriorityQueue;

/**
 * Demonstrates a priority queue with objects.
 */
public class PriorityQueueExample2 {

    public static void main(String[] args) {
        PriorityQueue<TestObject> pq = new PriorityQueue<>();   //Priority Queue of TestObjects

        pq.add(new TestObject(5));                              //Adds 5 to the priority queue
        pq.add(new TestObject(2));                              //Adds 2 to the priority queue
        pq.add(new TestObject(4));                              //Adds 4 to the priority queue
        pq.add(new TestObject(1));                              //Adds 1 to the priority queue
        pq.add(new TestObject(3));                              //Adds 3 to the priority queue


        Iterator<TestObject> iterator = pq.iterator();          //Iterates through the priority queue
        while(pq.size() > 0) {
            System.out.println(iterator.next().value);          //Print the value of the object in the front of the priority queue
            iterator.remove();                                  //Remove the object at the front of the priority queue
        }
    }

}

