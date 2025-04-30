package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio08_1;

public class TestPonto {
    public static void main(String[] args) {
        Ponto p1 = new Ponto(1,2);
        Ponto p2 = new Ponto();

        p1.desloca(2,3);
        System.out.println(p1.toString());
        System.out.println("================");
        p1.desloca("2","1");
        System.out.println(p1.toString());
        System.out.println("================");
        p2.setX(2);
        p2.setY(3);
        System.out.println(p2.toString());
        System.out.println("===================");
        p2.setX("4");
        p2.setY("5");
        System.out.println(p2.toString());
    }
}
