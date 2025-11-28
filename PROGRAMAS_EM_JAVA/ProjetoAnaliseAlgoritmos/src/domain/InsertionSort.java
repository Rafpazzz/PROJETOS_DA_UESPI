package domain;

public class InsertionSort {

    public void insertionSort(int[] arr, Resultado r) {
        int n = arr.length;

        for (int i = 1; i < n; i++) {
            int currentValue = arr[i];
            r.addAtribuicao();

            int j = i - 1;

            while (j >= 0) {
                r.addComparacao(); // comparação arr[j] > currentValue

                if (arr[j] > currentValue) {
                    arr[j + 1] = arr[j];
                    r.addAtribuicao();

                    j--;
                } else {
                    break;
                }
            }

            arr[j + 1] = currentValue;
            r.addAtribuicao();
        }
    }
}
