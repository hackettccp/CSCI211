public class BreadthFirstTraversal {

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

        g.addEdge("A", "B");
        g.addEdge("A", "C");
        g.addEdge("A", "D");
        g.addEdge("B", "C");
        g.addEdge("B", "E");
        g.addEdge("B", "F");
        g.addEdge("C", "D");
        g.addEdge("C", "G");
        g.addEdge("D", "G");
        g.addEdge("D", "H");
        g.addEdge("E", "H");
        g.addEdge("F", "H");
        g.addEdge("H", "G");

        g.traverseB("H");
    }

}
