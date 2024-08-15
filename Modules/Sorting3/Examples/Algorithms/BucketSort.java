package Examples.Algorithms;

import Examples.ModuleTools;
import java.util.Random;
import java.util.Vector;

public class BucketSort {

    public static void main(String[] args) {
        int LENGTH = 25; //Used to easily change/resize the array for testing with longer or shorter arrays
        int BUCKETS = 5; //Used to easily change the number of buckets to use
        int[] numbers = new int[LENGTH];

        //Fills the array with a sequence of random numbers. (May include some duplicate numbers.)
        Random r = new Random();
        for(int i = 0; i < LENGTH; i++) {
            int rNum = r.nextInt(100) + 1; //Gets a random number between 1 and 100 (0 to 99 + 1 = 1 to 100).
            numbers[i] = rNum;
        }

        ModuleTools.printArray(numbers); //Comment this out if you are using a large array.

        System.out.println("Sorting...");
        bucketSort(numbers, BUCKETS);
        System.out.println("Done.");

        ModuleTools.printArray(numbers); //Comment this out if you are using a large array.
    }

    /**
     * Bucket Sort Algorithm
     */
    public static void bucketSort(int[] a, int numBuckets) {
        Vector[] buckets = new Vector[numBuckets];   //An array of vectors (the vectors will serve as buckets)

        //Initialize each vector
        for(int i = 0; i < buckets.length; i++) {
            buckets[i] = new Vector<Integer>();
        }

        //Determine the max
        int max = ModuleTools.getMax(a);

        //Distribute the array elements into different buckets
        for(int i = 0; i < a.length; i++) {
            int bIndex = a[i] * numBuckets / (max+1);    //Calculates bucket index
            buckets[bIndex].add(a[i]);					 //Adds the element to the bucket
        }

        //Sort each bucket
        for(int i = 0; i < numBuckets; i++) {
            insertionSort(buckets[i]);
        }

        //Move the elements from each bucket back into the original array
        int index = 0;
        for (int i = 0; i < numBuckets; i++) {
            while(buckets[i].size() > 0) {
                a[index++] = (int)(buckets[i].get(0));		//Get the first value in the bucket and put it in the array
                buckets[i].remove(0);		                //Remove the value from the bucket
            }
        }
    }

    /**
     * Insertion Sort Algorithm
     */
    public static void insertionSort(Vector<Integer> a) {
        for(int i = 1; i < a.size(); i++) {
            int value = a.get(i);
            int j = i-1;
            while(j >= 0 && a.get(j) > value) {
                a.set(j+1, a.get(j));
                j--;
            }
            a.set(j+1, value);
        }
    }

}
