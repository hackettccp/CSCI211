package Examples.ObjectSorting;

import Examples.ModuleTools;
import java.util.Arrays;

public class ComparatorSorting {

    public static void main(String[] args) {
        Book[] books = new Book[5];
        books[0] = new Book("The Art of Computer Programming, Vol. 1", "Donald Knuth", 1968, 672);
        books[1] = new Book("Computer Organization and Architecture", "William Stallings", 1987, 815);
        books[2] = new Book("Data Structures and Algorithms", "Alfred Aho", 1983, 448);
        books[3] = new Book("Artificial Intelligence: A Modern Approach", "Peter Norvig", 1995, 1136);
        books[4] = new Book("Modern Operating Systems", "Andrew Tanenbaum", 1992, 752);

        System.out.println("Unsorted objects: ");
        ModuleTools.printObjectArray(books);

        //The new Comparator objects being instantiated in the below Arrays.sort() method calls
        //are in the BookComparators.java file
        Arrays.sort(books, new SortYearAscending());
        System.out.println("Sorted objects (by year published, ascending): ");
        ModuleTools.printObjectArray(books);

        Arrays.sort(books, new SortYearDescending());
        System.out.println("Sorted objects (by year published, descending): ");
        ModuleTools.printObjectArray(books);

        Arrays.sort(books, new SortPagesAscending());
        System.out.println("Sorted objects (by page count, ascending): ");
        ModuleTools.printObjectArray(books);

        Arrays.sort(books, new SortPagesDescending());
        System.out.println("Sorted objects (by page count, descending): ");
        ModuleTools.printObjectArray(books);

        Arrays.sort(books, new SortByTitleAscending());
        System.out.println("Sorted objects (by title, ascending): ");
        ModuleTools.printObjectArray(books);

        Arrays.sort(books, new SortByTitleDescending());
        System.out.println("Sorted objects (by title, descending): ");
        ModuleTools.printObjectArray(books);
    }

}
