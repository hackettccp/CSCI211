package RedBlack;

public class Node {

    /**
     * Data stored in the node.
     */
    private int data;

    /**
     * The color of the node. Black = 0; Red = 1
     */
    private int color;

    /**
     * Left Child
     */
    private Node left;

    /**
     * Right Child
     */
    private Node right;

    /**
     * Parent Node
     */
    private Node parent;

    /**
     * Constructor
     * @param p -  Parent Node
     */
    public Node(Node p) {
        left = null;
        right = null;
        parent = p;
        color = 0;
    }

    /**
     * Returns the data field
     * @return data
     */
    public int getData() {
        return data;
    }

    /**
     * Returns the color of the node
     * @return height
     */
    public int getColor() {
        return color;
    }

    /**
     * Returns the left child
     * @return left child
     */
    public Node getLeft() {
        return left;
    }

    /**
     * Returns the right child
     * @return right child
     */
    public Node getRight() {
        return right;
    }

    /**
     * Returns the nonde's parent
     * @return parent node
     */
    public Node getParent() {
        return parent;
    }

    /**
     * Sets/updates the node's data field
     * @param d - new data
     */
    public void setData(int d) {
        data = d;
    }

    /**
     * Sets/updates the node's color field
     * @param c - new color
     */
    public void setColor(int c) {
        color = c;
    }

    /**
     * Sets/Updates the node's left child
     * @param n - new left child node
     */
    public void setLeft(Node n) {
        left = n;
    }

    /**
     * Sets/Updates the node's right child
     * @param n - new right child node
     */
    public void setRight(Node n) {
        right = n;
    }

    /**
     * Sets/Updates the node's parent
     * @param n - new parent node
     */
    public void setParent(Node n) {
        parent = n;
    }

    public String toString() {
        String c = color == 1 ? "red" : "black";
        return data + " - " + c;
    }

}
