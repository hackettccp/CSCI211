package SampleCode;

/**
 * Object that implements the Comparable interface.
 * Comparable is used for comparison/sorting based on a SINGLE property.
 */
public class InventoryItem implements Comparable<InventoryItem> {

    private String name;
    private double price;
    private int quantity;

    public InventoryItem(String n, double p, int q) {
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

    /**
     * Required by Comparable Interface.
     */
    @Override
    public int compareTo(InventoryItem otherItem) {
        int otherQuantity = otherItem.getQuantity();

        //Ascending Order
        return quantity - otherQuantity;

        //Descending Order
        //return otherQuantity - quantity;
    }
}
