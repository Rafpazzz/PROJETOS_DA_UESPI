package PROGRAMAS_EM_JAVA.EstruturaDeDados.Arrays.test;

import PROGRAMAS_EM_JAVA.EstruturaDeDados.Arrays.domain.VetorJava;
import PROGRAMAS_EM_JAVA.EstruturaDeDados.Arrays.domain.Contato;

public class ArrayTest02 {
    public static void main(String[] args) throws Exception {
        VetorJava a = new VetorJava();
        Contato c1 = new Contato("contato 1", 1234_5678, "contato1@email.com");
        Contato c2 = new Contato("contato 2", 5432_8765, "contato2@email.com");
        Contato c3 = new Contato("contato 3", 3456_0987, "contato3@email.com");
        Contato c4 = new Contato("contato 4", 3216_6587, "contato4@email.com");

        a.inserirElemento(c1);
        a.inserirElemento(c2);
        a.inserirElemento(c3);

        System.out.println(a.toString());

        System.out.println(a.existeElemento(c4));

    }
}
