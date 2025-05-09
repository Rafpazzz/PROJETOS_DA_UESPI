package PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.MenorCaminho;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class MenorCaminhoNãoDirecionado {
    private int vertices;
    private LinkedList<Integer>[] adjacentes;

    public MenorCaminhoNãoDirecionado(int vertices) {
        this.vertices = vertices;
        adjacentes = new LinkedList[vertices];
        for (int i = 0; i < vertices; i++) {
            adjacentes[i] = new LinkedList<>();
        }
    }

    public void adicionarAresta(int vertice, int vizinho) {
        adjacentes[vertice].add(vizinho);
    }

    public LinkedList<Integer> getAdjacentes(int vertice) {
        return adjacentes[vertice];
    }

    public void bfs(MenorCaminhoDirecionado grafo, int inicio) {
        Queue<Integer> fila = new LinkedList<>();
        HashSet<Integer> visitados = new HashSet<>();

        fila.add(inicio);
        visitados.add(inicio);

        while (!fila.isEmpty()) {
            int vertice = fila.poll();
            System.out.println("Visitando: " + vertice);

            for (int vizinho : grafo.getAdjacentes(vertice)) {
                if (!visitados.contains(vizinho)) {
                    fila.add(vizinho);
                    visitados.add(vizinho);
                }
            }
        }
    }
}
