package PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.ArvoreGeradora;

import java.util.Arrays;

public class Prim {
    int size;
    int[][] adjMatrix;
    boolean[] inMST; //verificar se um i pertence a MST
    int[] keyValues; //armazena o menor peso de aresta para conectar um vértice ainda não incluído à MST
    int[] parents; //armazena o pai de cada vértice na MST
    String[] vertexData;

    public Prim(int[][] matrix, String[] vertexNames) {
        this.size = matrix.length;
        this.adjMatrix = new int[size][size];
        this.inMST = new boolean[size];
        this.keyValues = new int[size];
        this.parents = new int[size];
        this.vertexData = vertexNames.clone();

        //todas as distâncias inicialmente são infinitas e ninguém possui um pai inicialmente
        for (int i = 0; i < size; i++) {
            keyValues[i] = Integer.MAX_VALUE;
            parents[i] = -1;
        }

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (matrix[i][j] != 0) {
                    adjMatrix[i][j] = matrix[i][j];
                    adjMatrix[j][i] = matrix[i][j];
                }
            }
        }
    }

    public void primsAlgorithm() {
        keyValues[0] = 0;

        System.out.println("Aresta\tPeso");
        for (int i = 0; i < size; i++) {
            int u = -1;
            int min = Integer.MAX_VALUE;
            for (int v = 0; v < size; v++) {
                if (!inMST[v] && keyValues[v] < min) {
                    min = keyValues[v];
                    u = v;
                }
            }

            inMST[u] = true;

            if (parents[u] != -1) {
                System.out.println(vertexData[parents[u]] + "-" + vertexData[u] + "\t" + adjMatrix[u][parents[u]]);
            }

            //atualizar o vizinho de "u"
            for (int v = 0; v < size; v++) {
                //verifica quais são os vizinhos do índice "u"
                if (adjMatrix[u][v] != 0 && !inMST[v] && adjMatrix[u][v] < keyValues[v])  {
                    parents[v] = u; // u vira pai de v
                    keyValues[v] = adjMatrix[u][v]; //atualiza o custo para chegar no índice representado por "v"
                }
            }
        }
    }
}
