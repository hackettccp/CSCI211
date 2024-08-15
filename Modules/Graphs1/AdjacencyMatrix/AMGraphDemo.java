package AdjacencyMatrix;

public class AMGraphDemo {

    public static void main(String[] args) {

        Graph g = new Graph(6);
        g.addVertex("A");
        g.addVertex("B");
        g.addVertex("C");
        g.addVertex("D");
        g.addVertex("E");
        g.addVertex("F");

        g.addEdge("A", "C");
        g.addEdge("A", "F");
        g.addEdge("B", "C");
        g.addEdge("D", "E");
        g.addEdge("C", "F");

        g.printGraph();

        System.out.println();

        g.removeEdge("B", "C");

        g.printGraph();
    }

}
