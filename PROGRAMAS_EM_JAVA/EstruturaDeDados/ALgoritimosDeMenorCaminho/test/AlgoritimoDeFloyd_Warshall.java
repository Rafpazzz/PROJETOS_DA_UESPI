package PROGRAMAS_EM_JAVA.EstruturaDeDados.ALgoritimosDeMenorCaminho.test;

public class AlgoritimoDeFloyd_Warshall {
    final static int INF = 9999999;
    private final int tam;

    public AlgoritimoDeFloyd_Warshall(int tam) {
        this.tam = tam;
    }

    public void floydMarshall(int[][] garph) {
        int[][] matrix = new int[tam][tam];
        int i, j, k;

        for(i= 0; i < tam; i++) {
            for(j = 0; j < tam; j++) {
                matrix[i][j] = garph[i][j];
            }
        }

        for(k = 0; k<tam; k++) {
            for(i= 0; i<tam; i++) {
                for(j = 0; j<tam; j++) {
                    if(matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
        printMatrix(matrix);
    }

    public void printMatrix(int[][] matrix) {
        for (int i = 0; i < tam; ++i) {
            for (int j = 0; j < tam; ++j) {
                if (matrix[i][j] == INF)
                    System.out.print("INF ");
                else
                    System.out.print(matrix[i][j] + "  ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int graph[][] = {{0, 3, INF, 5}, {2, 0, INF, 4}, {INF, 1, 0, INF}, {INF, INF, 2, 0}};
        AlgoritimoDeFloyd_Warshall a = new AlgoritimoDeFloyd_Warshall(4);
        a.floydMarshall(graph);
    }
}
