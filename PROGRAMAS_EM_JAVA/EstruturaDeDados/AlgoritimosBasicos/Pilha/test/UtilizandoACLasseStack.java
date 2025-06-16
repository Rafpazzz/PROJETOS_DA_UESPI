package PROGRAMAS_EM_JAVA.EstruturaDeDados.AlgoritimosBasicos.Pilha.test;

import java.util.Stack;

public class UtilizandoACLasseStack {
    public static void main(String[] args) {
        Stack<Integer> pilha = new Stack<Integer>();

        pilha.add(1);
        pilha.add(2);
        pilha.add(3);
        pilha.add(4);
        System.out.println(pilha);
        System.out.println("===============");
        System.out.println(pilha.capacity());
        pilha.pop();
        System.out.println(pilha.peek());
    }
}
