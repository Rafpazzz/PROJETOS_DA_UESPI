package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercico03p2;

public class ArraysAleatorios{
    public static void main(String[] args) {
        int[] array = {1,2,3,4,5};

        System.out.println("Maior valor: "+retornaMaior(array));
        System.out.println("Menor valor: " + retornaMenor(array));
        retornaMedia(array);
       
    }

    public static int retornaMaior(int arr[]) {
        int temp;
        int maior = arr[0];

        for(int i = 0; i<arr.length; i++) {
            temp = arr[i];
            if(maior < temp) {
                maior = temp;
            }
        }

        return maior;
    }

    public static int retornaMenor(int arr[]) {
        int temp;
        int menor = arr[0];

        for(int i = 0; i<arr.length; i++) {
            temp = arr[i];
            if(menor > temp) {
                menor = temp;
            }
        }

        return menor;
    }

    public static void retornaMedia(int arr[]) {
        int temp = 0;
        double media;
        for(int i = 0; i<arr.length; i++) {
            temp += arr[i];
        }
        
        media = temp/arr.length;

        System.out.println("A soma dos valores: " + temp);
        System.out.println("Meida dos valores: " + media);
    }
}