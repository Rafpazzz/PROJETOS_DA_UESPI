package PROGRAMAS_EM_JAVA.EstruturaDeDados.Fila.domain;

public class FilaEstatica<T> {
    private T[] a;
    private int cont;
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
}




