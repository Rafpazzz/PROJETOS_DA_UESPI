package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio03p2;
//public class Estoque
public class Q1 {
    
    String nome;
    int quantidadeAtual;
    int quantidadeMinima;

    public Q1(){}
    
    public Q1(String nome, int quantidadeAtual, int quantidadeMinima) {
        this.nome = nome;
        this.quantidadeAtual = quantidadeAtual;
        this.quantidadeMinima = quantidadeMinima;
    }

    public void AlterarNome(String nome) {
        this.nome = nome;
    }

    public void alterarQtdMinima(int quantMim) {
        this.quantidadeMinima = quantMim;
    }

    public void Repor(int qunt) {
        if(precisarepor()){
            this.quantidadeAtual += qunt;
        }else {
            System.out.println("Nao precisa repor o estoque");
        }
        
    }

    public void darbaixa(int qnt) {
        this.quantidadeAtual -= qnt;
    }

    public void lista() {
        System.out.println("Nome: " + this.nome);
        System.out.println("Quantidade atual: " + this.quantidadeAtual);
        System.out.println("Quantidade minima: " + this.quantidadeMinima);
    }

    public boolean precisarepor() {
        return quantidadeAtual<quantidadeMinima;   
    }
}
