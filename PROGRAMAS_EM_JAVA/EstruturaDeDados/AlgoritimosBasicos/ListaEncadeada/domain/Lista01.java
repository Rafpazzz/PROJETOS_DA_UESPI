package PROGRAMAS_EM_JAVA.EstruturaDeDados.AlgoritimosBasicos.ListaEncadeada.domain;

public class Lista01<T> {
    private No<T> inicio;
    private No<T> ultimo;
    private int cont;

    public void add(T elemento) {
        No<T> celula = new No<>(elemento);
        if(cont == 0){
            this.inicio = celula;
        }else {
            ultimo.setProximo(celula);
        }
        this.ultimo = celula;
        cont++;
    }

    public int getCont() {
        return this.cont;
    }

    public void limpa() {
        for( No<T> atual = this.inicio; atual != null;) {
            No<T> proximo = atual.getProximo();
            atual.setElemento(null);
            atual.setProximo(proximo);
            atual = proximo;
        }

        inicio = null;
        ultimo = null;
        cont = 0;
    }

    @Override
    public String toString() {
        if(cont == 0){
            return "[]";
        }

        final StringBuilder sb = new StringBuilder();
        No<T> atual = this.inicio;
        sb.append("[");
        for(int i = 0; i<this.cont-1; i++) {
            sb.append(atual.getElemento()).append(", ");
            atual = atual.getProximo();
        }
        sb.append(atual.getElemento());
        sb.append("]");
        return sb.toString();
    }
}
