package PROGRAMAS_EM_JAVA.Analise_De_Algortimos.Test;

import PROGRAMAS_EM_JAVA.Analise_De_Algortimos.Domain.BubbleSort;
import PROGRAMAS_EM_JAVA.Analise_De_Algortimos.Domain.GeradorCenarios;
import PROGRAMAS_EM_JAVA.Analise_De_Algortimos.Domain.InsertionSort;
import PROGRAMAS_EM_JAVA.Analise_De_Algortimos.Domain.SelectionSort;

import java.util.Random;

public class aplication {
    public static void main(String[] args) {
        int[] tamanhos = {10, 100, 1_000, 10_000, 100_000};
        String[] tipos = {"ORDENADO", "INVERSO", "ALEATORIO", "QUASE_ORDENADO"};
        BubbleSort bs = new BubbleSort();
        InsertionSort is = new InsertionSort();
        SelectionSort ss = new SelectionSort();
        GeradorCenarios gc = new GeradorCenarios();

        System.out.printf("%-10s | %-20s | %-10s%n", "Qtd Dados", "Tempo (ns)", "Tempo (ms)");
        System.out.println("------------------------------------------------");


        for (String tipo : tipos) {
            System.out.println("Cenario: " + tipo);

            for(int tamanho : tamanhos) {
                int[] vetor = gc.gerarCenario(tamanho, tipo);

                long inicio = System.nanoTime();

//                bs.bubble(vetor);
//                is.insertionSort(vetor);
                ss.selectionSort(vetor);

                long fim = System.nanoTime();

                long duracaoNano = fim - inicio;
                double duracaoMs = duracaoNano / 1_000_000.0;

                System.out.printf("%-10d | %-20d | %-10.4f%n", tamanho, duracaoNano, duracaoMs);
            }
        }
    }
}
