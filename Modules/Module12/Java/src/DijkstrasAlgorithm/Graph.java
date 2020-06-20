package DjikstrasAlgorithm;

import java.util.*;

/**
 * Implementation of an undirected, unweighted graph
 * Using Adjacency Lists
 */
public class Graph {

    private class AdjVertex {
        int cost;
        Vertex vertex;

        AdjVertex(int c, Vertex v) {
            cost = c;
            vertex = v;
        }
    }

    /**
     * Inner class that represents a vertex in the graph
     */
    private class Vertex {
        /**
         * Value stored in the vertex
         */
        String value;

        /**
         * Constructor
         * @param v - The value to store in the vertex
         */
        Vertex(String v) {
            value = v;
        }

    }

    /**
     * The vertices contained in the graph.
     * Stored in an ArrayList of Vertex objects
     */
    ArrayList<Vertex> vertices;

    /**
     * A HashMap linking a Vertex to an ArrayList.
     * An ArrayList of AdjVertex objects is used for the adjacency list
     */
    HashMap<Vertex, ArrayList<AdjVertex>> map;

    /**
     * No-Arg Constructor
     * Instantiates the ArrayList of vertices and the HashMap
     */
    public Graph() {
        vertices = new ArrayList<Vertex>();
        map = new HashMap<Vertex, ArrayList<AdjVertex>>();
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
        map.put(t, new ArrayList<AdjVertex>());
    }

    /**
     * Adds an (undirected) edge between two vertices
     * @param s1 - The value of the first vertex
     * @param s2 - The value of the second vertex
     */
    public void addEdge(String s1, String s2, int cost) {
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
            map.get(v1).add(new AdjVertex(cost, v2));       //Adds v2 to v1's adjacency list
            //map.get(v2).add(new AdjVertex(cost, v1));       //Adds v1 to v2's adjacency list
        }
    }

    public void dijkstrasAlgorithm(String s) {
        Set<Vertex> done = new HashSet<Vertex>();
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

        HashMap<Vertex, Integer> costs = new HashMap<Vertex, Integer>();
        for(int i = 0; i < vertices.size(); i++) {
            costs.put(vertices.get(i), Integer.MAX_VALUE);
        }
        costs.put(v, 0);

        PriorityQueue pq = new PriorityQueue(new Compare());

        for(AdjVertex av : map.get(v)) {
            costs.put(av.vertex, costs.get(v) + av.cost);
            pq.add(av);
        }
        done.add(v);
        AdjVertex t;
        while(!pq.isEmpty()) {
            t = (AdjVertex)pq.poll();
            for(AdjVertex av : map.get(t.vertex)) {
                int currentcost = costs.get(av.vertex);
                int possiblecost = costs.get(t.vertex) + av.cost;
                if(possiblecost < currentcost) {
                    costs.put(av.vertex, possiblecost);
                }
                if(!done.contains(av.vertex)) {
                    pq.add(av);
                }
            }
            done.add(t.vertex);
        }

        Set<Vertex> keys = costs.keySet();
        for(Vertex k : keys) {
            System.out.print("Cost from ");
            System.out.print(s);
            System.out.print(" to ");
            System.out.print(k.value);
            System.out.print(" = ");
            System.out.println(costs.get(k));
        }


    }

    public class Compare implements Comparator {
        @Override
        public int compare(Object v1, Object v2) {
            if(((AdjVertex)v1).cost < ((AdjVertex)v2).cost) {
                return -1;
            }
            if(((AdjVertex)v1).cost > ((AdjVertex)v2).cost) {
                return 1;
            }
            return 0;
        }
    }

}
