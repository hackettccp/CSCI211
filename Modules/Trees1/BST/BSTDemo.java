package BST;

public class BSTDemo {

    public static void main(String[] args) {
        BST tree = new BST();
        try {
            tree.insert(50);
            tree.insert(30);
            tree.insert(70);
            tree.insert(80);
            tree.insert(10);
            tree.insert(20);
            tree.insert(20);  //Causes an exception (20 is already in the BST)
        } catch(Exception e) {
            System.out.println("Problem inserting to tree: " + e.getMessage());
        }

        System.out.println("Inorder Traversal:");
        tree.traverse(1);
        System.out.println();
        System.out.println("Preorder Traversal:");
        tree.traverse(2);
        System.out.println();
        System.out.println("Postorder Traversal:");
        tree.traverse(3);
        System.out.println();
        System.out.println("Depth-First Traversal:");
        tree.depthFirst();
        System.out.println();
        System.out.println("Breadth-First Traversal:");
        tree.breadthFirst();
        System.out.println();

        try {
            tree.remove(30);
        } catch(Exception e) {
            System.out.println("Problem removing from the tree: " + e.getMessage());
        }

        System.out.println("Preorder Traversal:");
        tree.traverse(2);
        System.out.println();

        if(tree.search(80)) {
            System.out.println("80 is in the tree");
        }
        else {
            System.out.println("80 is NOT in the tree");
        }

    }

}
