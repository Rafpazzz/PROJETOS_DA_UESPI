package PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.ArvoreGeradora;

import java.util.*;


public class Kruskal {
    int V;
    String[] vertexNames;
    List<Edge> edges;

    class Edge implements Comparable<Edge> {
        int src, dest, weight;

        Edge(int s, int d, int w) {
            src = s;
            dest = d;
            weight = w;
        }

        @Override
        public int compareTo(Edge other) {
            return this.weight - other.weight;
        }
    }

    class Subset {
        int parent, rank;
    }

    public Kruskal(int size, String[] names) {
        V = size;
        edges = new ArrayList<>();
        vertexNames = new String[size];
        vertexNames = names.clone();
    }

    public void addEdge(int[][] matrix) {
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                if (matrix[i][j] != 0) {
                    edges.add(new Edge(i, j, matrix[i][j]));
                }
            }
        }
    }

    public int find(Subset[] subsets, int i) {
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }

    public void union(Subset[] subsets, int x, int y) {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);

        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }

    public void KruskalMST() {
        List<Edge> result = new ArrayList<>();
        Collections.sort(edges);

        Subset[] subsets = new Subset[V];
        for (int v = 0; v < V; ++v) {
            subsets[v] = new Subset();
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }

        for (Edge edge : edges) {
            int x = find(subsets, edge.src);
            int y = find(subsets, edge.dest);

            if (x != y) {
                result.add(edge);
                union(subsets, x, y);
            }
        }

        System.out.println("Aresta \tPeso");
        for (Edge e : result)
            System.out.println(vertexNames[e.src] + " - " + vertexNames[e.dest] + "\t" + e.weight);
    }
}

