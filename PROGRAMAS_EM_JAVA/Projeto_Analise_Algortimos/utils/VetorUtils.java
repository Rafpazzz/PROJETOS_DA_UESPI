package PROGRAMAS_EM_JAVA.Projeto_Analise_Algortimos.utils;

import java.util.Random;

public class VetorUtils {

    // Gera vetor único aleatório de tamanho n
    public static int[] gerarVetorAleatorio(int n) {
        int[] vetor = new int[n];
        for (int i = 0; i < n; i++) {
            vetor[i] = i; // valores únicos
        }
        embaralhar(vetor);
        return vetor;
    }

    // Gera vetor ordenado
    public static int[] gerarVetorOrdenado(int n) {
        int[] vetor = new int[n];
        for (int i = 0; i < n; i++) vetor[i] = i;
        return vetor;
    }

    // Gera vetor inversamente ordenado
    public static int[] gerarVetorInverso(int n) {
        int[] vetor = new int[n];
        for (int i = 0; i < n; i++) vetor[i] = n - i - 1;
        return vetor;
    }

    // Gera vetor quase ordenado (90% ordenado, 10% embaralhado)
    public static int[] gerarVetorQuaseOrdenado(int n) {
        int[] vetor = gerarVetorOrdenado(n);
        Random rand = new Random();
        int numTrocas = n / 10;
        for (int i = 0; i < numTrocas; i++) {
            int a = rand.nextInt(n);
            int b = rand.nextInt(n);
            int temp = vetor[a];
            vetor[a] = vetor[b];
            vetor[b] = temp;
        }
        return vetor;
    }

    // Copia vetor para não alterar o original
    public static int[] copiarVetor(int[] vetor) {
        int[] copia = new int[vetor.length];
        System.arraycopy(vetor, 0, copia, 0, vetor.length);
        return copia;
    }


    // Método Fisher-Yates para embaralhar
    private static void embaralhar(int[] vetor) {
        Random rand = new Random();
        for (int i = vetor.length - 1; i > 0; i--) {
            int j = rand.nextInt(i + 1);
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
}
