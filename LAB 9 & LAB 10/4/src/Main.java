import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

class Edge {
    public String start; // start node of an edge
    public String end;  //  End node of an edge
    public int cost;    //  cost of wire

    Edge(String s, String e, int w) {
        start =s;
        end =e;
        cost =w;
    }
} // end of edge class

class Graph {
    public static ArrayList<Edge> list_edges; // list of edges of a graph

    Graph(ArrayList<Edge> n) {
        list_edges = n;
    }

    public void removeLoop() {
        //Q.1.1 write the java code to remove loops from the list_edges:ArrayList. */

        //                int temp = list_edges.indexOf(x);
        list_edges.removeIf(x -> x.start.equals(x.end));
    }

    public Edge findParallelEdge(Edge n) {
        //Q.1.2 This function finds a parallel edge of n:Edge inlist_edges:ArrayList.
        // If parallel edge exists it returns parallel edge otherwise null. Write the java code*/
            for (Edge x: list_edges) {
                if(x.start.equals(n.start) && x.end.equals(n.end)) {
                    return x;
                }
            }

            return null;
    }

    public void removeParallel() {
        //Q.1.3 This method traverses list_edges:ArrayList and finds a parallel edge.
        // if an Edge’s parallel edge is found and Edge’s cost is higher than parallel edge it removes Edge.
        // Write the java code */
        for (int i=0; i<list_edges.size(); i++) {
            for (int j=i+1; j<list_edges.size(); j++) {
                if(list_edges.get(i).start.equals(list_edges.get(j).start) && list_edges.get(i).end.equals(list_edges.get(j).end)) {
                    if(list_edges.get(i).cost<=list_edges.get(j).cost) {
                        list_edges.remove(j);
                    } else {
                        list_edges.remove(i);
                    }
                }
            }
        }
    }

    public void print() {
       // Q.1.4 write the java code to print edges of list_edges:ArrayList
        for (Edge x: list_edges) {
            System.out.println(x.start + " ------> " + x.end + "   Cost: " + x.cost);
        }
    }
}

public class Main {
    public static void main(String[] Args) {
        Scanner sc = new Scanner(System.in);
        Edge[] e = new Edge[7];

        e[0] = new Edge("Jaipur", "Pilani", 5);
        e[1] = new Edge("Jaipur", "Delhi", 1);
        e[2] = new Edge("Jaipur", "Sikar", 2);
        e[3] = new Edge("Sikar", "Delhi", 2);
        e[4] = new Edge("Sikar", "Delhi", 12);
        e[5] = new Edge("Delhi", "Pilani", 3);
        e[6] = new Edge("Pilani", "Pilani", 4);

        ArrayList<Edge> graph = new ArrayList<>(Arrays.asList(e).subList(0, 7));


        Graph g = new Graph(graph);
        System.out.println("The Initial Graph is: ");
        g.print();
        System.out.println();

        g.removeLoop();
        System.out.println("After Removing Self Loop, Graph is: ");
        g.print();
        System.out.println();

        Edge temp = g.findParallelEdge(e[3]);
        if(temp!=null) {
            System.out.println("Found Parallel edge for: " + temp.start + "------>" + temp.end);
        } else {
            System.out.println("Not having parallel Edge");
        }
        System.out.println();

        g.removeParallel();
        System.out.println("After removing costlier parallel edge, Graph is");
        g.print();
    }

}
