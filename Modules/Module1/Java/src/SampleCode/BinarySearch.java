package SampleCode;

import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

/**
 * Demonstrates the Arrays.binarySearch() method.
 */
public class BinarySearch {

    Random r;                                                                                       //Random object used for setting random numbers into the array
    final int LENGTH = 10;                                                                          //Used to set the length of the array
    int[] numbersArray;                                                                             //Array of ints that will be searched

    /**
     * Constructor.
     */
    public BinarySearch() {
        r = new Random();
        numbersArray = new int[LENGTH];
        numbersArray[0] = r.nextInt(100) + 1;                                                       //Places a random number for index 0
        for(int i = 1; i < LENGTH; i++) {
            numbersArray[i] = numbersArray[i - 1] + (r.nextInt(100) + 1);                           //Fills the rest of the numbersArray with random values that will be in ascending order
        }
    }

    /**
     * Run Method.
     */
    public void run() {
        System.out.print("Array contents: ");
        printArray(numbersArray);                                                                   //Prints the array's values (method defined below)

        Scanner keyboard = new Scanner(System.in);
        String input = "";

        while(true) {
            System.out.print("Enter a number to search for (type EXIT to quit): ");
            input = keyboard.nextLine();
            try {
                int numberToFind = Integer.parseInt(input);                                         //May cause NumberFormatException; Handled in the catch
                int index = Arrays.binarySearch(numbersArray, numberToFind);                        //Searches the array (returns a negative number if not found)

                if (index < 0) {
                    System.out.println("Number not found. Index returned: " + index);
                    System.out.println("Should have been at index " + ((index * -1) - 1));          //Calculates and prints the index where the number would have been
                } else {
                    System.out.println(numbersArray[index] + " was found at index " + index);
                }
            } catch(NumberFormatException e) {                                                      //Handles non-int input
                if(input.equalsIgnoreCase("EXIT")) {
                    break;
                }
                System.out.println("Invalid entry. Try again.\n");
            }
        }

    }

    /**
     * Prints the contents of an array.
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
        BinarySearch b = new BinarySearch();
        b.run();

    }
}