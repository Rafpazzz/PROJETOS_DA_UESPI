package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio05.test;

import java.util.Scanner;

public class ImprecaoMeuNome {
    public static void main(String[] args) {
        Scanner myReader = new Scanner(System.in);

        System.out.print("Informe seu nome: ");
        String nome = myReader.nextLine();

        for(int i = 1; i<11; i++) {
            System.out.println(i + ". "+nome);
        }
    }
}
