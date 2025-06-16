package PROGRAMAS_EM_JAVA.EstruturaDeDados.AlgoritimosBasicos.domain;

public class EstruturaEstatica<T> {
    private T[] a; //generalizaçao de tipo de variavel.
    private final int MAX = 5;
    public int cont;

    public EstruturaEstatica() {
        a = (T[]) new Object[MAX];
        cont = 0;
    }

    protected void inserirElemento(T data) {
        try{
            a[cont] = data;
            cont++;
        }catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("Não ha mais espaço no array");
            e.printStackTrace();
        }
    }

    protected void adicionaDeterminadaPosicao(T data, int posicao) throws Exception {
        if(posicao > MAX && cont == MAX && posicao<0) {
            throw new IllegalArgumentException("Posição invalida, ou não ha espaço no array");
        }

        for(int i = cont; i > posicao; i--) {
            a[i] = a[i-1];
        }

        a[posicao] = data;
        cont++;

    }

    protected boolean isEmpty(){
        if(cont == 0) return true;
        return false;
    }

    protected int tamanhoArray() {
        return cont;
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append("[ ");
        for(int i = 0; i<cont-1; i++) {
            s.append(a[i]);
            s.append(", ");
        }

        if(cont > 0) {
            s.append(a[cont-1]);
        }

        s.append(" ]");

        return s.toString();

    }

    protected void removerUltimoElemento() {
        cont--;
    }

    public void liberaMemoriaDaEstrutura() {
        a = (T[]) new Object[MAX];

    }
}
