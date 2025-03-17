package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio04.test;

public class Soma {
    public static void main(String[] args) {
        long soma = 0L;
        long pares =  0L;
        long impares = 0L;
        for(int i = 5; i<10_000; i++) {
            if(i%2 == 0) {
                pares += i;
            }else {
                impares += i;
            }
        }
        soma = pares + impares;
        System.out.println("Soma dos pares: " + pares);
        System.out.println("Soma dos ímpares: " + impares);
        System.out.println("Soma: " + soma);
    }
}
