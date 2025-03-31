package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercico06.test;

public class Array01 {
    public static void main(String[] args) {
        int[] arr = {45,2,3,4,5,6,1,7,8,9,100,10,11,12,13,14,15};

        System.out.println(numerosPares(arr));
        invertString(arr);
        System.out.println();
        maiorValor(arr);
        menorValor(arr);
    }

    public static String numerosPares(int[] a) {
        StringBuilder grupoPar = new StringBuilder();
        grupoPar.append("[");

        for(int i = 0; i<a.length; i++) {
            if(a[i] % 2 == 0) {
                grupoPar.append(a[i]);
                grupoPar.append(", ");
            }
        }
        grupoPar.append("]");

        return grupoPar.toString();
    }

    public static void invertString(int[] a) {
        int[] invert = new int[a.length];
        int temp = 0;

        for(int i = a.length-1; i>=0; i--) {
            invert[temp] = a[i];
            temp++;
        }

        for(int g = 0; g<invert.length; g++) {
            System.out.print(invert[g]+ " ");
        }
    }

    public static void maiorValor(int[] a) {
        int maiorNumero = a[0];
        int posicao = 0;

        for(int i = 0; i<a.length; i++) {
           if(a[i]>maiorNumero) {
               maiorNumero = a[i];
               posicao = i;
           }
        }

        System.out.println("Posição: "+posicao);
        System.out.println("Maior numero: "+maiorNumero);

    }

    public static void menorValor(int[] a) {
        int menorNumero = a[0];
        int posicao = 0;

        for(int i = 0; i<a.length; i++) {
            if(menorNumero>a[i]) {
                menorNumero = a[i];
                posicao = i;
            }
        }

        System.out.println("Posição: "+posicao);
        System.out.println("Maior numero: "+menorNumero);

    }

}
