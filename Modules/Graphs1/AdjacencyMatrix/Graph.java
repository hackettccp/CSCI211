package AdjacencyMatrix;

import Graph.Vertex;

/**
 * Implementation of an undirected, unweighted graph
 * Using an Adjacency Matrix
 */
public class Graph {

    /**
     * The vertices contained in the graph.
     * Stored in an Array of Vertex objects
     */
    Vertex[] vertices;

    /**
     * A 2D array representing edges between vertices
     */
    int[][] map;

    /**
     * Constructor
     * Instantiates the array of vertices and adjacency matrix
     * @param size - The max number of vertices in the graph
     */
    public Graph(int size) {
        vertices = new Vertex[size];
        map = new int[size][size];
    }

    /**
     * Adds a new vertex to the graph
     * @param v - The value to be stored in the new vertex
     */
    public void addVertex(String v) {
        for(int i=0; i < vertices.length; i++) {
            //Find an index not in use
            if(vertices[i] != null) {
                //Check if the vertex already exists
                if(vertices[i].value.equals(v)) {
                    return;
                }
            }
            else {
                //New vertex is added at this available index
                vertices[i] = new Vertex(v);
                return;
            }
        }
    }

    /**
     * Adds an (undirected) edge between two vertices
     * @param s1 - The value of the first vertex
     * @param s2 - The value of the second vertex
     */
    public void addEdge(String s1, String s2) {
        int e1 = -1;    //Array index of first vertex
        int e2 = -1;    //Array index of second vertex

        //Check that the two vertices with these values exist
        //If found, remember the index
        for(int i=0; i<vertices.length; i++) {
            if(vertices[i].value.equals(s1)) {
                e1 = i;
            }
            else if(vertices[i].value.equals(s2)) {
                e2 = i;
            }
        }
        //Update adjacency matrix
        if(e1 >= 0 && e2 >= 0) {
            map[e1][e2] = 1;
            map[e2][e1] = 1;
        }
    }

    /**
     * Removes a directed edge between two vertices
     * @param s1 - The value of the first vertex (FROM)
     * @param s2 - The value of the second vertex (TO)
     */
    public void removeEdge(String s1, String s2) {
        int e1 = -1;    //Array index of first vertex
        int e2 = -1;    //Array index of second vertex

        //Check that the two vertices with these values exist
        //If found, remember the index
        for(int i=0; i<vertices.length; i++) {
            if(vertices[i].value.equals(s1)) {
                e1 = i;
            }
            else if(vertices[i].value.equals(s2)) {
                e2 = i;
            }
        }
        //Update adjacency matrix
        if(e1 >= 0 && e2 >= 0) {
            map[e1][e2] = 0;
            map[e2][e1] = 0;
        }
    }

    /**
     * Prints the contents of the graph.
     * Format: Vertex ---> Adjacent Vertices
     */
    public void printGraph() {
        //For each vertex in the graph
        for(int i = 0; i < vertices.length; i++) {
            //Print the vertex's value
            System.out.print(vertices[i].value);
            System.out.print(" ---> ");

            //For each index in that vertex's row of the adjacency matrix
            for(int j=0; j<map.length; j++) {
                //If an edge exists
                if(map[i][j] == 1) {
                    System.out.print(vertices[j].value + " ");  //Print the adjacent vertex's value
                }
            }
            System.out.println();
        }
    }
}
