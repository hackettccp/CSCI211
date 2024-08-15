package Examples.Algorithms;

import Examples.ModuleTools;
import java.util.Random;

public class Quicksort {

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
        quicksort(numbers, 0, numbers.length-1);
        System.out.println("Done.");

        ModuleTools.printArray(numbers); //Comment this out if you are using a large array.
    }

    /**
     * Quicksort Algorithm
     */
    public static void quicksort(int[] array, int start, int end) {
        int lower = start;                                //Index for inserting in the lower partition
        int upper = end;                                  //Index for inserting in the upper partition
        int temp;                                         //Used when swapping values
        int pivot = array[(lower + upper) / 2];           //Uses the middle element as the pivot value

        //Partitioning
        //Moves numbers less than the pivot to the lower partition, numbers greater than to the pivot to the upper partition
        while(lower <= upper) {
            while(array[lower] < pivot) {
                lower++;                                  //Increment the lower insert index as long as values are less than the pivot value
            }
            while(array[upper] > pivot) {
                upper--;                                  //Decrement the upper insert index as long as values are greater than the pivot value
            }
            if(lower <= upper) {
                //Swap the elements at index "lower" and index "upper" (the indexes where the above while loops needed to stop)
                temp = array[lower];
                array[lower] = array[upper];
                array[upper] = temp;
                lower++;                                  //Increment the lower insert index
                upper--;                                  //Decrement the upper insert index
            }
        }

        //Recursively partition the lower and upper partitions
        if(start < upper) {
            quicksort(array, start, upper);               //Lower partition (Start index through where upper left off)
        }
        if(lower < end) {
            quicksort(array, lower, end);                 //Upper partition (Where lower left off through the ending index)
        }
    }
}
