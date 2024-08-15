package Examples.Algorithms;

import Examples.ModuleTools;
import java.util.Random;

public class AllAlgorithms {

    public static void main(String[] args) {
        int LENGTH = 25; //Used to easily change/resize the array for testing with longer or shorter arrays
        int[] numbers = new int[LENGTH];
        int[] numbers2 = new int[LENGTH];
        int[] numbers3 = new int[LENGTH];
        int[] numbers4 = new int[LENGTH];
        int[] numbers5 = new int[LENGTH];
        int[] numbers6 = new int[LENGTH];
        int[] numbers7 = new int[LENGTH];

        //Fills the arrays with the same sequence of random numbers. (May include some duplicate numbers.)
        Random r = new Random();
        for(int i = 0; i < LENGTH; i++) {
            int rNum = r.nextInt(100) + 1; //Gets a random number between 1 and 100 (0 to 99 + 1 = 1 to 100).
            numbers[i] = rNum;
            numbers2[i] = rNum;
            numbers3[i] = rNum;
            numbers4[i] = rNum;
            numbers5[i] = rNum;
            numbers6[i] = rNum;
            numbers7[i] = rNum;
        }

        ModuleTools.printArray(numbers); //Comment this out if you are using a large array.

        //Sorts each array using a different algorithm for each
        System.out.println("Sorting...");
        BubbleSort.bubbleSort(numbers);
        BubbleSort.bubbleSort1(numbers2);
        BubbleSort.bubbleSort2(numbers3);
        BubbleSort.cocktailSort(numbers4);
        BubbleSort.cocktailSort2(numbers5);
        SelectionSort.selectionSort(numbers6);
        InsertionSort.insertionSort(numbers7);
        System.out.println("Done.");
    }

}
