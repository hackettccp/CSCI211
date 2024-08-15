package Examples.Algorithms;

import Examples.ModuleTools;
import java.util.Random;

public class InsertionSort {

    public static void main(String[] args) {
        int LENGTH = 25; //Used to easily change/resize the array for testing with longer or shorter arrays
        int[] numbers = new int[LENGTH];

        //Fills the array with a sequence of random numbers. (May include some duplicate numbers.)
        Random r = new Random();
        for(int i = 0; i < LENGTH; i++) {
            int rNum = r.nextInt(100) + 1; //Gets a random number between 1 and 100 (0 to 99 + 1 = 1 to 100).
            numbers[i] = rNum;
        }

        ModuleTools.printArray(numbers); //Comment this out if you are using a large array.

        //Sorts the array
        System.out.println("Sorting...");
        insertionSort(numbers);
        System.out.println("Done.");
    }

    /**
     * Insertion Sort Algorithm
     */
    public static void insertionSort(int[] a) {
        int compareCount = 0;
        for(int i = 1; i < a.length; i++) {
            int value = a[i];
            int j = i-1;
            compareCount++;                         //Always at least 1 comparison
            while(j >= 0 && a[j] > value) {
                a[j+1] = a[j];
                j--;
                compareCount++;                     //Next comparison
            }
            if(j < 0) {
                compareCount--;                     //Adjust if the last comparison expected didn't actually happen (because j went negative)
            }
            a[j+1] = value;
        }
        System.out.println("Insertion Sort Total Comparisons: " + compareCount);
    }

}
