package BinaryTree;

public class BinaryTree {

    public static void main(String[] args) {
        Node root = new Node(10);       //Create the root node (Node "A" in these comments)
        root.setLeft(new Node(20));     //Create a left child (Node "B" in these comments)
        root.setRight(new Node(30));    //Create a right child (Node "C" in these comments)
        /*
                 10("A")
              /      \
            20("B")   30("C")
           /  \      /   \
        NULL  NULL NULL  NULL
        */

        root.getLeft().setRight(new Node(40));     //Create a right child (Node "D" in these comments) for Node B
        root.getRight().setRight(new Node(50));    //Create a right child (Node "E" in these comments) for Node C
        /*
                 10("A")
              /         \
            20("B")      30("C")
           /  \          /    \
        NULL   40("D")  NULL    50("E")
             /    \      /       \
           NULL  NULL  NULL      NULL
        */

        root.getLeft().getRight().setLeft(new Node(60));     //Create a left child (Node "F" in these comments) for Node D
        root.getRight().getRight().setLeft(new Node(70));    //Create a left child (Node "G" in these comments) for Node E
        /*
                  10("A")
              /         \
            20("B")      30("C")
           /  \          /    \
        NULL   40("D")  NULL    50("E")
              /     \          /      \
          60("F")   NULL     70("G")   NULL
           /  \               /  \
        NULL  NULL         NULL  NULL
        */

        System.out.println("Inorder Traversal/\"Infix\": ");
        inorder(root);
        System.out.println();

        System.out.println("Preorder Traversal/\"Prefix\": ");
        preorder(root);
        System.out.println();

        System.out.println("Postorder Traversal/\"Postfix\": ");
        postorder(root);
        System.out.println();
    }

    /**
     *  (Recursively) Performs an inorder traversal of the tree
     */
    public static void inorder(Node n) {
        if(n == null) {
            return;
        }
        inorder(n.getLeft());
        System.out.print(n.getData() + " ");
        inorder(n.getRight());
    }

    /**
     * (Recursively) Performs a postorder traversal of the tree
     */
    public static void postorder(Node n) {
        if(n == null) {
            return;
        }
        postorder(n.getLeft());
        postorder(n.getRight());
        System.out.print(n.getData() + " ");
    }

    /**
     * (Recursively) Performs a preorder traversal of the tree
     */
    public static void preorder(Node n) {
        if(n == null) {
            return;
        }
        System.out.print(n.getData() + " ");
        preorder(n.getLeft());
        preorder(n.getRight());
    }

}
