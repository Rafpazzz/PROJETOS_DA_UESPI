package PROGRAMAS_EM_JAVA.EstruturaDeDados.AlgoritimosBasicos.Fila.domain;

public class FilaComPrioridade<T> extends FilaEstatica<T>{

    public FilaComPrioridade(int tamanho) {
        super(tamanho);
    }

    public void enfieleirar(T elemento) throws Exception {
        Comparable<T> chave =(Comparable<T>) elemento;
        int i;
        for(i=0; i<cont; i++) {
            if(chave.compareTo(a[i]) < 0) {
                break;
            }
        }
        this.adicionaDeterminadaPosicao(elemento, i);
    }
}
