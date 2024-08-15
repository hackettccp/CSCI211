public class Demo {

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

        g.addEdge("A", "C", 5);
        g.addEdge("B", "A", 10);
        g.addEdge("B", "C", 1);
        g.addEdge("B", "E", 2);
        g.addEdge("B", "F", 3);
        g.addEdge("D", "A", 3);
        g.addEdge("D", "C", 3);
        g.addEdge("D", "H", 4);
        g.addEdge("E", "H", 1);
        g.addEdge("F", "H", 1);
        g.addEdge("G", "C", 1);
        g.addEdge("G", "D", 5);
        g.addEdge("H", "G", 4);

        g.dijkstrasAlgorithm("B");
    }

}
