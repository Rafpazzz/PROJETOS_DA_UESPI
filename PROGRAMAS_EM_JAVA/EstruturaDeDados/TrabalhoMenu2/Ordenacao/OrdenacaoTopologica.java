package PROGRAMAS_EM_JAVA.EstruturaDeDados.TrabalhoMenu2.Ordenacao;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class OrdenacaoTopologica {
    //busca em profundidade recursiva para verificar os visinhos do vertice.
    public void dfs(int v, int [][] matix, boolean [] visitado, Stack<Integer> pilha ) {
        visitado[v] = true;
        for(int i =0; i <matix.length; i++) {
            if(matix[v][i] == 1 && !visitado[i]) {
                dfs(i,matix,visitado,pilha);
            }
        }

        pilha.push(v); //adicionar o vertice após visitar os vizinhos;

    }

    public List<Integer> ordemTop(int[][] matix, int size) {
        boolean[] visitado = new  boolean[size];
        Stack<Integer> pilha = new Stack<>();

        //executa o dfs com todos dos vertices nao visitados
        for(int i = 0; i < size; i++) {
            if(!visitado[i]) {
                dfs(i, matix, visitado, pilha);
            }
        }

        List<Integer> resultado = new ArrayList<>();

        while (!pilha.isEmpty()) {
            resultado.add(pilha.pop());
        }

        return resultado;
    }


}
