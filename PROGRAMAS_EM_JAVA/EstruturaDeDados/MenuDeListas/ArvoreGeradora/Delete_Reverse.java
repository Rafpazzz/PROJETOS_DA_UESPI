package PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.ArvoreGeradora;

import java.util.*;


public class Delete_Reverse {
    private int V;
    private List<Integer>[] adj;
    private List<Edge> edges;
    private String[] vertexNames;

    class Edge implements Comparable<Edge> {
        int u, v, wength;

        Edge(int u, int v, int wength) {
            this.u = u;
            this.v = v;
            this.wength = wength;
        }

        public int compareTo(Edge other) {
            return this.wength - other.wength;
        }
    }

    @SuppressWarnings("unchecked") //nao mostrar a mensagem de warning no compilador, devido o compilador nao garantir a segurança de tipos genericos
    public Delete_Reverse(int[][] matrix, String[] vertexNames) {
        this.V = matrix.length;
        this.adj = new ArrayList[V]; //criando uma lista de valores generics, ou seja, aqui pode entrar qualquer valor
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

    //marca todos os vertices a partir de "v" como true, somente aqueles que é possivel ser visitado
    private void DFS(int v, boolean[] visited) {
        visited[v] = true;
        for (int i : adj[v]) {
            if (!visited[i]) {
                DFS(i, visited);
            }
        }
    }

    //verifica se o grafo está conexo ou não
    private boolean isConnected() {
        boolean[] visited = new boolean[V];
        DFS(0, visited);
        for (boolean v : visited) {
            if (!v) return false;
        }
        return true;
    }

    public void reverseDeleteMST() {
        Collections.sort(edges); // ordencação dos pesos ordem crescente
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
                System.out.println(vertexNames[u] + " - " + vertexNames[v] + "\t" + e.wength);
                mstWeight += e.wength;
            }
        }

        System.out.println("Peso total da AGM: " + mstWeight);
    }
}
