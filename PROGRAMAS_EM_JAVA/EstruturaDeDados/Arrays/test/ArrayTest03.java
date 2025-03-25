package PROGRAMAS_EM_JAVA.EstruturaDeDados.Arrays.test;


import PROGRAMAS_EM_JAVA.EstruturaDeDados.Arrays.domain.Lista;

public class ArrayTest03 {
    public static void main(String[] args) {
        Lista<Integer> l1 = new Lista<Integer>();

        l1.inserirElemento(1);
        l1.inserirElemento(2);
        l1.inserirElemento(3);
        System.out.println(l1.toString());
        System.out.println("=================");
        l1.liberaLista1();
        System.out.println(l1.toString());
    }
}
