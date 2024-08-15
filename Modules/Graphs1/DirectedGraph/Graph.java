package DirectedGraph;

import java.util.ArrayList;
import java.util.HashMap;
import Graph.Vertex;

/**
 * Implementation of a directed, unweighted graph
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
        //link it with a new adjacency list
        Vertex t = new Vertex(v);
        vertices.add(t);
        map.put(t, new ArrayList<Vertex>());
    }

    /**
     * Adds a directed edge between two vertices
     * @param s1 - The value of the first vertex (FROM)
     * @param s2 - The value of the second vertex (TO)
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
        }
    }

    /**
     * Prints the contents of the graph.
     * Format: Vertex ---> Adjacent Vertices
     */
    public void printGraph() {
        //For each vertex in the graph
        for(int i = 0; i < vertices.size(); i++) {
            //Print the vertex's value
            Vertex v = vertices.get(i);
            System.out.print(v.value);
            System.out.print(" ---> ");

            //Get the vertex's adjacency list
            ArrayList<Vertex> adjList = map.get(v);

            //For each vertex in its adjacency list
            for(int j=0; j<adjList.size(); j++) {
                System.out.print(adjList.get(j).value + " ");    //The adjacent vertex's value
            }
            System.out.println();
        }
    }
}
