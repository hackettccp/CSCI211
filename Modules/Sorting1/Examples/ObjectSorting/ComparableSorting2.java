package Examples.ObjectSorting;

import Examples.ModuleTools;

public class ComparableSorting2 {

    public static void main(String[] args) {
        Book[] books = new Book[5];
        books[0] = new Book("The Art of Computer Programming, Vol. 1", "Donald Knuth", 1968, 672);
        books[1] = new Book("Computer Organization and Architecture", "William Stallings", 1987, 815);
        books[2] = new Book("Data Structures and Algorithms", "Alfred Aho", 1983, 448);
        books[3] = new Book("Artificial Intelligence: A Modern Approach", "Peter Norvig", 1995, 1136);
        books[4] = new Book("Modern Operating Systems", "Andrew Tanenbaum", 1992, 752);

        System.out.println("Unsorted objects: ");
        ModuleTools.printObjectArray(books);

        bubbleSort(books);

        System.out.println("Sorted objects (by year): ");
        ModuleTools.printObjectArray(books);

    }

    /**
     * Uses the Bubble Sort algorithm to sort an array of Book objects by year (ascending order)
     * @param a - Array to sort
     */
    public static void bubbleSort(Book[] a) {
        for(int i = 0; i < a.length; i++) {
            for(int j = 1; j < a.length; j++) {
                if(a[j-1].compareTo(a[j]) > 0) {
                    Book temp = a[j-1];
                    a[j-1] = a[j];
                    a[j] = temp;
                }
            }
        }
    }

}
