package Examples;

public class ModuleTools {

    /**
     * Simply prints the current values in the array.
     */
    public static void printArray(int[] a) {
        System.out.print("Current values in the array: ");
        for(int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    /**
     * Simply prints the objects in the array.
     * Each object's toString method is called implicitly.
     */
    public static void printObjectArray(Object[] a) {
        for(int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
        System.out.println();
    }

    /**
     * Finds the largest value in an array of ints.
     */
    public static int getMax(int[] a) {
        int max = a[0];
        for (int i = 1; i < a.length; i++) {
            if (a[i] > max) {
                max = a[i];
            }
        }
        return max;
    }

}
