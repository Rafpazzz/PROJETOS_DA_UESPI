package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio04;

import java.util.Scanner;

class calculaConsumo {
    public static void main(String[] args) {
        Scanner myReader = new Scanner(System.in);
        final float precoAgua = (float) 3.4;

        System.out.print("Informe seu nome: ");
        String nome  = myReader.nextLine();
        System.out.println();
        System.out.print("Informe seu consumo de agua: ");
        float consumo = myReader.nextFloat();
        System.out.println("O consumidor " + nome + " tem como valor de sua conta " + valorAPagar(nome, precoAgua, consumo) + " reais");

    }

    public static float valorAPagar(String nome, float precoAgua, float consumo) {
        float valorFinal = 0;
        valorFinal = precoAgua * consumo;
        return valorFinal;
    }
}