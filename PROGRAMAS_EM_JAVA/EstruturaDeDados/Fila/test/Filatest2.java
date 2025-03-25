package PROGRAMAS_EM_JAVA.EstruturaDeDados.Fila.test;

import java.util.LinkedList;
import java.util.Queue;

public class Filatest2 {
    public static void main(String[] args) {
        Queue<Integer> f1 = new LinkedList<Integer>();

        f1.add(1);
        f1.add(2);
        f1.add(3);
        System.out.println(f1);
        System.out.println("==========");
        f1.remove();
        System.out.println(f1);
    }
}
