package PROGRAMAS_EM_JAVA.EstruturaDeDados.ALgoritimosDeMenorCaminho.domain;

public class GraphDijkitra {
    private int[][] matrisAdj;
    private String[] verticeDado;
    private int size;

    public GraphDijkitra(int tam) {
        matrisAdj = new int[tam][tam];
        verticeDado = new String[tam];
        size = tam;
    }

    public void addVertice(int vetice, String dado) {
        if (vetice >= 0 && vetice < size) {
            this.verticeDado[vetice] = dado;
        }
    }

    public void addElemento(int u, int v, int peso) {
        if (u < size && v < size && u >= 0 && v >= 0) {
            matrisAdj[u][v] = peso;
            matrisAdj[v][u] = peso;
        }
    }

    public int[] dijkitra(String verticeInicio) {
        int inicio = retornaIndice(verticeInicio);
        int[] distancias = new int[size];
        boolean[] visitado = new boolean[size];

        for (int i = 0; i < size; i++) {
            distancias[i] = Integer.MAX_VALUE;
        }
        distancias[inicio] = 0;

        for (int i = 0; i < size; i++) {
            int u = distanciaMin(distancias, visitado);
            if (u == -1) break;

            visitado[u] = true;
            for (int v = 0; v < size; v++) {
                if (!visitado[v] && matrisAdj[u][v] != 0 && distancias[u] != Integer.MAX_VALUE) {
                    int newDistance = distancias[u] + this.matrisAdj[u][v];
                    if (newDistance < distancias[v]) {
                        distancias[v] = newDistance;
                    }
                }
            }
        }
        return distancias;
    }

    private int retornaIndice(String data) {
        for (int i = 0; i < size; i++) {
            if (verticeDado[i].equals(data)) {
                return i;
            }
        }
        return -1;
    }

    private int distanciaMin(int[] distancia, boolean[] visitado) {
        int min = Integer.MAX_VALUE, minIndex = -1;

        for (int i = 0; i < size; i++) {
            if (!visitado[i] && distancia[i] <= min) {
                min = distancia[i];
                minIndex = i;
            }
        }

        return minIndex;
    }

    public String getVerticeDado(int index) {
        return verticeDado[index];
    }
}

