package PROGRAMAS_EM_JAVA.EstruturaDeDados.Pilha.test;

import PROGRAMAS_EM_JAVA.EstruturaDeDados.Pilha.domain.Pilha;

public class CadastroConsulta {
    public static void main(String[] args) {
        Pilha<Integer> p1 = new Pilha<>();

        p1.queue(1);
        p1.queue(2);
        p1.queue(3);
        p1.queue(4);
        System.out.println(p1.toString());
        System.out.println("====================");
        p1.dequeue();
        System.out.println(p1.toString());
    }
}
