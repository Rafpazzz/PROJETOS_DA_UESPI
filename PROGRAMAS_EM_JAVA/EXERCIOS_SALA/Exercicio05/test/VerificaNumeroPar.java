package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio05.test;

import java.sql.SQLOutput;

public class VerificaNumeroPar {
    public static void main(String[] args) {
        int numero = 5;
        if(numeroPar(numero) == false) {
            System.out.println("O numero " + numero + " não é par");
        }else System.out.println("O numero " + numero + " é par");

    }

    public static boolean numeroPar(int numero){
        boolean par = true;
        if(numero%2 == 0) {
            return par;
        }return false;
    }
}
