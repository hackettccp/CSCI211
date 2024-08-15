/**
 * Graph Vertex
 */
public class Vertex {

    /**
     * Value stored in the vertex
     */
    public String value;

    /**
     * Vertex's color
     * 0 = white
     * 1 = gray
     * 2 = black
     */
    int color = 0;

    /**
     * Constructor
     * @param v - The value to store in the vertex
     */
    public Vertex(String v) {
        value = v;
    }

}
