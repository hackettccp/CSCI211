package Examples.ObjectSorting;

public class Book implements Comparable<Book>{

    private int yearPublished;
    private int numPages;
    private String title;
    private String author;

    /**
     * Constructor
     * @param t Title
     * @param a Author
     * @param y Year Published
     * @param n Number of Pages
     */
    public Book(String t, String a, int y, int n) {
        title = t;
        author = a;
        yearPublished = y;
        numPages = n;
    }

    /**
     * Returns a descriptive string about the book object.
     * Overrides the primordial Object toString method.
     * @return String representation of a Book object
     */
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(title);
        sb.append("-");
        sb.append(author);
        sb.append("; Year: ");
        sb.append(yearPublished);
        sb.append(", Pages: ");
        sb.append(numPages);
        return sb.toString();
    }

    /**
     * Accessor for the yearPublished field.
     * @return yearPublished
     */
    public int getYearPublished() {
        return yearPublished;
    }

    /**
     * Accessor for the numPages field.
     * @return numPages
     */
    public int getNumPages() {
        return numPages;
    }

    /**
     * Accessor for the title field.
     * @return title
     */
    public String getTitle() {
        return title;
    }

    /**
     * Compares two books, making the comparison based on the year published.
     *  result >= 1 when this book's year is greater than the other book's year
     *  result <= -1 when this book's year is less than the other book's year
     *  result = 0 when this book's year is equal to the other book's year
     * @param otherBook Book object to compare against
     * @return result of this book's year minus the other book's year
     */
    @Override
    public int compareTo(Book otherBook) {
        return this.yearPublished - otherBook.getYearPublished();
    }

}
