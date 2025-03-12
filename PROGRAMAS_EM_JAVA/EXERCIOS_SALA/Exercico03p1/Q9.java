package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercico03p1;

public class Q9 {
    public static void main(String args[]) {
        int gastosJaneiro = 15_000;
        int gastosFevereiro = 23_000;
        int gastosMarco = 17_000;
        int gastosTrimestre = gastosJaneiro + gastosFevereiro + gastosMarco;
        Double mediaSalarisal = (double)gastosTrimestre/3;

        System.out.println("Os gstos do trimestre forão: " + gastosTrimestre);
        System.out.println("Valor da média mensal = "+ mediaSalarisal);
    }
}