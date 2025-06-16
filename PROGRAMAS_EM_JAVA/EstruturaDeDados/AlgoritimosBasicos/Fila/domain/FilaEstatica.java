package PROGRAMAS_EM_JAVA.EstruturaDeDados.AlgoritimosBasicos.Fila.domain;

public class FilaEstatica<T> {
    protected T[] a;
    protected int cont;
    private int tamanho;

    public FilaEstatica(int tamanho) {
        this.tamanho = tamanho;
        a = (T[]) new Object[tamanho];
        cont = 0;
    }

    public void enfileira(T elemento) {
        try{
            a[cont] = elemento;
            cont++;
        }catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("A Fila esta lotada.");
            e.printStackTrace();
        }
    }

    public void adicionaDeterminadaPosicao(T data, int posicao) throws Exception {
        if(posicao > tamanho && cont == tamanho && posicao<0) {
            throw new IllegalArgumentException("Posição invalida, ou não ha espaço no array");
        }

        for(int i = cont; i > posicao; i--) {
            a[i] = a[i-1];
        }

        a[posicao] = data;
        cont++;

    }

    public void aumentaCapaciadade(int n) {
        tamanho = n;
    }

    public boolean isEmpty() {
        if(cont == 0) return true;
        return false;
    }

    public T espiar() {
        if(cont == 0){
            return null;
        }

        return a[0];
    }

    public T desenfileirar() {
        if(isEmpty()) {
            return null;
        }
        T temp = a[0];
        for(int i = 0; i<cont; i++) {
            a[i] = a[i+1];
        }
        cont--;
        return temp;
    }

    public int tamanho() {
        return cont;
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append("[");

        for(int i = 0; i<cont-1; i++) {
            s.append(a[i]);
            s.append(", ");
        }

        if(cont>0) {
            s.append(a[cont-1]);
        }

        s.append("]");

        return s.toString();
    }
}




