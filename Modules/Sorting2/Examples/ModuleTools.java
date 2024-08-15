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

}
