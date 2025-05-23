package PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.MenorCaminho;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class MenorCaminhoDirecionado {
    private int vertices;
    private LinkedList<Integer>[] adjacentes;

    public MenorCaminhoDirecionado(int vertices) {
        this.vertices = vertices;
        adjacentes = new LinkedList[vertices];
        for (int i = 0; i < vertices; i++) {
            adjacentes[i] = new LinkedList<>();
        }
    }

    public void adicionarAresta(int [][] matrix) {
        for(int i = 0; i<vertices; i++) {
            for(int j = 0; j<vertices; j++) {
                if(matrix[i][j] == 1) {
                    adjacentes[i].add(j);
                }
            }
        }
    }

    public LinkedList<Integer> getAdjacentes(int vertice) {
        return adjacentes[vertice];
    }

    public void bfs(MenorCaminhoDirecionado grafo, int inicio) {
        Queue<Integer> fila = new LinkedList<>();
        HashSet<Integer> visitados = new HashSet<>();

        fila.add(inicio);
        visitados.add(inicio);

        System.out.print("Vertice visitado a partir do indide " + inicio + ": ");

        while (!fila.isEmpty()) {
            int vertice = fila.poll();
            System.out.print(vertice);

            for (int vizinho : grafo.getAdjacentes(vertice)) {
                if (!visitados.contains(vizinho)) {
                    fila.add(vizinho);
                    visitados.add(vizinho);
                }
            }
        }
    }
}
