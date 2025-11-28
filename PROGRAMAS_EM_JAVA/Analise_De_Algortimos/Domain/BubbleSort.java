package domain;

public class BubbleSort {

    public void bubbleSort(int[] arr, Resultado r) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {

                r.addComparacao(); // comparação arr[j] > arr[j+1]

                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    r.addAtribuicao();

                    arr[j] = arr[j + 1];
                    r.addAtribuicao();

                    arr[j + 1] = temp;
                    r.addAtribuicao();
                }
            }
        }
    }
}
