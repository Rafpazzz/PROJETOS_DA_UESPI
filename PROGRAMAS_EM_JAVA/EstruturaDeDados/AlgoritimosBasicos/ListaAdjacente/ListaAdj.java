package PROGRAMAS_EM_JAVA.EstruturaDeDados.AlgoritimosBasicos.ListaAdjacente;

import java.util.*;

public class ListaAdj {
    public static void main(String[] args) {
        ListaAdjacente list = new ListaAdjacente(5);

        list.inserirValor(3, 2);
        list.inserirValor(1, 4);
        list.inserirValor(1, 3);
        list.exibirLista();
        System.out.println(list.possueVizinhos(1));
        System.out.println(list.retornaGrau(1));
        list.liberaGrafo();
        System.out.println("====================");
        list.exibirLista();

    }

}

class ListaAdjacente {
    private LinkedList<Integer>[] listAdj;
    private int numVertices;
    private int numArestas;

    public ListaAdjacente(int vertice) {
        this.numVertices = vertice;
        this.numArestas = 0;
        listAdj = new LinkedList[vertice];

        for(int i = 0; i<vertice; i++) {
            listAdj[i] = new LinkedList<>();
        }
    }

    public void inserirValor(int v1, int v2) {
        listAdj[v1].add(v2);
        listAdj[v2].add(v1); //comentar esta linha se o grafo for direcional.
        numArestas++;

    }

    public void removerValor(int v1, int v2) {
        if(existeAresta(v1, v2)){
            listAdj[v1].remove((Integer) v2);
            listAdj[v2].remove((Integer) v1);
            numArestas--;
        }else {
            System.out.println("Esses valores nao possuem ligação");
        }
        
    }

    public int quantidadeArestas() {
        return numArestas;
    }

    public Boolean existeAresta(int v1, int v2) {
        return listAdj[v1].contains(v2);
    }

    public void exibirLista() {
        System.out.println("Exibindo grafo(vertices: "+ numVertices +"; arestas: "+ numArestas+ ")");
        for(int i = 0; i<numVertices; i++) {
            System.out.print("Vertice ["+ i+ "]: ");
            for(Integer vizinho : listAdj[i]){
                System.out.print(vizinho+". ");
            }
            System.out.println();
        }
    }

    public Boolean possueVizinhos(int v) {
        if(v>=0 && v<numVertices && !listAdj[v].isEmpty()) {
            return true;
        }else{
            return false;
        }
        
    }

    public int retornaGrau(int v) {
        if(v<0 || v>=numVertices) {
            return 1;
        }
        return listAdj[v].size();
    }

    public Boolean liberaGrafo() {
        if(listAdj == null) return false;

        for(int i = 0; i<numVertices; i++){
            listAdj[i].clear();
        }

        listAdj = null;

        numArestas = 0;
        numVertices = 0;
        return true;
            
    }
}