package Examples.ObjectSorting;

import Examples.ModuleTools;
import java.util.Arrays;

public class ComparableSorting1 {

    public static void main(String[] args) {
        Book[] books = new Book[5];
        books[0] = new Book("The Art of Computer Programming, Vol. 1", "Donald Knuth", 1968, 672);
        books[1] = new Book("Computer Organization and Architecture", "William Stallings", 1987, 815);
        books[2] = new Book("Data Structures and Algorithms", "Alfred Aho", 1983, 448);
        books[3] = new Book("Artificial Intelligence: A Modern Approach", "Peter Norvig", 1995, 1136);
        books[4] = new Book("Modern Operating Systems", "Andrew Tanenbaum", 1992, 752);

        System.out.println("Unsorted objects: ");
        ModuleTools.printObjectArray(books);

        Arrays.sort(books);

        System.out.println("Sorted objects (by year): ");
        ModuleTools.printObjectArray(books);

    }

}
