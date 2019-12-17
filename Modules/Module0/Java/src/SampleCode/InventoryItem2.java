package SampleCode;

import java.util.Comparator;

/**
 * Object that contains classes that implement Comparator interface.
 * Comparators are used for comparison/sorting based for MULTIPLE properties.
 */
public class InventoryItem2 {

    private String name;
    private double price;
    private int quantity;

    public InventoryItem2(String n, double p, int q) {
        name = n;
        price = p;
        quantity = q;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    /**
     * Overrides the primordial Object class's toString method
     */
    @Override
    public String toString() {
        return "Name: " + name + ", Price: " + price + ", Quantity: " + quantity;
    }

}

/**
 * Class that implements Comparator to sort by name (ascending)
 */
class sortByName implements Comparator<InventoryItem2> {
    @Override
    public int compare(InventoryItem2 item1, InventoryItem2 item2) {
        return item1.getName().compareTo(item2.getName());
    }
}

/**
 * Class that implements Comparator to sort by price (ascending)
 */
class sortByPrice implements Comparator<InventoryItem2> {
    @Override
    public int compare(InventoryItem2 item1, InventoryItem2 item2) {
        if(item1.getPrice() < item2.getPrice()) {
            return -1;
        }
        else if(item2.getPrice() < item1.getPrice()) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

/**
 * Class that implements Comparator to sort by quantity (ascending)
 */
class sortByQuantity implements Comparator<InventoryItem2> {
    @Override
    public int compare(InventoryItem2 item1, InventoryItem2 item2) {
        if(item1.getQuantity() < item2.getQuantity()) {
            return -1;
        }
        else if(item2.getQuantity() < item1.getQuantity()) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

