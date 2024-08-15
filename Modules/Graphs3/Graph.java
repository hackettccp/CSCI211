import java.util.*;

/**
 * Implementation of a directed, weighted graph
 */
public class Graph {

    /**
     * Wrapper class for Vertex objects
     * Associates a cost with the edge to this vertex
     */
    private class AdjVertex {
        int cost;                       //Cost of the edge
        Vertex vertex;                  //The adjacent vertex

        AdjVertex(int c, Vertex v) {
            cost = c;
            vertex = v;
        }
    }

    /**
     * Comparator for comparing costs (prioritizing) in the priority queue
     * Lowest cost == highest priority
     */
    public class VertexCompare implements Comparator {
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

        Vertex t = new Vertex(v);                   //Create the new vertex,
        vertices.add(t);                            //Add it to the graph's list of vertices
        map.put(t, new ArrayList<AdjVertex>());     //Pair it with a new adjacency list in the map
    }

    /**
     * Adds a directed edge between two vertices
     * @param s1 - The value of the first vertex
     * @param s2 - The value of the second vertex
     * @param cost - The cost of this edge
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
        }
    }

    /**
     * Dijkstra's Algorithm
     * Finds and displays the path with the least cost from a
     * starting vertex to every other vertex
     * @param s - The value of the starting vertex
     */
    public void dijkstrasAlgorithm(String s) {
        Set<Vertex> done = new HashSet<Vertex>();              //Set of (non-duplicated) vertices; prevents revisiting a visited vertex
        Vertex v = null;
        //Find the starting vertex
        for(int i = 0; i < vertices.size(); i++) {
            if(vertices.get(i).value.equals(s)) {
                v = vertices.get(i);
            }
        }
        if(v == null) {
            return;                                            //Starting vertex not found
        }

        HashMap<Vertex, Integer> costs = new HashMap<Vertex, Integer>();     //Keeps track of the cost (value) to a vertex (key)
        for(int i = 0; i < vertices.size(); i++) {
            costs.put(vertices.get(i), Integer.MAX_VALUE);     //Initialize each cost to a large number
        }
        costs.put(v, 0);                                       //Cost from starting vertex to itself is 0

        //Priority queue (heap) keeps the edge/vertex with the least cost at the front of the queue
        PriorityQueue pq = new PriorityQueue(new VertexCompare());

        //Get the costs to the vertices adjacent to the starting vertex
        //Queue the adjacent vertices
        for(AdjVertex av : map.get(v)) {
            costs.put(av.vertex, costs.get(v) + av.cost);
            pq.add(av);
        }
        done.add(v); //Done with the starting queue
        AdjVertex t;
        while(!pq.isEmpty()) {
            t = (AdjVertex)pq.poll();                               //Get the queued vertex with the lowest cost
            for(AdjVertex av : map.get(t.vertex)) {                 //Look at each adjacent vertex
                int currentcost = costs.get(av.vertex);             //Current cost to this adjacent vertex from the starting vertex
                int possiblecost = costs.get(t.vertex) + av.cost;   //Potential lower cost to this adjacent vertex from the starting vertex
                if(possiblecost < currentcost) {
                    costs.put(av.vertex, possiblecost);             //New lower cost
                }
                if(!done.contains(av.vertex)) {
                    pq.add(av);                                     //Add any adjacent vertices that have not been visited
                }
            }
            done.add(t.vertex);                                     //Done with this vertex
        }

        //Print the costs
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



}
