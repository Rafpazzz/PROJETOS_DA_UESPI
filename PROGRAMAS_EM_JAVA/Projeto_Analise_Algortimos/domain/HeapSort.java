package PROGRAMAS_EM_JAVA.Projeto_Analise_Algortimos.domain;

public class HeapSort {

    public void heapSort(int[] arr, Resultado r) {
        int n = arr.length;

        // construir heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i, r);
        }

        // extrair elementos
        for (int i = n - 1; i > 0; i--) {

            int temp = arr[0];
            r.addAtribuicao();

            arr[0] = arr[i];
            r.addAtribuicao();

            arr[i] = temp;
            r.addAtribuicao();

            heapify(arr, i, 0, r);
        }
    }

    private void heapify(int[] arr, int n, int i, Resultado r) {
        int maior = i;
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;

        // compara esquerda
        if (esq < n) {
            r.addComparacao();
            if (arr[esq] > arr[maior]) {
                maior = esq;
            }
        }

        // compara direita
        if (dir < n) {
            r.addComparacao();
            if (arr[dir] > arr[maior]) {
                maior = dir;
            }
        }

        // troca se necessário
        if (maior != i) {
            int temp = arr[i];
            r.addAtribuicao();

            arr[i] = arr[maior];
            r.addAtribuicao();

            arr[maior] = temp;
            r.addAtribuicao();

            heapify(arr, n, maior, r);
        }
    }
}
