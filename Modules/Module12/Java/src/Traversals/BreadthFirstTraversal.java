package Traversals;

public class DepthFirstTraversal {

    public static void main(String[] args) {
        Graph g = new Graph();
        g.addVertex("A");
        g.addVertex("B");
        g.addVertex("C");
        g.addVertex("D");
        g.addVertex("E");
        g.addVertex("F");
        g.addVertex("G");
        g.addVertex("H");

        g.addEdge("A", "C");
        g.addEdge("A", "D");
        g.addEdge("B", "F");
        g.addEdge("F", "H");
        g.addEdge("H", "D");
        g.addEdge("H", "E");
        g.addEdge("D", "C");
        g.addEdge("D", "G");
        g.addEdge("G", "C");

        g.traverse("B");
    }

}
