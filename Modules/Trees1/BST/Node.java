package BST;

public class Node {

    /**
     * Data stored in the node.
     */
    private int data;

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
     * @param d - Data to be stored in the Node
     * @param p -  Parent Node
     */
    public Node(int d, Node p) {
        data = d;
        left = null;
        right = null;
        parent = p;
    }

    /**
     * Returns the data field
     * @return data
     */
    public int getData() {
        return data;
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
     * Returns the node's parent
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

}
