package GeneralTree;

import java.util.LinkedList;
import java.util.Queue;

public class GeneralTree {

    public static void main(String[] args) {
        Node root = new Node("A");                    //Root of the tree
        root.addChild("B");                           //Root's 0th child
        root.addChild("C");                           //Root's 1st child
        root.addChild("D");                           //Root's 2nd child

        root.getChild(0).addChild("E");               //B's children
        root.getChild(0).addChild("F");               //
        root.getChild(0).addChild("G");               //
        root.getChild(0).addChild("H");               //

        root.getChild(1).addChild("I");               //C's child

        root.getChild(2).addChild("J");               //D's children
        root.getChild(2).addChild("K");               //
        root.getChild(2).addChild("L");               //

        System.out.println("Breadth First Traversal: ");
        breadthFirst(root);
        System.out.println();

        System.out.println("Depth First Traversal: ");
        depthFirst(root);
        System.out.println();
    }

    /**
     * Performs a breadth-first traversal of the tree
     */
    public static void breadthFirst(Node n) {
        if(n == null) {
            return;
        }
        Queue<Node> q = new LinkedList<Node>();
        q.add(n);
        while(!q.isEmpty()) {
            Node t = q.poll();
            System.out.print(t.getData() + " ");
            for(int i = 0; i < t.numberOfChildren(); i++) {
                q.add(t.getChild(i));
            }
        }
    }

    /**
     * Performs a recursive depth-first (post-order) traversal of the tree
     */
    public static void depthFirst(Node n) {
        if(n == null) {
            return;
        }
        for(int i = 0; i < n.numberOfChildren(); i++) {
            depthFirst(n.getChild(i));
        }
        System.out.print(n.getData() + " ");
    }

}
