package Examples.ObjectSorting;

import java.util.Comparator;

/**
 * Compares two books, making the comparison based on the year published (ascending order).
 *  result >= 1 when book 1's year is greater than book 2's year
 *  result <= -1 when book 1's year is less than book 2's year
 *  result = 0 when book 1's year is equal to book 2's year
 */
class SortYearAscending implements Comparator<Book> {
    @Override
    public int compare(Book b1, Book b2) {
        return b1.getYearPublished() - b2.getYearPublished();
    }
}

/**
 * Compares two books, making the comparison based on the year published (descending order).
 *  result >= 1 when book 2's year is greater than book 1's year
 *  result <= -1 when book 2's year is less than book 1's year
 *  result = 0 when book 2's year is equal to book 1's year
 */
class SortYearDescending implements Comparator<Book> {
    @Override
    public int compare(Book b1, Book b2) {
        return b2.getYearPublished() - b1.getYearPublished();
    }
}

/**
 * Class that implements Comparator to sort by title (ascending)
 */
class SortByTitleAscending implements Comparator<Book> {
    @Override
    public int compare(Book b1, Book b2) {
        return b1.getTitle().compareTo(b2.getTitle());              //Strings implement Comparable
    }
}

/**
 * Class that implements Comparator to sort by title (descending)
 */
class SortByTitleDescending implements Comparator<Book> {
    @Override
    public int compare(Book b1, Book b2) {
        return b2.getTitle().compareTo(b1.getTitle());              //Strings implement Comparable
    }
}

/**
 * Compares two books, making the comparison based on the number of pages (ascending order).
 *  result >= 1 when book 1's pages is greater than book 2's pages
 *  result <= -1 when book 1's pages is less than book 2's pages
 *  result = 0 when book 1's pages is equal to book 2's pages
 */
class SortPagesAscending implements Comparator<Book> {
    @Override
    public int compare(Book b1, Book b2) {
        return b1.getNumPages() - b2.getNumPages();
    }
}

/**
 * Compares two books, making the comparison based on the number of pages (descending order).
 *  result >= 1 when book 2's pages is greater than book 1's pages
 *  result <= -1 when book 2's pages is less than book 1's pages
 *  result = 0 when book 2's pages is equal to book 1's pages
 */
class SortPagesDescending implements Comparator<Book> {
    @Override
    public int compare(Book b1, Book b2) {
        return b2.getNumPages() - b1.getNumPages();
    }
}
