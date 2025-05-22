package PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.ArvoreGeradora;

import java.util.*;

public class OrdenaMaiorMenor {
    private int V;
    private String[] vertexNames;
    private List<Edge> edges;

    class Edge {
        int u, v, weight;

        Edge(int u, int v, int weight) {
            this.u = u;
            this.v = v;
            this.weight = weight;
        }
    }

    public OrdenaMaiorMenor(int[][] matrix, String[] vertexNames) {
        this.V = matrix.length;
        this.vertexNames = vertexNames.clone();
        this.edges = new ArrayList<>();

        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                if (matrix[i][j] != 0) {
                    edges.add(new Edge(i, j, matrix[i][j]));
                }
            }
        }
    }

    public void sortEdgesAscending() {
        edges.sort(Comparator.comparingInt(e -> e.weight));
        System.out.println("Arestas em ordem crescente de peso:");
        for (Edge e : edges) {
            System.out.println(vertexNames[e.u] + " - " + vertexNames[e.v] + "\t" + e.weight);
        }
    }

    public void sortEdgesDescending() {
        edges.sort((e1, e2) -> Integer.compare(e2.weight, e1.weight));
        System.out.println("Arestas em ordem decrescente de peso:");
        for (Edge e : edges) {
            System.out.println(vertexNames[e.u] + " - " + vertexNames[e.v] + "\t" + e.weight);
        }
    }
}
