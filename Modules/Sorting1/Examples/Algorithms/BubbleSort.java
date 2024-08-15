package Examples.Algorithms;

import Examples.ModuleTools;
import java.util.Random;

public class BubbleSort {

    public static void main(String[] args) {
        int LENGTH = 25; //Used to easily change/resize the array for testing with longer or shorter arrays
        int[] numbers = new int[LENGTH];
        int[] numbers2 = new int[LENGTH];
        int[] numbers3 = new int[LENGTH];
        int[] numbers4 = new int[LENGTH];
        int[] numbers5 = new int[LENGTH];

        //Fills the arrays with the same sequence of random numbers. (May include some duplicate numbers.)
        Random r = new Random();
        for(int i = 0; i < LENGTH; i++) {
            int rNum = r.nextInt(100) + 1; //Gets a random number between 1 and 100 (0 to 99 + 1 = 1 to 100).
            numbers[i] = rNum;
            numbers2[i] = rNum;
            numbers3[i] = rNum;
            numbers4[i] = rNum;
            numbers5[i] = rNum;
        }

        ModuleTools.printArray(numbers); //Comment this out if you are using a large array.

        //Sorts each array using a different variation of Bubble Sort
        System.out.println("Sorting...");
        bubbleSort(numbers);
        bubbleSort1(numbers2);
        bubbleSort2(numbers3);
        cocktailSort(numbers4);
        cocktailSort2(numbers5);
        System.out.println("Done.");
    }

    /**
     * Original Bubble Sort Algorithm
     */
    public static void bubbleSort(int[] a) {
        int compareCount = 0;
        for(int i = 0; i < a.length; i++) {
            for(int j = 1; j < a.length; j++) {
                compareCount++;
                if(a[j-1] > a[j]) {
                    int temp = a[j-1];
                    a[j-1] = a[j];
                    a[j] = temp;
                }
            }
        }
        System.out.println("Original Bubble Sort Total Comparisons: " + compareCount);
    }

    /**
     * Bubble Sort Algorithm Improvement 1
     */
    public static void bubbleSort1(int[] a) {
        boolean sorted;
        int compareCount = 0;
        do {
            sorted = true;
            for(int i = 0; i < a.length-1; i++) {
                compareCount++;
                if(a[i] > a[i+1]) {
                    int temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                    sorted = false;
                }
            }
        } while(!sorted);
        System.out.println("Bubble Sort Improvement 1 Total Comparisons: " + compareCount);
    }

    /**
     * Bubble Sort Algorithm Improvement 2
     */
    public static void bubbleSort2(int[] a) {
        int compareCount = 0;
        for(int i = 0; i < a.length; i++) {
            for(int j = 1; j < a.length - i; j++) {
                compareCount++;
                if(a[j-1] > a[j]) {
                    int temp = a[j-1];
                    a[j-1] = a[j];
                    a[j] = temp;
                }
            }
        }
        System.out.println("Bubble Sort Improvement 2 Total Comparisons: " + compareCount);
    }

    /**
     * Original Cocktail Shaker Sort Algorithm
     */
    public static void cocktailSort(int[] a) {
        int compareCount = 0;
        boolean sorted;
        do {
            sorted = true;
            //Forward
            for(int i = 1; i < a.length; i++) {
                compareCount++;
                if(a[i-1] > a[i]) {
                    int temp = a[i-1];
                    a[i-1] = a[i];
                    a[i] = temp;
                    sorted = false;
                }
            }
            if(sorted) {
                break;
            }
            //Reverse
            for(int j = a.length-1; j > 0; j--) {
                compareCount++;
                if(a[j] < a[j-1]) {
                    int temp = a[j-1];
                    a[j-1] = a[j];
                    a[j] = temp;
                    sorted = false;
                }
            }
        } while(!sorted);
        System.out.println("Original Cocktail Shaker Sort Total Comparisons: " + compareCount);
    }

    /**
     * Improved Cocktail Shaker Sort Algorithm
     */
    public static void cocktailSort2(int[] a) {
        int compareCount = 0;
        int lowBound = 0;
        int highBound = a.length - 1;

        while(lowBound < highBound) {
            //Forward
            for(int i = lowBound; i < highBound; i++) {
                compareCount++;
                if(a[i] > a[i+1]) {
                    int temp = a[i+1];
                    a[i+1] = a[i];
                    a[i] = temp;
                }
            }
            highBound--;

            //Reverse
            for(int i = highBound; i > lowBound; i--) {
                compareCount++;
                if(a[i-1] > a[i]) {
                    int temp = a[i-1];
                    a[i-1] = a[i];
                    a[i] = temp;
                }
            }
            lowBound++;
        }
        System.out.println("Improved Cocktail Shaker Sort Total Comparisons: " + compareCount);
    }

}
