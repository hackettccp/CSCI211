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

}
