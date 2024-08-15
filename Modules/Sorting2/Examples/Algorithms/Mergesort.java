package Examples.Algorithms;

import Examples.ModuleTools;
import java.util.Random;

public class Mergesort {

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
        mergesort(numbers, 0, numbers.length-1);
        System.out.println("Done.");

        ModuleTools.printArray(numbers); //Comment this out if you are using a large array.
    }

    /**
     * Merge Sort Algorithm
     */
    public static void mergesort(int[] array, int left, int right) {
        //Check that the left boundary of the partition is less than the right boundary of the partition
        if(left < right) {
            int middle = (left+right)/2;            //Calculate the middle index

            mergesort(array, left, middle);         //Recursively break down the lower partition
            mergesort(array, middle+1, right);      //Recursively break down the upper partition

            merge(array, left, middle, right);      //Merge the partitions
        }
    }

    /**
     * Merges two partitions of an array together, in the correct order.
     */
    public static void merge(int[] array, int left, int middle, int right) {
        int lowerCounter = 0;                                               //Working index of the lower partition
        int upperCounter = 0;                                               //Working index of the upper partition
        int mergeCounter = left;                                            //Working index of the entire (lower and upper) parition

        int lowerSize = middle - left + 1;                                  //Calculate size of the lower partition
        int upperSize = right - middle;                                     //Calculate size of the upper partition

        //Two temporary arrays that will be used in the merge process
        int tempLower[] = new int[lowerSize];
        int tempUpper[] = new int[upperSize];

        //Copy elements into the temporary arrays
        for(int i = 0; i < lowerSize; i++) {
            tempLower[i] = array[left + i];
        }
        for(int i = 0; i < upperSize; i++) {
            tempUpper[i] = array[middle + 1 + i];
        }

        //Copy the elements of the temp arrays back into array
        //Effectively, this "merges" the temporary elements into the actual array
        while(lowerCounter < lowerSize && upperCounter < upperSize) {

            //The smaller element is put in the actual array at index "mergeCounter"
            if(tempLower[lowerCounter] <= tempUpper[upperCounter]) {
                array[mergeCounter] = tempLower[lowerCounter];
                lowerCounter++;                                           //Increment the lower partition index
            }
            else {
                array[mergeCounter] = tempUpper[upperCounter];
                upperCounter++;                                           //Increment the upper partition index
            }

            //Increment index to place the next value from the two partitions
            mergeCounter++;
        }

        //**Only one of the two partitions might still have values left over, so we have to check both
        //  with the below while loops**

        //Copy the remaining elements of tempLower, if there are any
        while(lowerCounter < lowerSize) {
            array[mergeCounter] = tempLower[lowerCounter];
            lowerCounter++;
            mergeCounter++;
        }

        //Copy the remaining elements of tempUpper, if there are any
        while(upperCounter < upperSize) {
            array[mergeCounter] = tempUpper[upperCounter];
            upperCounter++;
            mergeCounter++;
        }
    }

}
