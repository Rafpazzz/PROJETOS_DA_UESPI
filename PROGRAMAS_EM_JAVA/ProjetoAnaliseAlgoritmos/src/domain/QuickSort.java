package domain;

import java.util.Random;

public class QuickSort {

    private Random rand = new Random();

    public void quickSort(int[] arr, int inicio, int fim, Resultado r) {
        if (inicio < fim) {
            int p = particiona(arr, inicio, fim, r);
            quickSort(arr, inicio, p - 1, r);
            quickSort(arr, p + 1, fim, r);
        }
    }

    private int particiona(int[] arr, int inicio, int fim, Resultado r) {
        // Escolher pivot aleatório
        int pivotIndex = inicio + rand.nextInt(fim - inicio + 1);
        swap(arr, pivotIndex, fim, r);

        int pivo = arr[fim];
        r.addAtribuicao();

        int i = inicio - 1;

        for (int j = inicio; j < fim; j++) {
            r.addComparacao(); // arr[j] <= pivo
            if (arr[j] <= pivo) {
                i++;
                swap(arr, i, j, r);
            }
        }

        swap(arr, i + 1, fim, r);
        return i + 1;
    }

    private void swap(int[] arr, int i, int j, Resultado r) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        r.addAtribuicao();
        r.addAtribuicao();
        r.addAtribuicao();
    }
}
