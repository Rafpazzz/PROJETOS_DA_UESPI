package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercico03p2;

public class UandoEstoque {
    public static void main(String[] args) {
        Q1 estoque1 = new Q1("Impressora Jato de Tinta", 13, 6);
        Q1 estoque2 = new Q1("Monitor LCD 17 polegadas", 11, 13);
        Q1 estoque3 = new Q1("Mouse Ótico", 6, 2);

        estoque1.darbaixa(5);
        estoque2.Repor(7);
        estoque3.darbaixa(4);
        System.out.println("============================");

        System.out.println(estoque1.precisarepor());
        System.out.println(estoque2.precisarepor());
        System.out.println(estoque3.precisarepor());

        System.out.println("=======================");

        estoque1.lista();
        estoque2.lista();
        estoque3.lista();

    }
}
