package PROGRAMAS_EM_JAVA.EstruturaDeDados.TrabalhoMenu2.PontoDeArticulação;

import java.util.Arrays;

public class EncontrarPonto {
    private int tempo;

    public void encontrarPontos(int[][] matriz) {
        int V = matriz.length;
        boolean[] visitado = new boolean[V];
        int[] discovery = new int[V]; //tempo para um determinado vertice ser descoberto pelo dfs, ou seja, o número de vertices que passa para chegar nele.
        int[] low = new int[V]; //Menor tempo que leva para descobir um determinado nó ou os seus filhos
        int[] pai = new int[V];
        boolean[] articulacao = new boolean[V];

        Arrays.fill(pai, -1); //estou instanciando valores -1 para todas as posições, para inicialmente todos os pais dos vertices serem nulos, ou seja, cada vertice não ter pai.
        tempo = 0;

        //Laço de repetição para verificar se o grafo é desconexo e iniciar a exploração do vertice
        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                dfs(i, visitado, discovery, low, pai, articulacao, matriz);
            }
        }

        System.out.print("Pontos de articulação: ");
        for (int i = 0; i < V; i++) {
            if (articulacao[i]) {
                System.out.print(i + " ");
            }
        }
    }

    private void dfs(int u, boolean[] visitado, int[] discovery, int[] low, int[] pai, boolean[] articulacao, int[][] matriz) {
        visitado[u] = true;
        discovery[u] = low[u] = ++tempo;
        int filhos = 0;
        articulacao[u] = false;

        for (int v = 0; v < matriz.length; v++) {
            if (matriz[u][v] == 1) {
                if (!visitado[v]) {
                    filhos++;
                    pai[v] = u;
                    dfs(v, visitado, discovery, low, pai, articulacao, matriz);

                    low[u] = Math.min(low[u], low[v]);

                    if (pai[u] == -1 && filhos > 1)
                        articulacao[u] = true;

                    if (pai[u] != -1 && low[v] >= discovery[u])
                        articulacao[u] = true;

                } else if (v != pai[u]) {
                    low[u] = Math.min(low[u], discovery[v]);
                }
            }
        }
    }

}
