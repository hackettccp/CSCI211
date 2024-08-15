package Examples.Algorithms;

import Examples.ModuleTools;
import java.util.Random;

public class CountingSort {

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

        System.out.println("Sorting...");
        countingSort(numbers);
        System.out.println("Done.");

        ModuleTools.printArray(numbers); //Comment this out if you are using a large array.
    }

    /**
     * Counting Sort Algorithm
     */
    public static void countingSort(int[] a) {
        int[] result = new int[a.length];                                 //Temporary array for sorting

        //Find the largest value in unsorted array "a"
        int max = a[0];
        for(int i = 1; i < a.length; i++) {
            if(a[i] > max) {
                max = a[i];
            }
        }

        //Create the counting array "c"
        int[] c = new int[max + 1];

        //For each value in "a", increment the corresponding index in "c"
        for(int i = 0; i < a.length; i++) {
            int value = a[i];
            c[value] += 1;
        }

        //Linearly sum the values in the array "c"
        for(int i = 1; i < max + 1; i++) {
            c[i] += c[i-1];
        }

        //For each value in "a", decrease the value at the corresponding index in "c",
        //and put the value in the sorted array "r" at index "c[temp]"
        for(int i = 0; i < a.length; i++) {
            int temp = a[i];
            c[temp] -= 1;
            result[c[temp]] = temp;
        }

        //Copy each value in "result" (sorted) to the original array
        for(int i = 0; i < a.length; i++) {
            a[i] = result[i];
        }
    }

}
