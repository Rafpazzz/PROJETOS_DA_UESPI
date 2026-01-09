package PROGRAMAS_EM_JAVA.Projeto_Analise_Algortimos.domain;

public class SelectionSort {

    public void selectionSort(int[] arr, Resultado r) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                r.addComparacao();
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            int temp = arr[i];
            r.addAtribuicao();

            arr[i] = arr[minIndex];
            r.addAtribuicao();

            arr[minIndex] = temp;
            r.addAtribuicao();
        }
    }
}
