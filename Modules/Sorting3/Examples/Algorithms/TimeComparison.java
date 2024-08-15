package Examples.Algorithms;

import java.util.Random;

public class TimeComparison {

    public static void main(String[] args) {
        int LENGTH = 50000; //Used to easily change/resize the array for testing with longer or shorter arrays
        int BUCKETS = 100; //Used to easily change the number of buckets to use for bucket sorting
        int[] numbers = new int[LENGTH];
        int[] numbers2 = new int[LENGTH];
        int[] numbers3 = new int[LENGTH];

        //Fills the arrays with the same sequence of random numbers. (May include some duplicate numbers.)
        Random r = new Random();
        for(int i = 0; i < LENGTH; i++) {
            int rNum = r.nextInt(100000) + 1; //Gets a random number between 1 and 100000.
            numbers[i] = rNum;
            numbers2[i] = rNum;
            numbers3[i] = rNum;
        }

        //Displays the runtime of each algorithm
        System.out.println("Sorting...");


        long startTime = System.currentTimeMillis();
        CountingSort.countingSort(numbers);
        long endTime = System.currentTimeMillis();
        System.out.println("Counting sort: " + (endTime-startTime)/1000.0 + " seconds");

        startTime = System.currentTimeMillis();
        RadixSort.radixSort(numbers2);
        endTime = System.currentTimeMillis();
        System.out.println("Radix sort: " + (endTime-startTime)/1000.0 + " seconds");

        startTime = System.currentTimeMillis();
        BucketSort.bucketSort(numbers3, BUCKETS);
        endTime = System.currentTimeMillis();
        System.out.println("Bucket sort: " + (endTime-startTime)/1000.0 + " seconds");

        System.out.println("Done.");
    }

}
