package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercico03p2;

import java.util.Scanner;

public class QuantificandoNotas {
    public static void ResultadoNota() {
        int nota;
        Scanner myReader = new Scanner(System.in);
        do{
            System.out.println("Selecione uma nota: ");
            nota = myReader.nextInt();
            switch (nota) {
                case 1: 
                    System.out.println("Mal");
                    break;
                case 2:
                    System.out.println("Mediocre");
                    break;
                case 3:
                    System.out.println("Suficiente");
                    break;
                case 4:
                    System.out.println("Bom");
                    break;
                case 5:
                    System.out.println("Excelente");
                    break;
                default:
                    System.out.println("Nota invalida. Tente novamente");
            }
        }while(nota>5);
    }

    public static void main(String[] args) {
        ResultadoNota();
    }
}
