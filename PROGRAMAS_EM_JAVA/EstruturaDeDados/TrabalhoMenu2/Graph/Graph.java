package PROGRAMAS_EM_JAVA.EstruturaDeDados.TrabalhoMenu2.Graph;

public class Graph {
    private int[][] matrisAdj;
    private String[] verticeDado;
    private int size;

    public Graph(int tam) {
        matrisAdj = new int[tam][tam];
        verticeDado = new String[tam];
        size = tam;

        for(int i = 0; i<tam; i++) {
            for(int j = i+1; j<tam; j++) {
                matrisAdj[i][j] = 0;
            }
        }
    }

    public void addVertice(String dado, int vetice) {
        if (vetice >= 0 && vetice < size) {
            this.verticeDado[vetice] = dado;
        }
    }

    public void graphDirecionado(int u, int v) {
        if (u < size && v < size && u >= 0 && v >= 0) {
            matrisAdj[u][v] = 1;
        }
    }

    public void graphNaoDirecionado(int u, int v) {
        if (u < size && v < size && u >= 0 && v >= 0) {
            matrisAdj[u][v] = 1;
            matrisAdj[v][u] = 1;
        }
    }

    public int[][] getMatrisAdj() {
        return matrisAdj;
    }

}
