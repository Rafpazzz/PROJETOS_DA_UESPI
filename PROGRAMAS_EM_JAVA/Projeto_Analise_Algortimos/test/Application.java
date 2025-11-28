package PROGRAMAS_EM_JAVA.Projeto_Analise_Algortimos.test;

import PROGRAMAS_EM_JAVA.Projeto_Analise_Algortimos.domain.*;
import PROGRAMAS_EM_JAVA.Projeto_Analise_Algortimos.utils.*;

public class Application {

    public static void main(String[] args) {

        int[] tamanhos = {10, 100, 1000, 10000,100000};
        Cenario[] cenarios = Cenario.values();

        RegistroCSV csv = new RegistroCSV();
        csv.iniciarArquivo("resultados.csv");

        BubbleSort bubble = new BubbleSort();
        InsertionSort insertion = new InsertionSort();
        SelectionSort selection = new SelectionSort();
        QuickSort quick = new QuickSort();
        MergeSort merge = new MergeSort();
        HeapSort heap = new HeapSort();

        for (Cenario cenario : cenarios) {
            System.out.println("\nCenario: " + cenario);

            for (int tamanho : tamanhos) {
                int[] vetorOriginal = switch (cenario) {
                    case ORDENADO -> VetorUtils.gerarVetorOrdenado(tamanho);
                    case INVERSO -> VetorUtils.gerarVetorInverso(tamanho);
                    case ALEATORIO -> VetorUtils.gerarVetorAleatorio(tamanho);
                    case QUASE_ORDENADO -> VetorUtils.gerarVetorQuaseOrdenado(tamanho);
                };

                System.out.println("\nQtd Dados: " + tamanho);
                System.out.printf("%-12s | %-12s | %-12s%n", "Algoritmo", "Tempo(ns)", "Tempo(ms)");
                System.out.println("------------------------------------------");

                // BubbleSort
                int[] vetor = VetorUtils.copiarVetor(vetorOriginal);
                Resultado r = new Resultado();
                long inicio = System.nanoTime();
                bubble.bubbleSort(vetor, r);
                long fim = System.nanoTime();
                imprimirResultado("BubbleSort", r, inicio, fim, csv, tamanho, cenario);

                // InsertionSort
                vetor = VetorUtils.copiarVetor(vetorOriginal);
                r = new Resultado();
                inicio = System.nanoTime();
                insertion.insertionSort(vetor, r);
                fim = System.nanoTime();
                imprimirResultado("InsertionSort", r, inicio, fim, csv, tamanho, cenario);

                // SelectionSort
                vetor = VetorUtils.copiarVetor(vetorOriginal);
                r = new Resultado();
                inicio = System.nanoTime();
                selection.selectionSort(vetor, r);
                fim = System.nanoTime();
                imprimirResultado("SelectionSort", r, inicio, fim, csv, tamanho, cenario);

                // QuickSort
                vetor = VetorUtils.copiarVetor(vetorOriginal);
                r = new Resultado();
                inicio = System.nanoTime();
                quick.quickSort(vetor, 0, vetor.length - 1, r);
                fim = System.nanoTime();
                imprimirResultado("QuickSort", r, inicio, fim, csv, tamanho, cenario);

                // MergeSort
                vetor = VetorUtils.copiarVetor(vetorOriginal);
                r = new Resultado();
                inicio = System.nanoTime();
                merge.mergeSort(vetor, 0, vetor.length - 1, r);
                fim = System.nanoTime();
                imprimirResultado("MergeSort", r, inicio, fim, csv, tamanho, cenario);

                // HeapSort
                vetor = VetorUtils.copiarVetor(vetorOriginal);
                r = new Resultado();
                inicio = System.nanoTime();
                heap.heapSort(vetor, r);
                fim = System.nanoTime();
                imprimirResultado("HeapSort", r, inicio, fim, csv, tamanho, cenario);
            }
        }

        csv.fechar();
    }

    private static void imprimirResultado(String nome, Resultado r, long inicio, long fim, RegistroCSV csv,
                                          int tamanho, Cenario cenario) {
        long tempoNano = fim - inicio;
        double tempoMs = TempoUtils.nanoParaMs(tempoNano);

        System.out.printf("%-12s | %-12d | %-12.4f%n", nome, tempoNano, tempoMs);
        csv.registrarResultado(nome, tamanho, cenario, tempoNano, tempoMs, r);
    }
}
