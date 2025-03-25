package PROGRAMAS_EM_JAVA.EstruturaDeDados.Pilha.test;

import PROGRAMAS_EM_JAVA.EstruturaDeDados.Pilha.domain.Pilha2;

public class PilhaTest01 {
    public static void main(String[] args) {
        Pilha2<Integer> p1 = new Pilha2<Integer>();

        p1.queue(1);
        p1.queue(2);
        p1.queue(3);
        System.out.println(p1.mostar());
        System.out.println("============");
        p1.dequeue();
        System.out.println(p1.mostar());
    }
}
