import java.io.File;
import java.util.Stack;

/**
 * Demonstrates traversing a directory using a depth-first algorithm.
 */
public class DepthFirstTraversal {

    /**
     * Main Method. This is where the program begins.
     */
    public static void main(String[] args) {
        File rootDirectory = new File("Directory1");
        traverse(rootDirectory);
    }

    /**
     * Traverses the supplied directory using a depth-first traversal
     */
    public static void traverse(File directory) {
        Stack<File> s = new Stack<File>();
        File[] contents = directory.listFiles();                                                //Gets the contents of the directory
        if(contents == null) {
            return;                                                                             //Returns if empty
        }
        s.push(directory);                                                                      //Add starting directory to the stack
        while(!s.isEmpty()) {
            System.out.println(s.peek().getPath());                                             //Prints the current directory it is in
            contents = s.pop().listFiles();                                                     //Gets the next directory in the stack; gets the array of File objects

            if(contents != null) {
                for(File f : contents) {                                                        //For each file in this directory
                    if(f.isDirectory()) {
                        s.add(f);                                                               //Found a directory. Add it to the stack.
                    }
                    else if(f.getName().endsWith(".txt")) {
                        System.out.println("FOUND: " + f.getPath());                            //Prints the name/path of each file in the directory that ends with .txt
                    }
                }
            }
        }

    }

}