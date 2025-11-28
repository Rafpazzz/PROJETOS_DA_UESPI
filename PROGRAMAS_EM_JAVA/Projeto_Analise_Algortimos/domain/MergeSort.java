package PROGRAMAS_EM_JAVA.Projeto_Analise_Algortimos.domain;

public class MergeSort {

    public void mergeSort(int[] arr, int inicio, int fim, Resultado r) {
        if (inicio < fim) {
            int meio = (inicio + fim) / 2;

            mergeSort(arr, inicio, meio, r);
            mergeSort(arr, meio + 1, fim, r);

            merge(arr, inicio, meio, fim, r);
        }
    }

    private void merge(int[] arr, int inicio, int meio, int fim, Resultado r) {

        int n1 = meio - inicio + 1;
        int n2 = fim - meio;

        int[] L = new int[n1];
        int[] R = new int[n2];

        // copia
        for (int i = 0; i < n1; i++) {
            L[i] = arr[inicio + i];
            r.addAtribuicao();
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[meio + 1 + j];
            r.addAtribuicao();
        }

        int i = 0, j = 0, k = inicio;

        while (i < n1 && j < n2) {

            r.addComparacao(); // L[i] <= R[j]

            if (L[i] <= R[j]) {
                arr[k] = L[i];
                r.addAtribuicao();
                i++;
            } else {
                arr[k] = R[j];
                r.addAtribuicao();
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            r.addAtribuicao();
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            r.addAtribuicao();
            j++;
            k++;
        }
    }
}
