package PROGRAMAS_EM_JAVA.Analise_De_Algortimos.Domain;

public class SelectionSort {

    public void selectionSort(int[] arr) {
        int len = arr.length;

        for (int i = 0; i< len; i++) {
            int min_index = i;
            for (int j = i +1; j < len; j++) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }

            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index]= temp;
        }
    }
}
