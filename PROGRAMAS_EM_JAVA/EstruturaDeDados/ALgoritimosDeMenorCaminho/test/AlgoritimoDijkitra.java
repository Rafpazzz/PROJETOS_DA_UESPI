package PROGRAMAS_EM_JAVA.EstruturaDeDados.ALgoritimosDeMenorCaminho.test;

import PROGRAMAS_EM_JAVA.EstruturaDeDados.ALgoritimosDeMenorCaminho.domain.GraphDijkitra;

public class AlgoritimoDijkitra {
    public static void main(String[] args) {
        GraphDijkitra g1 = new GraphDijkitra(7);

        g1.addVertice(0, "A");
        g1.addVertice(1, "B");
        g1.addVertice(2, "C");
        g1.addVertice(3, "D");
        g1.addVertice(4, "E");
        g1.addVertice(5, "F");
        g1.addVertice(6, "G");

        g1.addElemento(3,0, 4);
        g1.addElemento(3,4, 2);
        g1.addElemento(0,2, 3);
        g1.addElemento(0,4, 4);
        g1.addElemento(4,2, 4);
        g1.addElemento(4,6, 5);
        g1.addElemento(2,5, 5);
        g1.addElemento(2,1, 2);
        g1.addElemento(1,5, 2);
        g1.addElemento(6,5, 5);

        int[] dsitances = g1.dijkitra("D");
        for(int i = 0; i<dsitances.length; i++) {
            System.out.println("A distancia de D para " + g1.getVerticeDado(i) + " : " + dsitances[i]);
        }
    }
}
