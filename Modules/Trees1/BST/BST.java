package BST;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class BST {

    /**
     * Root Node.
     */
    private Node root;

    /**
     * Constructor.
     */
    public BST() {
        root = null;
    }

    /**
     * External function to search for a value in the tree.
     * @param data - The data to be found in the tree
     */
    public boolean search(int data) {
        if(root != null) {
            Node t = root;
            while(t != null) {
                if(data == t.getData()) {
                    return true;
                } else if(data > t.getData()) {
                    t = t.getRight();
                } else {
                    t = t.getLeft();
                }
            }
        }
        return false;
    }

    /**
     * External function for inserting new data into the tree.
     * @param data - The data being inserted into the tree
     * @throws Exception - Duplicate data
     */
    public void insert(int data) throws Exception {
        if(root == null) {
            //Create a new root node
            root = new Node(data, null);
        }
        else {
            //Use the private insert function to insert the data
            insert(data, root);
        }
    }

    /**
     * External function for removing data from the tree.
     * @param data - The data to be removed from the tree
     */
    public void remove(int data) throws Exception {
        //Immediately call the private remove function
        //with the root at the starting point
        Node t = remove(data, root);
        if(t == null) {
            throw new Exception("Data " + data + " not found in tree.");
        }
    }

    /**
     * Internal function that (if necessary) uses recursion to traverse down
     * the tree and find the location to insert a new node for the new data.
     * @param data - The data being inserted into the tree
     * @param n - Current node being checked
     * @throws Exception - Duplicate data
     */
    private void insert(int data, Node n) throws Exception {
        if(data > n.getData()) {
            //The new data belongs to the right of the current node
            if(n.getRight() != null) {
                //Something is already on the right
                //Traverse down and compare the new data to that right node
                insert(data, n.getRight());
            }
            else {
                //Nothing is to the right
                //This new data belongs here
                n.setRight(new Node(data, n));
            }
        }
        else if(data < n.getData()) {
            //The new data belongs to the left of the current node
            if(n.getLeft() != null) {
                //Something is already on the left
                //Traverse down and compare the new data to that left node
                insert(data, n.getLeft());
            }
            else {
                //Nothing is to the left
                //This new data belongs here
                n.setLeft(new Node(data, n));
            }
        }
        else {
            //The data already exists. Duplicates not allowed.
            throw new Exception("Value " + data + " already exists in the tree.");
        }
    }

    /**
     * Internal function that (if necessary) uses recursion to traverse down
     * the tree and find the location to delete an existing node for the data.
     * @param data - The data to be removed from the tree
     * @param n - Current node being checked
     */
    private Node remove(int data, Node n) {
        if(n == null) {
            //Nothing to remove
            return n;
        }
        else if(data > n.getData()) {
            //Go down right branch
            n.setRight(remove(data, n.getRight()));
        }
        else if (data < n.getData()) {
            //Go down left branch
            n.setLeft(remove(data, n.getLeft()));
        }
        else {
            //Found the data to remove
            if(n.getRight() == null && n.getLeft() == null) {
                //HAS NO CHILDREN
                if(n == n.getParent().getRight()) {
                    //This was its parent's right child
                    n.getParent().setRight(null);
                }
                else {
                    //This was its parent's left child
                    n.getParent().setLeft(null);
                }
            }
            else if(n.getRight() != null && n.getLeft() == null) {
                //HAS RIGHT CHILD, NO LEFT CHILD
                return n.getRight();
            }
            else if(n.getRight() == null && n.getLeft() != null) {
                //HAS LEFT CHILD, NO RIGHT CHILD
                return n.getLeft();
            }
            else {
                //HAS LEFT AND RIGHT CHILD
                //Find the successor
                Node t = findMin(n.getRight());
                //Copy the successor's data
                n.setData(t.getData());
                //Update the right branch by removing the successor
                n.setRight(remove(t.getData(), n.getRight()));
            }
        }
        return n;
    }

    /**
     * Internal function for finding the node with the smallest (left-most) value
     * in a tree/subtree.
     * @param n - Current node
     * @return The node with the smallest(left-most) value in a tree/subtree
     */
    private Node findMin(Node n) {
        while(n.getLeft() != null) {
            n = n.getLeft();
        }
        return n;
    }

    /**
     * Internal function for finding the node with the largest (right-most) value
     * in a tree/subtree.
     * @param n - Current node
     * @return The node with the largest(right-most) value in a tree/subtree
     */
    private Node findMax(Node n) {
        while(n.getRight() != null) {
            n = n.getRight();
        }
        return n;
    }

    /**
     * External method for performing a traversal
     * @param type 1: inorder; 2: preorder; 3: postorder
     */
    public void traverse(int type) {
        if(type == 1) {
            inorder(root);
        }
        else if(type == 2) {
            preorder(root);
        }
        else if(type == 3) {
            postorder(root);
        }
    }

    /**
     * Recursively performs an inorder traversal
     * @param n current node
     */
    private void inorder(Node n) {
        if(n == null) {
            return;
        }
        inorder(n.getLeft());
        System.out.print(n.getData() + " ");
        inorder(n.getRight());
    }

    /**
     * Recursively performs a preorder traversal
     * @param n current node
     */
    private void preorder(Node n) {
        if(n == null) {
            return;
        }
        System.out.print(n.getData() + " ");
        preorder(n.getLeft());
        preorder(n.getRight());
    }

    /**
     * Recursively performs a postorder traversal
     * @param n current node
     */
    private void postorder(Node n) {
        if(n == null) {
            return;
        }
        postorder(n.getLeft());
        postorder(n.getRight());
        System.out.print(n.getData() + " ");
    }

    /**
     * Performs a depth-first (preorder) traversal
     */
    public void depthFirst() {
        Stack<Node> s =  new Stack<Node>();
        if(root != null) {
            s.push(root);
        }
        while(!s.isEmpty()) {
            //Pop/remove the node at the top of the stack
            Node n = s.pop();
            System.out.print(n.getData() + " ");
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
     * Performs a breadth-first traversal
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
            System.out.print(q.remove().getData() + " ");
        }
    }

}
