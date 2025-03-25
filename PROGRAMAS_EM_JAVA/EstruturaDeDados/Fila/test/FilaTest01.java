package PROGRAMAS_EM_JAVA.EstruturaDeDados.Fila.test;

import PROGRAMAS_EM_JAVA.EstruturaDeDados.Fila.domain.FilaEstatica;

public class FilaTest01 {
    public static void main(String[] args) {
        FilaEstatica<Integer> f1 = new FilaEstatica<Integer>(5);
        f1.enfileira(1);
        f1.enfileira(2);
        f1.enfileira(3);
        f1.enfileira(4);
        System.out.println(f1.toString());
        System.out.println("=================");
        System.out.println(f1.desenfileirar());
        System.out.println(f1.toString());
        System.out.println(f1.espiar());
    }
}
