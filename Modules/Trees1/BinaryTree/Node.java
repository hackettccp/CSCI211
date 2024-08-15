package BinaryTree;

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
     * Constructor
     * @param d - Data to be stored in the Node
     */
    public Node(int d) {
        data = d;
        left = null;
        right = null;
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
