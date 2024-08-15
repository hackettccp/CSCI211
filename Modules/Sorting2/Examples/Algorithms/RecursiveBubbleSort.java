package Examples.Algorithms;

import Examples.ModuleTools;
import java.util.Random;

public class RecursiveBubbleSort {

    public static void main(String[] args) {
        int LENGTH = 25; //Used to easily change/resize the array for testing with longer or shorter arrays
        int[] numbers = new int[LENGTH];

        //Fills the arrays with the same sequence of random numbers. (May include some duplicate numbers.)
        Random r = new Random();
        for(int i = 0; i < LENGTH; i++) {
            int rNum = r.nextInt(100) + 1; //Gets a random number between 1 and 100 (0 to 99 + 1 = 1 to 100).
            numbers[i] = rNum;
        }

        ModuleTools.printArray(numbers); //Comment this out if you are using a large array.

        //Sorts each array using a different variation of Bubble Sort
        System.out.println("Sorting...");
        bubbleSort(numbers, numbers.length);
        System.out.println("Done.");

        ModuleTools.printArray(numbers); //Comment this out if you are using a large array.
    }

    /**
     * Recursive Bubble Sort Algorithm
     */
    public static void bubbleSort(int[] a, int length) {
        //BASE CASE
        if(length == 1) {
            return;                              //Sorting for index 0 (length of sorting space is 1)
        }

        //RECURSIVE CASE
        for(int i = 0; i < length-1; i++) {      //Swaps remaining; unsorted values in the array
            if(a[i] > a[i+1]) {
                int temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
            }
        }
        bubbleSort(a, length-1);
    }

}
