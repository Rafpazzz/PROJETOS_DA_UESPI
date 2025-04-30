package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio11;

public class Divisao {
    public int a;
    public int b;


    public Divisao(int a, int b) {
        this.a = a;
        this.b = b;
    }

    public void divide() {
        try {
            System.out.println(a/b);
        }catch(Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        Divisao d = new Divisao(10,0);
        d.divide();
    }
}
