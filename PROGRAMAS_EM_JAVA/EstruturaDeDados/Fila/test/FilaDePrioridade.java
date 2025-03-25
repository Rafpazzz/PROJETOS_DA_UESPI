package PROGRAMAS_EM_JAVA.EstruturaDeDados.Fila.test;

import PROGRAMAS_EM_JAVA.EstruturaDeDados.Fila.domain.FilaComPrioridade;

public class FilaDePrioridade {
    public static void main(String[] args) throws Exception {
        FilaComPrioridade<Integer> f1 = new FilaComPrioridade<Integer>(5);

        f1.enfieleirar(1);
        f1.enfieleirar(3);
        f1.enfieleirar(2);
        System.out.println(f1.toString());
    }
}
