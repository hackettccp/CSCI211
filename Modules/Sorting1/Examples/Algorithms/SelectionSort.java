package Examples.Algorithms;

import Examples.ModuleTools;
import java.util.Random;

public class SelectionSort {

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
        selectionSort(numbers);
        System.out.println("Done.");
    }

    /**
     * Selection Sort Algorithm
     */
    public static void selectionSort(int[] a) {
        int compareCount = 0;
        for(int i = 0; i < a.length-1; i++) {
            int smallest = i;
            for(int j = i+1; j < a.length; j++) {
                compareCount++;
                if(a[j] < a[smallest]) {
                    smallest = j;
                }
            }
            if(smallest != i) {
                int temp = a[smallest];
                a[smallest] = a[i];
                a[i] = temp;
            }
        }
        System.out.println("Selection Sort Total Comparisons: " + compareCount);
    }

}
