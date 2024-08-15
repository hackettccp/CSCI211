package RedBlack;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class RedBlackTree {

    private Node root;
    private Node nil;    //Used as an empty ("nil") node for leaves

    /**
     * Constructor
     */
    public RedBlackTree() {
        nil = new Node(null);
        nil.setLeft(null);
        nil.setRight(null);
        root = nil;
    }

    /**
     * Rotate a node to the left
     * @param current - rotated node
     */
    public void leftRotate(Node current) {
        Node temp = current.getRight();
        current.setRight(temp.getLeft());
        if(temp.getLeft() != nil) {
            temp.getLeft().setParent(current);
        }
        temp.setParent(current.getParent());
        if(current.getParent() == null) {
            root = temp;
        }
        else if(current == current.getParent().getLeft()) {
            current.getParent().setLeft(temp);
        }
        else {
            current.getParent().setRight(temp);
        }
        temp.setLeft(current);
        current.setParent(temp);
    }

    /**
     * Rotate a node to the left
     * @param current - rotated node
     */
    public void rightRotate(Node current) {
        Node temp = current.getLeft();
        current.setLeft(temp.getRight());
        if(temp.getRight() != nil) {
            temp.getRight().setParent(current);
        }
        temp.setParent(current.getParent());
        if(current.getParent() == null) {
            root = temp;
        }
        else if(current == current.getParent().getRight()) {
            current.getParent().setRight(temp);
        }
        else {
            current.getParent().setLeft(temp);
        }
        temp.setRight(current);
        current.setParent(temp);
    }

    /**
     * Fixes the tree by re-balancing starting where the node was removed
     * @param current - Initially, the deleted node
     */
    private void rebalanceAfterDeletion(Node current) {
        Node temp;
        while(current != root && current.getColor() == 0) {
            //Haven't reached the root and the current node's color is black
            if(current == current.getParent().getLeft()) {
                //Current node is its parent's left child
                temp = current.getParent().getRight();  //Get its sibling
                if(temp.getColor() == 1) {
                    //Sibling is red
                    temp.setColor(0);                       //Recolor to black
                    current.getParent().setColor(1);        //Recolor parent to red
                    leftRotate(current.getParent());        //Left rotate parent
                    temp = current.getParent().getRight();  //Get the new right child post-rotation
                }

                if(temp.getLeft().getColor() == 0 && temp.getRight().getColor() == 0) {
                    //Both of the current node's niblings are black
                    temp.setColor(1);                       //Set sibling to red
                    current = current.getParent();          //Go up the tree
                }
                else {
                    //One is red
                    if(temp.getRight().getColor() == 0) {
                        //Check if the right nibling is black
                        temp.getLeft().setColor(0);         //Update the left nibling to black
                        temp.setColor(1);                   //Update the sibling to red
                        rightRotate(temp);                  //Right rotate the sibling
                        temp = current.getParent().getRight(); //Get the new right child post-rotation
                    }

                    temp.setColor(current.getParent().getColor()); //Color the sibling the same as its parent
                    current.getParent().setColor(0);               //Update the parent's color to black
                    temp.getRight().setColor(0);                   //Update the right nibling to black
                    leftRotate(current.getParent());               //Left rotate the parent
                    current = root;                                //Go to root
                }
            }
            else {
                //Current node is its parent's left child
                temp = current.getParent().getLeft();       //Get its sibling
                if(temp.getColor() == 1) {
                    //Sibling is red
                    temp.setColor(0);                       //Recolor to black
                    current.getParent().setColor(1);        //Recolor parent to red
                    rightRotate(current.getParent());       //Right rotate parent
                    temp = current.getParent().getLeft();  //Get the new left child post-rotation
                }

                if(temp.getLeft().getColor() == 0 && temp.getRight().getColor() == 0) {
                    //Both of the current node's niblings are black
                    temp.setColor(1);                       //Set sibling to red
                    current = current.getParent();          //Go up the tree
                }
                else {
                    //One is red
                    if (temp.getLeft().getColor() == 0) {
                        //Check if the left nibling is black
                        temp.getRight().setColor(0);        //Update the right nibling to black
                        temp.setColor(1);                   //Update the sibling to red
                        leftRotate(temp);                   //Left rotate the sibling
                        temp = current.getParent().getLeft();  //Get the new left child post-rotation
                    }

                    temp.setColor(current.getParent().getColor()); //Color the sibling the same as its parent
                    current.getParent().setColor(0);               //Update the parent's color to black
                    temp.getLeft().setColor(0);                    //Update the left nibling to black
                    rightRotate(current.getParent());              //Right rotate the parent
                    current = root;                                //Go to root
                }
            }
        }
        current.setColor(0); //Exited the loop; Ensure the current node is set to black
    }

    /**
     * Fixes the tree by re-balancing starting where the node was inserted
     * @param current - Initially, the inserted node
     */
    private void rebalanceAfterInsertion(Node current) {
        Node temp;
        while(current.getParent().getColor() == 1) {
            //As long as the current node's parent is red
            if(current.getParent() == current.getParent().getParent().getRight()) {
                //The current node's parent is its parent's right child
                temp = current.getParent().getParent().getLeft();  //Get the current node's ommer (parent's left sibling)
                if(temp.getColor() == 1) {
                    //Ommer is red
                    temp.setColor(0);                               //Set the ommer's color to black
                    current.getParent().setColor(0);                //Set the parent's color to black
                    current.getParent().getParent().setColor(1);    //Set the grandparent's color to red
                    current = current.getParent().getParent();      //Go up the tree (skip parent)
                }
                else {
                    //Ommer is black
                    if(current == current.getParent().getLeft()) {
                        //Current node is the left child
                        current = current.getParent();        //Go up the tree
                        rightRotate(current);                 //Right rotate
                    }
                    current.getParent().setColor(0);                //Update parent to black
                    current.getParent().getParent().setColor(1);    //Update grandparent to red
                    leftRotate(current.getParent().getParent());    //Left rotate grandparent
                }
            }
            else {
                //The current node's parent is its parent's left child
                temp = current.getParent().getParent().getRight();  //Get the current node's ommer (parent's right sibling)

                if(temp.getColor() == 1) {
                    //Ommer is red
                    temp.setColor(0);                               //Set the ommer's color to black
                    current.getParent().setColor(0);                //Set the parent's color to black
                    current.getParent().getParent().setColor(1);    //Set the grandparent's color to red
                    current = current.getParent().getParent();      //Go up the tree (skip parent)
                }
                else {
                    //Ommer is black
                    if(current == current.getParent().getRight()) {
                        //Current node is the right child
                        current = current.getParent();        //Go up the tree
                        leftRotate(current);                  //Left rotate
                    }
                    current.getParent().setColor(0);                //Update parent to black
                    current.getParent().getParent().setColor(1);    //Update grandparent to red
                    rightRotate(current.getParent().getParent());   //Right rotate grandparent
                }
            }
            if(current == root) {
                break;             //Reached the root, exit the loop
            }
        }
        root.setColor(0);          //Ensure root is colored black
    }

    /**
     * Handles promoting a node
     * @param n1 - Destination
     * @param n2 - Node to promote
     */
    private void promote(Node n1, Node n2) {
        if (n1.getParent() == null) {
            root = n2;
        } else if (n1 == n1.getParent().getLeft()) {
            n1.getParent().setLeft(n2);
        } else {
            n1.getParent().setRight(n2);
        }
        n2.setParent(n1.getParent());
    }

    /**
     * Private remove function
     * @param data - Value to delete
     */
    public void remove(int data) throws Exception {
        Node current = root;             //Start at root
        Node nodeToDelete = nil;         //Node that will be deleted
        Node t1;                         //Temporary node variable
        Node t2;                         //Temporary node variable
        while(current != nil) {
            if(current.getData() == data) {
                //Found the node
                nodeToDelete = current;
                break;
            }
            else if(current.getData() <= data) {
                //Go down the tree (right)
                current = current.getRight();
            }
            else {
                //Go down the tree (left)
                current = current.getLeft();
            }
        }

        if (nodeToDelete == nil) {
            //Node/data not found
            throw new Exception("Value" + data + " not found in tree.");
        }

        t1 = nodeToDelete;                                              //New reference to the node to delete
        int t1OriginalColor = t1.getColor();                            //Node to delete's original color

        if(nodeToDelete.getLeft() == nil) {
            //Node to delete has no left child
            t2 = nodeToDelete.getRight();                               //Get a reference to the right child
            promote(nodeToDelete, nodeToDelete.getRight());             //Promote the right child
        }
        else if(nodeToDelete.getRight() == nil) {
            //Node to delete has no right child
            t2 = nodeToDelete.getLeft();                                //Get a reference to the left child
            promote(nodeToDelete, nodeToDelete.getLeft());              //Promote the left child
        }
        else {
            //Has none or both children
            t1 = getMax(nodeToDelete.getLeft());                        //Get the largest value/node down the left branch
            t1OriginalColor = t1.getColor();                            //Remember its color
            t2 = t1.getRight();                                         //Get the right child
            if (t1.getParent() == nodeToDelete) {
                //Node to delete is this node's parent
                t2.setParent(t1);                                       //Update the right child to its new parent
            }
            else {
                promote(t1, t1.getRight());                             //Promote the right child
                t1.setRight(nodeToDelete.getRight());                   //Update its right child
                t1.getRight().setParent(t1);                            //This is now the new right child's parent
            }
            promote(nodeToDelete, t1);                                  //Promote the largest value from the left branch
            t1.setLeft(nodeToDelete.getLeft());                         //Update its left child
            t1.getLeft().setParent(t1);                                 //This is now the new left child's parent
            t1.setColor(nodeToDelete.getColor());                       //Update the color to the deleted node's color
        }
        if(t1OriginalColor == 0) {
            //The promoted node was black before promotion
            rebalanceAfterDeletion(t2);                                 //Check/fix/re-balance the tree starting at the new child
        }
    }

    /**
     * Find the smallest value down a branch
     * @param node - starting node
     * @return Node with the smallest value down that branch
     */
    public Node getMin(Node node) {
        while (node.getLeft() != nil) {
            node = node.getLeft();
        }
        return node;
    }

    /**
     * Find the largest value down a branch
     * @param node - starting node
     * @return Node with the largest value down that branch
     */
    public Node getMax(Node node) {
        while (node.getRight() != nil) {
            node = node.getRight();
        }
        return node;
    }

    /**
     * Inserts a new node
     * @param data - New data
     */
    public void insert(int data) {
        //Create a new red node
        Node node = new Node(null);
        node.setData(data);
        node.setLeft(nil);
        node.setRight(nil);
        node.setColor(1);

        Node current = root;
        Node temp = null;

        //Traverse to the insertion point
        while(current != nil) {
            temp = current;
            if(node.getData()< current.getData()) {
                current = current.getLeft();
            }
            else {
                current = current.getRight();
            }
        }

        node.setParent(temp);                        //Set its parent
        if(temp == null) {
            //Empty tree; This is the root
            root = node;
        }
        else if(node.getData()< temp.getData()) {
            temp.setLeft(node);                     //New node is its parent's left child
        }
        else {
            temp.setRight(node);                    //New node is its parent's right child
        }

        if(node.getParent() == null) {
            node.setColor(0);                       //It's the root; Make it black
            return;
        }

        if(node.getParent().getParent() != null) {
            //Its parent is not the root; May need re-balancing
            rebalanceAfterInsertion(node);          //Check/fix/re-balance the tree starting at the inserted node
        }

    }

    /**
     * Iteratively performs a depth-first (preorder) traversal
     */
    public void depthFirst() {
        Stack<Node> s =  new Stack<Node>();
        if(root != nil) {
            s.push(root);
        }
        while(!s.isEmpty()) {
            //Pop/remove the node at the top of the stack
            Node n = s.pop();
            System.out.println(n);
            //Add right child (if it exists) to the stack
            if(n.getRight() != nil) {
                s.add(n.getRight());
            }
            //Add left child (if it exists) to the stack
            if(n.getLeft() != nil) {
                s.add(n.getLeft());
            }
        }
    }

    /**
     * Iteratively performs a breadth-first traversal
     */
    public void breadthFirst() {
        Queue<Node> q = new LinkedList<Node>();
        if(root != nil) {
            q.add(root);
        }
        else {
            return;
        }
        while(!q.isEmpty()) {
            //Add left child (if it exists) to the queue
            if(q.peek().getLeft() != nil) {
                q.add(q.peek().getLeft());
            }
            //Add right child (if it exists) to the queue
            if(q.peek().getRight() != nil) {
                q.add(q.peek().getRight());
            }
            //Pop/remove the node at the head of the queue
            System.out.println(q.remove());
        }
    }
}
