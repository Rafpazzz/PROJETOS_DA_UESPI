package PROGRAMAS_EM_JAVA.Projeto_Analise_Algortimos.test;

import PROGRAMAS_EM_JAVA.Projeto_Analise_Algortimos.domain.*;
import PROGRAMAS_EM_JAVA.Projeto_Analise_Algortimos.utils.*;

import java.util.Arrays;

public class Application {

    public static void main(String[] args) {

        // Definição dos tamanhos e cenários
        int[] tamanhos = {10, 100, 1000, 10000, 100000};
        Cenario[] cenarios = Cenario.values();

        RegistroCSV csv = new RegistroCSV();
        csv.iniciarArquivo("resultados.csv");

        // Instanciação dos Algoritmos
        BubbleSort bubble = new BubbleSort();
        InsertionSort insertion = new InsertionSort();
        SelectionSort selection = new SelectionSort();
        QuickSort quick = new QuickSort();
        MergeSort merge = new MergeSort();
        HeapSort heap = new HeapSort();

        for (Cenario cenario : cenarios) {
            System.out.println("\n==================================================");
            System.out.println("CENÁRIO: " + cenario);
            System.out.println("==================================================");

            for (int tamanho : tamanhos) {
                // 1. Gera o vetor original de acordo com o cenário
                int[] vetorOriginal = switch (cenario) {
                    case ORDENADO -> VetorUtils.gerarVetorOrdenado(tamanho);
                    case INVERSO -> VetorUtils.gerarVetorInverso(tamanho);
                    case ALEATORIO -> VetorUtils.gerarVetorAleatorio(tamanho);
                    case QUASE_ORDENADO -> VetorUtils.gerarVetorQuaseOrdenado(tamanho);
                };

                System.out.println("\n>>> Teste com tamanho: " + tamanho);

                // EXIBIÇÃO: MOSTRAR ANTES DA ORDENAÇÃO
                imprimirVetor(vetorOriginal, "Vetor Original (Pré-ordenação)");

                System.out.printf("%-15s | %-15s | %-15s%n", "Algoritmo", "Tempo(ns)", "Tempo(ms)");
                System.out.println("-------------------------------------------------------");

                // --- BUBBLE SORT ---
                int[] vetor = VetorUtils.copiarVetor(vetorOriginal);
                Resultado r = new Resultado();
                long inicio = System.nanoTime();
                bubble.bubbleSort(vetor, r);
                long fim = System.nanoTime();
                imprimirResultado("BubbleSort", r, inicio, fim, csv, tamanho, cenario);
                // Exibição Pós-Ordenação (apenas se for pequeno para não poluir, ou chame imprimirVetor se quiser sempre)
                if (tamanho <= 20) imprimirVetor(vetor, "   -> Resultado BubbleSort");

                // --- INSERTION SORT ---
                vetor = VetorUtils.copiarVetor(vetorOriginal);
                r = new Resultado();
                inicio = System.nanoTime();
                insertion.insertionSort(vetor, r);
                fim = System.nanoTime();
                imprimirResultado("InsertionSort", r, inicio, fim, csv, tamanho, cenario);
                if (tamanho <= 20) imprimirVetor(vetor, "   -> Resultado Insertion");

                // --- SELECTION SORT ---
                vetor = VetorUtils.copiarVetor(vetorOriginal);
                r = new Resultado();
                inicio = System.nanoTime();
                selection.selectionSort(vetor, r);
                fim = System.nanoTime();
                imprimirResultado("SelectionSort", r, inicio, fim, csv, tamanho, cenario);
                if (tamanho <= 20) imprimirVetor(vetor, "   -> Resultado Selection");

                // --- QUICK SORT ---
                vetor = VetorUtils.copiarVetor(vetorOriginal);
                r = new Resultado();
                inicio = System.nanoTime();
                quick.quickSort(vetor, 0, vetor.length - 1, r);
                fim = System.nanoTime();
                imprimirResultado("QuickSort", r, inicio, fim, csv, tamanho, cenario);
                if (tamanho <= 20) imprimirVetor(vetor, "   -> Resultado Quick");

                // --- MERGE SORT ---
                vetor = VetorUtils.copiarVetor(vetorOriginal);
                r = new Resultado();
                inicio = System.nanoTime();
                merge.mergeSort(vetor, 0, vetor.length - 1, r);
                fim = System.nanoTime();
                imprimirResultado("MergeSort", r, inicio, fim, csv, tamanho, cenario);
                if (tamanho <= 20) imprimirVetor(vetor, "   -> Resultado Merge");

                // --- HEAP SORT ---
                vetor = VetorUtils.copiarVetor(vetorOriginal);
                r = new Resultado();
                inicio = System.nanoTime();
                heap.heapSort(vetor, r);
                fim = System.nanoTime();
                imprimirResultado("HeapSort", r, inicio, fim, csv, tamanho, cenario);
                if (tamanho <= 20) imprimirVetor(vetor, "   -> Resultado Heap");
            }
        }

        csv.fechar();
        System.out.println("\nProcessamento concluído. Dados salvos em 'resultados.csv'.");
    }

    // --- MÉTODOS AUXILIARES ---

    private static void imprimirResultado(String nome, Resultado r, long inicio, long fim, RegistroCSV csv,
                                          int tamanho, Cenario cenario) {
        long tempoNano = fim - inicio;
        double tempoMs = TempoUtils.nanoParaMs(tempoNano);

        System.out.printf("%-15s | %-15d | %-15.4f%n", nome, tempoNano, tempoMs);
        csv.registrarResultado(nome, tamanho, cenario, tempoNano, tempoMs, r);
    }

    /**
     * Método auxiliar para imprimir o vetor.
     */
    private static void imprimirVetor(int[] vetor, String titulo) {
        System.out.print(titulo + ": ");

        if (vetor.length <= 20) {
            // Se for pequeno, imprime tudo
            System.out.println(Arrays.toString(vetor));
        } else {
            // Se for grande, imprime resumo: [1, 2, 3 ... 99, 100]
            System.out.print("[");
            for (int i = 0; i < 5; i++) {
                System.out.print(vetor[i] + ", ");
            }
            System.out.print("... (" + (vetor.length - 10) + " itens ocultos) ... ");
            for (int i = vetor.length - 5; i < vetor.length; i++) {
                System.out.print(vetor[i] + (i == vetor.length - 1 ? "" : ", "));
            }
            System.out.println("]");
        }
    }
}