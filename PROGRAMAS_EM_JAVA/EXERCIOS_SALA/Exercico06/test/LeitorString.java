package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercico06.test;

import java.util.Scanner;

public class LeitorString {
    public static void main(String[] args) {
        Scanner myReader = new Scanner(System.in);

        System.out.print("Informe uma String: ");
        String palavra = myReader.nextLine();

        System.out.println("====================");
        System.out.println("Quantidade de caracteres: " + palavra.length());
        System.out.println("Ultimo caractere: " + palavra.charAt(palavra.length()-1));

        char[] invert = new char[palavra.length()];
        int temp = 0;

        for(int i = palavra.length()-1; i>=0; i--) {
            invert[temp] = palavra.charAt(i);
            temp++;
        }

        System.out.print("String invertida: ");
        System.out.println(invert);

    }
}
