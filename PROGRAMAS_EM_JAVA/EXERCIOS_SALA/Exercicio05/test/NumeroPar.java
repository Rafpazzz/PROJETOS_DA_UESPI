package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio05.test;

public class NumeroPar {

    public int Multiplicacao(int n1) {
        return n1*2;
    }

    public static void main(String[] args) {
        NumeroPar n = new NumeroPar();
        System.out.println(n.Multiplicacao(65));
    }
}
