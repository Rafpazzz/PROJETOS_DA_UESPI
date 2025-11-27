package PROGRAMAS_EM_JAVA.Analise_De_Algortimos.Domain;

public class InsertionSort {

    public void insertionSort(int[] arr) {
        int len = arr.length;

        for(int i =1; i<len; i++) {
            int insertIndex = i;
            int currentValue = arr[i];
            int j = i - 1;

            while(j >= 0 && arr[j] > currentValue) {
                arr[j + 1] = arr[i];
                insertIndex = j;
                j--;
            }

            arr[insertIndex] = currentValue;
        }
    }
}
