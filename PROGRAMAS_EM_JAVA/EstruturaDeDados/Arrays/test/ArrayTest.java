package PROGRAMAS_EM_JAVA.EstruturaDeDados.Arrays.test;

import PROGRAMAS_EM_JAVA.EstruturaDeDados.Arrays.domain.VetorJava;

public class ArrayTest {
    public static void main(String[] args) throws Exception {
        VetorJava a = new VetorJava();

        a.inserirElemento(1);
        a.inserirElemento(2);
        a.inserirElemento(3);
        System.out.println(a.toString());
        System.out.println("=====================");
        a.adicionaDeterminadaPosicao(4,0);
        System.out.println(a.toString());
        a.removerElemento(2);
        System.out.println(a.toString());
        a.retornaElemento(0);

    }
}
