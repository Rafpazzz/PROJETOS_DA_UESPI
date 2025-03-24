package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio05.test;

public class SemRetorno {

    public static void soma(int n){
        int a = 2;
        a = a + n;
        System.out.println("valor da soma: " + a);
    }

    public static void main(String[] args) {
        int i = 7;
        soma(i);
    }
}
