package PROGRAMAS_EM_JAVA.EstruturaDeDados.AlgoritimosBasicos.Pilha.test;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class PilhaComPrioridade {
    public static void main(String[] args) {
        Queue<Integer> p1 = new PriorityQueue<Integer>(
                new Comparator<Integer>() {
                    @Override
                    public int compare(Integer p1, Integer p2) {
                        return p1.compareTo(p2);
                    }
                }
        );

        p1.add(2);
        p1.add(1);
        p1.add(3);
        p1.add(5);
        p1.add(4);
        p1.remove();
        p1.remove();

        System.out.println(p1);
    }
}
