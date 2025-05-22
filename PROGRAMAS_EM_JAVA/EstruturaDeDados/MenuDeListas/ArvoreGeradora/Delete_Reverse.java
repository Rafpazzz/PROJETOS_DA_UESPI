package PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.ArvoreGeradora;

import java.util.*;


public class Delete_Reverse {
    private int V;
    private List<Integer>[] adj;
    private List<Edge> edges;
    private String[] vertexNames;

    class Edge implements Comparable<Edge> {
        int u, v, w;

        Edge(int u, int v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }

        public int compareTo(Edge other) {
            return this.w - other.w;
        }
    }

    @SuppressWarnings("unchecked")
    public Delete_Reverse(int[][] matrix, String[] vertexNames) {
        this.V = matrix.length;
        this.adj = new ArrayList[V];
        this.edges = new ArrayList<>();
        this.vertexNames = vertexNames.clone();

        for (int i = 0; i < V; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                if (matrix[i][j] != 0) {
                    adj[i].add(j);
                    adj[j].add(i);
                    edges.add(new Edge(i, j, matrix[i][j]));
                }
            }
        }
    }

    private void DFS(int v, boolean[] visited) {
        visited[v] = true;
        for (int i : adj[v]) {
            if (!visited[i]) {
                DFS(i, visited);
            }
        }
    }

    private boolean isConnected() {
        boolean[] visited = new boolean[V];
        DFS(0, visited);
        for (boolean v : visited) {
            if (!v) return false;
        }
        return true;
    }

    public void reverseDeleteMST() {
        Collections.sort(edges); // sort by weight
        int mstWeight = 0;

        System.out.println("Arestas da AGM (Reverse-Delete):");
        for (int i = edges.size() - 1; i >= 0; i--) {
            Edge e = edges.get(i);
            int u = e.u;
            int v = e.v;

            adj[u].remove(Integer.valueOf(v));
            adj[v].remove(Integer.valueOf(u));

            if (!isConnected()) {
                adj[u].add(v);
                adj[v].add(u);
                System.out.println(vertexNames[u] + " - " + vertexNames[v] + "\t" + e.w);
                mstWeight += e.w;
            }
        }

        System.out.println("Peso total da AGM: " + mstWeight);
    }
}
