package domain;

public class Resultado {

    private long comparacoes;
    private long atribuicoes;

    public Resultado() {
        this.comparacoes = 0;
        this.atribuicoes = 0;
    }

    public void addComparacao() {
        this.comparacoes++;
    }

    public void addAtribuicao() {
        this.atribuicoes++;
    }

    public long getComparacoes() {
        return comparacoes;
    }

    public long getAtribuicoes() {
        return atribuicoes;
    }

    public void reset() {
        this.comparacoes = 0;
        this.atribuicoes = 0;
    }
}
