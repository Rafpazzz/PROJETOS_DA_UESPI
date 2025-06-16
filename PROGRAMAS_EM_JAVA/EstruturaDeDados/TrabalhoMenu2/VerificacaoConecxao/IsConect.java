package PROGRAMAS_EM_JAVA.EstruturaDeDados.TrabalhoMenu2.VerificacaoConecxao;

public class IsConect {

    public void dfs(int v, int[][] matrix, boolean[] visitado) {
        visitado[v] = true;
        for(int i = 0; i<matrix.length; i++) {
            if(matrix[v][i] == 1 && !visitado[i]) {
                dfs(i, matrix, visitado);
            }
        }
    }

    public boolean isConexo(int [][] matrix, int size ) {
        boolean[] visitado = new boolean[size];
        dfs(0, matrix, visitado);

        //retorna se encontrar um vertice desconexo.
        for(boolean v : visitado) {
            if(!v) return true;
        }

        //retorna se não encontra vertice desconexo.
        return false;
    }
}
