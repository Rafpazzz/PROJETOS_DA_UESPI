package PROGRAMAS_EM_JAVA.Analise_De_Algortimos.Domain;

public class BubbleSort {
    //Ordena os dados do menor valor ate o maior valor

    public void bubble(int[] arr) {
        int len = arr.length;

        for(int i = 0; i< len -1; i++) {
            for(int j = 0; j < len-i-1; j++) {
                if(arr[j] > arr[i]) {
                    int temp = arr[i];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }

    }

}
