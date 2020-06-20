package SampleCode;

import java.util.Arrays;
import java.util.Random;

/**
 * Demonstrates the Arrays.sort() method.
 */
public class ArraySort {

    Random r;                                                               //Random object used for setting random numbers into the array
    final int LENGTH = 10;                                                  //Used to set the length of the array
    int[] numbersArray;                                                     //Array of ints that will be sorted

    /**
     * Constructor
     */
    public ArraySort() {
        r = new Random();
        numbersArray = new int[LENGTH];
        for(int i = 0; i < numbersArray.length; i++) {
            numbersArray[i] = r.nextInt(100) + 1;                           //Fills the numbersArray with random values (1-100)
        }
    }

    /**
     * Run Method.
     */
    public void run() {
        System.out.print("Unsorted: ");
        printArray(numbersArray);                                           //Prints the array's values (method defined below)

        Arrays.sort(numbersArray);                                          //Sorts the array into ascending order (Uses a dual-pivot quicksort for primitive-typed arrays)

        System.out.print("Sorted: ");
        printArray(numbersArray);                                           //Prints the array's values to verify they were sorted
    }

    /**
     * Prints the contents of an array
     */
    public void printArray(int[] a) {
        for(int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    /**
     * Main Method.
     */
    public static void main(String[] args) {
        ArraySort as = new ArraySort();
        as.run();
    }

}
