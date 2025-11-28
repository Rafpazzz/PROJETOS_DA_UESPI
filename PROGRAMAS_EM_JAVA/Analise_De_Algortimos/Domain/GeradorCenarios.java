package PROGRAMAS_EM_JAVA.Analise_De_Algortimos.Domain;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class GeradorCenarios {

    public int[] gerarCenario(int tamanho, String tipo) {
        List<Integer> lista = new ArrayList<>();
        for (int i = 1; i <= tamanho; i++) {
            lista.add(i);
        }

        switch (tipo) {
            case "ORDENADO":
                break;

            case "INVERSO":
                Collections.reverse(lista);
                break;

            case "ALEATORIO":
                Collections.shuffle(lista);
                break;

            case "QUASE_ORDENADO":
                int trocas = Math.max(1, tamanho / 20);
                for (int i = 0; i < trocas; i++) {
                    int idx1 = (int)(Math.random() * tamanho);
                    int idx2 = (int)(Math.random() * tamanho);
                    Collections.swap(lista, idx1, idx2);
                }
                break;

        }

        int[] vetor = new int[tamanho];
        for (int i = 0; i < tamanho; i++) {
            vetor[i] = lista.get(i);
        }
        return vetor;
    }
}
