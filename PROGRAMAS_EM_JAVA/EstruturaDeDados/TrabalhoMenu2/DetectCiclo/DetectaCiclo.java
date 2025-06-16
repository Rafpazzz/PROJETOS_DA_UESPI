package PROGRAMAS_EM_JAVA.EstruturaDeDados.TrabalhoMenu2.DetectCiclo;

public class DetectaCiclo {

    private boolean dfs(int v, int[][] matriz, boolean[] visitado, boolean[] emResursao) { //busca em profundidade
        visitado[v] = true;
        emResursao[v] = true;

        for (int u = 0; u < matriz.length; u++) {
            if (matriz[v][u] == 1) { // Existe uma aresta de v para u
                if (!visitado[u]) {
                    if (dfs(u, matriz, visitado, emResursao)) {
                        return true;
                    }
                } else if (emResursao[u]) {
                    return true; // Ciclo encontrado
                }
            }
        }

        emResursao[v] = false;
        return false;
    }


    public String isCyclic(int[][] matix, int size) {

        boolean[] visitado = new boolean[size];
        boolean[] ciclo = new boolean[size];

        // Verifica cada vértice
        for (int i = 0; i < size; i++) {
            if (!visitado[i]) {
                if (dfs(i, matix, visitado, ciclo)) {
                    return "Ciclo detectado"; // Ciclo detectado
                }
            }
        }

        return "Ciclo não detectado"; // Nenhum ciclo encontrado
    }
}
