package Examples.Algorithms;

import Examples.ModuleTools;
import java.util.Random;

public class RadixSort {

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
        radixSort(numbers);
        System.out.println("Done.");

        ModuleTools.printArray(numbers); //Comment this out if you are using a large array.
    }

    /**
     * Radix Sort Algorithm.
     */
    public static void radixSort(int[] a) {
        int max = ModuleTools.getMax(a);         //Gets the largest value in the array (Function defined below)

        //Performs a counting sort for every position (1's, 10's, 100's... places).
        //The loop counter, i, represents the values of 10^x (Starts at 1, or 10^0)
        for (int i = 1; max/i > 0; i *= 10) {
            modifiedCountingSort(a, i);
        }
    }

    /**
     * Performs a counting sort for each position/place (i)
     */
    public static void modifiedCountingSort(int[] a, int i) {
        int[] temp = new int[a.length];                 //Temporary array for sorting
        int[] digitCount = new int[10];                 //Valid digits can only be 0-9 (hence indexes 0-9)

        //Stores the counts of each digit's occurrence in position i into digitCount[]
        for (int j = 0; j < a.length; j++) {
            digitCount[(a[j] / i) % 10]++;
        }

        //Linearly sum the values in the digitCount array
        for (int j = 1; j < 10; j++) {
            digitCount[j] += digitCount[j - 1];
        }

        //For each value in a, put the value in the temp array
        //and decrease the value at the corresponding index in digitCount,
        for (int j = a.length - 1; j >= 0; j--) {
            int index = digitCount[(a[j] / i) % 10] - 1;
            temp[index] = a[j];
            digitCount[(a[j] / i) % 10]--;
        }

        //Copy the values from the temp array (sorted by position)
        //into the array, a (replacing the old ordering)
        for (int j = 0; j < a.length; j++) {
            a[j] = temp[j];
        }
    }
}
