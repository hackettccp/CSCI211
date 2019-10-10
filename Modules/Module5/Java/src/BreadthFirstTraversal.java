import java.io.File;
import java.util.LinkedList;
import java.util.Queue;

/**
 * Demonstrates traversing a directory using a breadth-first algorithm.
 */
public class BreadthFirstTraversal {

    /**
     * Main Method. This is where the program begins.
     */
    public static void main(String[] args) {
        File rootDirectory = new File("Directory1");
        traverse(rootDirectory);
    }

    /**
     * Traverses the supplied directory using a breadth-first traversal
     */
    public static void traverse(File directory) {
        Queue<File> q = new LinkedList<File>();
        File[] contents = directory.listFiles();                                                //Gets the contents of the directory
        if(contents == null) {
            return;                                                                             //Returns if empty
        }
        q.add(directory);                                                                       //Add starting directory to the queue
        while(!q.isEmpty()) {
            System.out.println(q.peek().getPath());                                             //Prints the current directory it is in
            contents = ((LinkedList<File>) q).pop().listFiles();                                //Gets the next directory in the queue; gets the array of File objects

            for(File f : contents) {                                                            //For each file in this directory
                if(f.isDirectory()) {
                    q.add(f);                                                                   //Found a directory. Add it to the queue.
                }
                else if(f.getName().endsWith(".txt")) {
                    System.out.println("FOUND: " + f.getPath());                                //Prints the name/path of each file in the directory that ends with .txt
                }
            }
        }

    }

}
