package AVL;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class AVLTree {

    /**
     * Root Node.
     */
    private Node root;

    /**
     * Constructor.
     */
    public AVLTree() {
        root = null;
    }

    /**
     * Calculates a node's balance factor
     * @param n Node to calculate the balance factor of
     * @return The balance factor (-1 if the node is null)
     */
    private int balanceFactor(Node n) {
        return n == null ? -1 : this.height(n.getLeft()) - this.height(n.getRight());
    }

    /**
     * Rotates a node clockwise (to the right)
     * @param n Node to rotate
     */
    private void rotateRight(Node n) {
        Node t1 = n.getLeft();                                  //Temp reference to left child
        Node t2 = t1.getRight();                                //Temp reference to left child's right child

        t1.setRight(n);                                         //Original node is now it's left child's right child
        n.setLeft(null);                                        //Removes original node's left child

        Node p = n.getParent();                                 //Original node's parent
        if(p != null) {
            //Original node had a parent (it wasn't the root)
            if(n == p.getLeft()) {
                //It was its parent's left child
                p.setLeft(t1);                                  //Original's old left child is now its parent's left child
            }
            if(n == p.getRight()) {
                //It was its parent's right child
                p.setRight(t1);                                 //Original's old left child is now its parent's right child
            }
        }

        t1.setParent(p);                //Update the old left child's parent reference
        n.setParent(t1);                //Update the original node's parent reference
        n.setLeft(t2);                  //Update the original node's left child reference

        if(t2 != null) {
            //Update its new left child's parent reference
            t2.setParent(n);
        }

        if(root == n) {
            //Update the root reference, if the original node was the root
            root = t1;
        }

        //Recalculate the heights of the rotated nodes
        n.setHeight(max(height(n.getLeft()), height(n.getRight())) + 1);
        t1.setHeight(max(height(t1.getLeft()), height(t1.getRight())) + 1);
    }

    /**
     * Rotates a node counter-clockwise (to the left)
     * @param n Node to rotate
     */
    private void rotateLeft(Node n) {
        Node t1 = n.getRight();                                 //Temp reference to right child
        Node t2 = t1.getLeft();                                 //Temp reference to right child's left child

        t1.setLeft(n);                                          //Original node is now it's right child's left child
        n.setRight(null);                                       //Removes original node's right child

        Node p = n.getParent();                                 //Original node's parent
        if(p != null) {
            //Original node had a parent (it wasn't the root)
            if(n == p.getLeft()) {
                //It was its parent's left child
                p.setLeft(t1);                                  //Original's old right child is now its parent's left child
            }
            if(n == p.getRight()) {
                //It was its parent's right child
                p.setRight(t1);                                 //Original's old right child is now its parent's right child
            }
        }

        t1.setParent(p);                //Update the old right child's parent reference
        n.setParent(t1);                //Update the original node's parent reference
        n.setRight(t2);                 //Update the original node's right child reference

        if(t2 != null) {
            //Update its new right child's parent reference
            t2.setParent(n);
        }

        if(root == n) {
            //Update the root reference, if the original node was the root
            root = t1;
        }

        //Recalculate the heights of the rotated nodes
        n.setHeight(max(height(n.getLeft()), height(n.getRight())) + 1);
        t1.setHeight(max(height(t1.getLeft()), height(t1.getRight())) + 1);
    }

    /**
     * Public insert function
     * @param data Data to insert
     * @throws Exception
     */
    public void insert(int data) throws Exception {
        if(root == null) {
            root = new Node(data, null);
        }
        else {
            insert(root, data);
        }
    }

    /**
     * Inserts a new node into the tree.
     * @param n - Current node.
     * @param data - Data to be inserted.
     * @throws Exception - Duplicate data.
     */
    private void insert(Node n, int data) throws Exception {
        if(data > n.getData()) {                            //Value is greater than the current node's value; Needs to be inserted down the right branch
            if(n.getRight() != null) {                      //A right child is present
                insert(n.getRight(), data);                 //Use recursion to insert down the right side
            }
            else {
                n.setRight(new Node(data, n));              //No right child. Add this new node there.
            }
        }
        else if(data < n.getData()) {                       //Value is less than the current node's value; Needs to be inserted down the left branch
            if(n.getLeft() != null) {                       //A left child is present
                insert(n.getLeft(), data);                  //Use recursion to insert down the left side
            }
            else {
                n.setLeft(new Node(data, n));               //No left child. Add this new node there
            }
        }
        else {
            throw new Exception("Value already exists in the BST");   //Can't have duplicate values in the BST
        }

        //Adjusts the height for the node
        n.setHeight(1 + max(height(n.getLeft()), height(n.getRight())));

        //Calculates the balance factor
        int b = balanceFactor(n);

        if((b > 1 || b < -1) && height(n.getLeft()) > height(n.getRight())) {
            rotateRight(n);  //Node needs a right rotation
        }
        else if((b > 1 || b < -1) && height(n.getRight()) > height(n.getLeft())) {
            rotateLeft(n);   //Node needs a left rotation
        }
    }

    /**
     * Public remove function.
     * @param data Data to remove
     */
    public void remove(int data) {
        remove(root, data);
    }

    /**
     * Removes a node from the tree.
     * @param n - Current node.
     * @param data - Data to be removed.
     */
    private Node remove(Node n, int data) {
        if(n == null) {
            //Nothing to remove
            return n;
        }
        else if(data < n.getData()) {
            //Go down left branch
            n.setLeft(remove(n.getLeft(), data));
        }
        else if(data > n.getData()) {
            //Go down right branch
            n.setRight(remove(n.getRight(), data));
        }
        else {
            //Found the value
            if(n.getLeft() == null && n.getRight() == null) {
                //NO children
                if(n == n.getParent().getRight()) {
                    //If this node is its parent's right child
                    n.getParent().setRight(null);
                }
                else if(n == n.getParent().getLeft()) {
                    //If this node is its parent's left child
                    n.getParent().setLeft(null);
                }
                n = null;  //Node is no longer needed
            }
            else if(n.getLeft() == null && n.getRight() != null || n.getLeft() != null && n.getRight() == null) {
                //Has ONE child
                Node t;
                if(n.getRight() != null) {
                    //Has right child
                    t = n.getRight();
                }
                else {
                    //Has left child
                    t = n.getLeft();
                }
                if(n.getParent() != null) {
                    //This node is not the root, so parent links need updating
                    if(n.getParent().getLeft() == n) {
                        //This node is its parent's left child
                        //This node's left child succeeds it
                        n.getParent().setLeft(t);
                    }
                    else if(n.getParent().getRight() == n) {
                        //This node is its parent's right child
                        //This node's right child succeeds it
                        n.getParent().setRight(t);
                    }
                }
                t.setParent(n.getParent());  //Update successor's parent link
                n = t;                       //May need to be rebalanced below

            }
            else {
                //Has a LEFT AND RIGHT child
                Node t = findMin(n.getRight());                    //Find the successor (smallest value down the right branch)
                n.setData(t.getData());                            //Copy the successor's value
                n.setRight(remove(n.getRight(), t.getData()));     //Recursively update the right branch to find and delete the successor
            }
        }

        if(n != null) {
            int b = balanceFactor(n);   //Calculates the balance factor
            if((b > 1 || b < -1) && height(n.getLeft()) > height(n.getRight())) {
                //Node needs a right rotation
                rotateRight(n);
            }
            else if((b > 1 || b < -1) && height(n.getRight()) > height(n.getLeft())) {
                //Node needs a left rotation
                rotateLeft(n);
            }
        }
        return n;
    }

    /**
     * Searches the tree for a value
     * @param value
     * @return true if value was found
     */
    public boolean search(int value) {
        Node n = root;
        while(n != null) {
            if (value == n.getData()) {
                return true;
            }
            else if (value > n.getData()) {
                n = n.getRight();
            }
            else {
                n = n.getLeft();
            }
        }
        return false;
    }

    /**
     * Iteratively performs a depth-first (preorder) traversal
     */
    public void depthFirst() {
        Stack<Node> s =  new Stack<Node>();
        if(root != null) {
            s.push(root);
        }
        while(!s.isEmpty()) {
            //Pop/remove the node at the top of the stack
            Node n = s.pop();
            System.out.println(n.getData());
            //Add right child (if it exists) to the stack
            if(n.getRight() != null) {
                s.add(n.getRight());
            }
            //Add left child (if it exists) to the stack
            if(n.getLeft() != null) {
                s.add(n.getLeft());
            }
        }
    }

    /**
     * Iteratively performs a breadth-first traversal
     */
    public void breadthFirst() {
        Queue<Node> q = new LinkedList<Node>();
        if(root != null) {
            q.add(root);
        }
        else {
            return;
        }
        while(!q.isEmpty()) {
            //Add left child (if it exists) to the queue
            if(q.peek().getLeft() != null) {
                q.add(q.peek().getLeft());
            }
            //Add right child (if it exists) to the queue
            if(q.peek().getRight() != null) {
                q.add(q.peek().getRight());
            }
            //Pop/remove the node at the head of the queue
            System.out.println(q.remove().getData());
        }
    }

    /**
     * Finds the smallest value
     * @param n - Starting node
     * @return - Node with the smallest value
     */
    private Node findMin(Node n) {
        if(n.getLeft() == null) {
            //No left child
            return n;
        }
        else {
            //Recursively go down the left side
            return findMin(n.getLeft());
        }
    }

    /**
     * Helper function to find the larger of two heights.
     * @param h1 - First height.
     * @param h2 - Second height.
     */
    private int max(int h1, int h2) {
        return h1 > h2 ? h1 : h2;
    }

    /**
     * Helper function to get the height of a node.
     * @param n The node to get the height of.
     * @return The height of the node (-1 if the node is null).
     */
    private int height(Node n) {
        return n == null ? -1 : n.getHeight();
    }

}
