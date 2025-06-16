package PROGRAMAS_EM_JAVA.EstruturaDeDados.AlgoritimosBasicos.Arrays.domain;

import PROGRAMAS_EM_JAVA.EstruturaDeDados.AlgoritimosBasicos.domain.EstruturaEstatica;

public class Lista2<T> extends EstruturaEstatica<T> {
    private T[] a;
    private final int MAX = 5;

    public Lista2() {
        super();
    }

    public void inserirElemento(T data){

    }

    protected void adicionaDeterminadaPosicao(T data, int posicao) throws Exception{

    }

    public void retornaElemento(int index) {
        try{
            System.out.println(a[index]);
        }catch(IllegalArgumentException e) {
            System.out.println("Index não pertence ao array");
            e.printStackTrace();
        }
    }

    public boolean existeElemento(T data) {
        for(int i = 0; i<cont; i++) {
            if(a[i].equals(data)) return true;
        }
        return false;
    }

    public void removerElemento(T data) {
        try{
            for(int i = 0; i<cont; i++) {
                if(a[i].equals(data)) {
                    a[i] = a[i+1];
                    cont--;
                    return;
                }
            }
        }catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Elemento nao existe no array");
            e.printStackTrace();
        }
    }

    public int ultimoIndice() {
        if(cont == 0) return -1;
        return cont-1;
    }

    public void liberaLista1() { //dependendo do atamanho vale mais a pena por quiestao da lixeira do java fazer um trataamento com os dados liberados na memoria
        for(int i = 0; i<cont; i++) {
            a[i] = null;
        }
        cont = 0;

    }

    public void liberaLiata2() { //melhor opçãopor ser menos custoso para a maquina
        a = (T[]) new Object[MAX];

    }

    public void liberaLista3() {
        cont = 0;

    }

}
