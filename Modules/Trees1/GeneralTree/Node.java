package GeneralTree;

import java.util.LinkedList;

public class Node {

    private String data;                   //Data stored in the node
    private LinkedList<Node> children;     //Linked List of the node's children

    /**
     * Constructor
     * @param d - String data stored in the node
     */
    public Node(String d) {
        data = d;
        children = new LinkedList<Node>();
    }

    /**
     * Returns the data field
     * @return data
     */
    public String getData() {
        return data;
    }

    /**
     * Updates the data field
     * @param d - String data stored in the node
     */
    public void setData(String d) {
        data = d;
    }

    /**
     * Adds a new child node
     * @param d - String data stored in the new child node
     */
    public void addChild(String d) {
        children.add(new Node(d));
    }

    /**
     * Gets a child node
     * @param i - Index of the node
     * @return The child node
     */
    public Node getChild(int i) {
        return children.get(i);
    }

    /**
     * Gets the data from a new child node
     * @param i - Index of the node
     * @return String data stored in the child node
     */
    public String getChildData(int i) {
        return children.get(i).getData();
    }

    /**
     * Returns the number of children
     * @return Number of children
     */
    public int numberOfChildren() {
        return children.size();
    }

}
