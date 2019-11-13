import java.util.Iterator;
import java.util.PriorityQueue;

/**
 * Demonstrates a priority queue with ints.
 */
public class PriorityQueueExample {

    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();      //Priority Queue of ints

        pq.add(5);                                              //Adds 5 to the priority queue
        pq.add(2);                                              //Adds 2 to the priority queue
        pq.add(4);                                              //Adds 4 to the priority queue
        pq.add(1);                                              //Adds 1 to the priority queue
        pq.add(3);                                              //Adds 3 to the priority queue

        Iterator<Integer> iterator = pq.iterator();             //Iterates through the priority queue
        while(pq.size() > 0) {
            System.out.println(iterator.next());                //Print the value at the front of the priority queue
            iterator.remove();                                  //Remove the value at the front of the priority queue
        }
    }

}
