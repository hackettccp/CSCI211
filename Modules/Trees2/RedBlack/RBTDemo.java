package RedBlack;

public class RBTDemo {

    public static void main(String[] args) {
        RedBlackTree t = new RedBlackTree();

        try {
            t.insert(23);
            t.insert(21);
            t.insert(19);
            t.insert(15);
            t.insert(10);
            t.insert(7);
            t.insert(5);
            t.insert(2);
        } catch(Exception e) {
            System.out.println("Exception: " + e.getMessage());
            e.printStackTrace();
        }

        System.out.println("Depth-First Traversal");
        t.depthFirst();
        System.out.println("\n\nBreadth-First Traversal");
        t.breadthFirst();

        try {
            t.remove(15);
            System.out.println("\n15 Removed");
        } catch(Exception e) {
            System.out.println("Exception: " + e.getMessage());
        }
        System.out.println("\n\nDepth-First Traversal");
        t.depthFirst();
        System.out.println("\n\nBreadth-First Traversal");
        t.breadthFirst();

    }

}
