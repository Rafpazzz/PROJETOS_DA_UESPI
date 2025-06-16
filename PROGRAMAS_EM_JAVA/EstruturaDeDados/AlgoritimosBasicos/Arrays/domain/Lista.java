package PROGRAMAS_EM_JAVA.EstruturaDeDados.AlgoritimosBasicos.Arrays.domain;

import java.lang.reflect.Array;

public class Lista<T> {
    private T[] a; //generalizaçao de tipo de variavel.
    private final int MAX = 5;
    public int cont;

    public Lista(Class<T> tipoClasse) {
        a = (T[])Array.newInstance(tipoClasse,MAX);
        cont = 0;
    }

    public Lista() {
        a = (T[]) new Object[MAX];
        cont = 0;
    }

    public void inserirElemento(T data) {
        try{
            a[cont] = data;
            cont++;
        }catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("Não ha mais espaço no array");
            e.printStackTrace();
        }
    }

    public int tamanhoArray() {
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

//        String s = "[ ";
//        for(int i = 0; i<cont-1; i++) {
//            s += a[i];
//            s += ", ";
//        }
//
//        if(cont > 0) {
//            s += a[cont-1];
//        }
//
//        s+=" ]";
        return s.toString();
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

    public void adicionaDeterminadaPosicao(T data, int posicao) throws Exception {
        if(posicao > MAX && cont == MAX && posicao<0) {
            throw new IllegalArgumentException("Posição invalida, ou não ha espaço no array");
        }

        for(int i = cont; i > posicao; i--) {
            a[i] = a[i-1];
        }

        a[posicao] = data;
        cont++;

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
