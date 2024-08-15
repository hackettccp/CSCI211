package Examples.Algorithms;

import java.util.Random;

public class TimeComparison {

    public static void main(String[] args) {
        int LENGTH = 50000; //Used to easily change/resize the array for testing with longer or shorter arrays
        int[] numbers = new int[LENGTH];
        int[] numbers2 = new int[LENGTH];
        int[] numbers3 = new int[LENGTH];
        int[] numbers4 = new int[LENGTH];

        //Fills the arrays with the same sequence of random numbers. (May include some duplicate numbers.)
        Random r = new Random();
        for(int i = 0; i < LENGTH; i++) {
            int rNum = r.nextInt(100000) + 1; //Gets a random number between 1 and 100000.
            numbers[i] = rNum;
            numbers2[i] = rNum;
            numbers3[i] = rNum;
            numbers4[i] = rNum;
        }

        //Displays the runtime of each algorithm
        System.out.println("Sorting...");


        long startTime = System.currentTimeMillis();
        insertionSort(numbers);
        long endTime = System.currentTimeMillis();
        System.out.println("Insertion sort: " + (endTime-startTime)/1000.0 + " seconds");

        try {
            startTime = System.currentTimeMillis();
            RecursiveBubbleSort.bubbleSort(numbers2, numbers2.length);
            endTime = System.currentTimeMillis();
            System.out.println("Recursive bubble sort: " + (endTime-startTime)/1000.0 + " seconds");
        } catch(Error e) {
            System.out.println("Recursive bubble sort: Recursive call stack overflow error");
        }

        startTime = System.currentTimeMillis();
        Mergesort.mergesort(numbers3, 0, numbers3.length-1);
        endTime = System.currentTimeMillis();
        System.out.println("Mergesort: " + (endTime-startTime)/1000.0 + " seconds");

        startTime = System.currentTimeMillis();
        Quicksort.quicksort(numbers4, 0, numbers4.length-1);
        endTime = System.currentTimeMillis();
        System.out.println("Quicksort: " + (endTime-startTime)/1000.0 + " seconds");

        System.out.println("Done.");
    }

    /**
     * Insertion Sort Algorithm
     */
    public static void insertionSort(int[] a) {
        for(int i = 1; i < a.length; i++) {
            int value = a[i];
            int j = i-1;
            while(j >= 0 && a[j] > value) {
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = value;
        }
    }

}
