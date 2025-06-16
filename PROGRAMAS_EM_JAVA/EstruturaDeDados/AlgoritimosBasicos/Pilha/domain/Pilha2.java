package PROGRAMAS_EM_JAVA.EstruturaDeDados.AlgoritimosBasicos.Pilha.domain;

import PROGRAMAS_EM_JAVA.EstruturaDeDados.AlgoritimosBasicos.domain.EstruturaEstatica;

public class Pilha2<T> extends EstruturaEstatica<T> {

    public Pilha2() {
        super();
        cont = 0;
    }

    public void queue(T data) {
        super.inserirElemento(data);
    }

    public void dequeue() {
        super.removerUltimoElemento();
    }

    public String mostar() {
        return super.toString();
    }

    public boolean vezia() {
        return super.isEmpty();
    }

}
