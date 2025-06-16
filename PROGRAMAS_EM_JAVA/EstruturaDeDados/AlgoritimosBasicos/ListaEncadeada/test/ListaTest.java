package PROGRAMAS_EM_JAVA.EstruturaDeDados.AlgoritimosBasicos.ListaEncadeada.test;

import PROGRAMAS_EM_JAVA.EstruturaDeDados.AlgoritimosBasicos.ListaEncadeada.domain.Lista01;

public class ListaTest {
    public static void main(String[] args) {
        Lista01<Integer> l1 = new Lista01<>();
        l1.add(1);
        l1.add(2);
        l1.add(3);
        l1.add(4);

        l1.limpa();
        System.out.println(l1.toString());

    }
}
