import java.util.*;

/**
 * Implementation of an undirected, unweighted graph
 * Using Adjacency Lists
 */
public class Graph {

    /**
     * The vertices contained in the graph.
     * Stored in an ArrayList of Vertex objects
     */
    ArrayList<Vertex> vertices;

    /**
     * A HashMap linking a Vertex to an ArrayList.
     * An ArrayList of Vertex objects is used for the adjacency list
     */
    HashMap<Vertex, ArrayList<Vertex>> map;

    /**
     * No-Arg Constructor
     * Instantiates the ArrayList of vertices and the HashMap
     */
    public Graph() {
        vertices = new ArrayList<Vertex>();
        map = new HashMap<Vertex, ArrayList<Vertex>>();
    }

    /**
     * Adds a new vertex to the graph
     * @param v - The value to be stored in the new vertex
     */
    public void addVertex(String v) {
        //Check the vertex doesn't already exist
        for(int i=0; i<vertices.size(); i++) {
            if(vertices.get(i).value.equals(v)) {
                return; //Vertex already exists
            }
        }
        //Create the new vertex,
        //add it to the graph's list of vertices,
        //pair it with a new adjacency list in the map
        Vertex t = new Vertex(v);
        vertices.add(t);
        map.put(t, new ArrayList<Vertex>());
    }

    /**
     * Adds an (undirected) edge between two vertices
     * @param s1 - The value of the first vertex
     * @param s2 - The value of the second vertex
     */
    public void addEdge(String s1, String s2) {
        Vertex v1 = null;
        Vertex v2 = null;
        //Check that two vertices with these values exist in the graph
        for(int i=0; i<vertices.size(); i++) {
            if(vertices.get(i).value.equals(s1)) {
                v1 = vertices.get(i);
            }
            else if(vertices.get(i).value.equals(s2)) {
                v2 = vertices.get(i);
            }
        }
        if(v1 != null && v2 != null) {
            map.get(v1).add(v2);       //Adds v2 to v1's adjacency list
            map.get(v2).add(v1);       //Adds v1 to v2's adjacency list
        }
    }

    /**
     * Removes a directed edge between two vertices
     * @param s1 - The value of the first vertex (FROM)
     * @param s2 - The value of the second vertex (TO)
     */
    public void removeEdge(String s1, String s2) {
        Vertex v1 = null;
        Vertex v2 = null;
        //Check that two vertices with these values exist in the graph
        for(int i=0; i<vertices.size(); i++) {
            if(vertices.get(i).value.equals(s1)) {
                v1 = vertices.get(i);
            }
            else if(vertices.get(i).value.equals(s2)) {
                v2 = vertices.get(i);
            }
        }
        if(v1 != null && v2 != null) {
            map.get(v1).remove(v2);       //Removes v2 from v1's adjacency list
            map.get(v2).remove(v1);       //Removes v1 from v2's adjacency list
        }
    }

    /**
     * Performs a depth-first traversal
     * @param s - Value of the starting vertex
     */
    public void traverseD(String s) {
        Stack<Vertex> stack = new Stack<Vertex>();
        Vertex v = null;
        //Find the starting vertex
        for(int i = 0; i < vertices.size(); i++) {
            if(vertices.get(i).value.equals(s)) {
                v = vertices.get(i);
            }
        }
        if(v == null) {
            return; //Starting vertex not found
        }

        stack.push(v);
        v.color = 1;                    //Set current vertex's color to gray
        while(!stack.empty()) {
            v = stack.pop();
            for(Vertex t : map.get(v)) {
                //Adjacent white vertices
                if(t.color == 0) {
                    t.color = 1;            //Set the adj. vertex's color to gray
                    stack.push(t);          //Push the adj. vertex on to the stack
                }
            }
            System.out.print(v.value + " ");
            v.color = 2;
        }

        //Reset all vertices back to white
        for(int i = 0; i < vertices.size(); i++) {
            vertices.get(i).color = 0;
        }

        System.out.println();
    }

    /**
     * Performs a breadth-first search
     * @param s - Value of the starting vertex
     */
    public void traverseB(String s) {
        LinkedList<Vertex> queue = new LinkedList<Vertex>();    //LinkedList used as a queue
        Set<Vertex> seen = new HashSet<Vertex>();               //Set (structure that does not allow duplicates)

        Vertex v = null;
        //Find the starting vertex
        for(int i = 0; i < vertices.size(); i++) {
            if(vertices.get(i).value.equals(s)) {
                v = vertices.get(i);
            }
        }
        if(v == null) {
            return; //Starting vertex not found
        }

        //Add the starting vertex to the queue and "seen" set
        queue.add(v);
        seen.add(v);
        while(!queue.isEmpty()) {
            v = queue.poll();
            //For each vertex in its adjacency list
            for(Vertex t : map.get(v)) {
                //Add unseen vertices to the queue and "seen" set
                if(!seen.contains(t)) {
                    queue.add(t);
                    seen.add(t);
                }
            }
            System.out.print(v.value + " ");
        }
        System.out.println();
    }
}
