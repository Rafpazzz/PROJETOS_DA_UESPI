package PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.ListAdj;

import java.util.LinkedList;

public class ListAdjNaoDirecionada {
    private LinkedList<Integer>[] listAdj;
    private int numVertices;

    public ListAdjNaoDirecionada(int vertice) {
        this.numVertices = vertice;
        listAdj = new LinkedList[vertice];

        for(int i = 0; i<vertice; i++) {
            listAdj[i] = new LinkedList<>();
        }
    }

    public void inserirValor(int [][] matrix) {
        for(int i = 0; i<numVertices; i++) {
            for(int j = i+1; j<numVertices; j++) {
                if(matrix[i][j] == 1) {
                    listAdj[i].add(j);
                    listAdj[j].add(i);
                }
            }
        }

    }

    public void exibirLista() {
        System.out.println("Exibindo grafo");
        for(int i = 0; i<numVertices; i++) {
            System.out.print("Vertice ["+ i+ "]: ");
            for(Integer vizinho : listAdj[i]){
                System.out.print(vizinho+". ");
            }
            System.out.println();
        }
    }
}
