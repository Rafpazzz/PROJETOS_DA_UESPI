package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio08_1.Univercidade;

public class Bolsista extends Aluno{
    private String nomeProjeto;
    private String orientador;

    public Bolsista(String matricula, String curso, String nome, String nomeProjeto, String orientador) {
        super(matricula, curso, nome);
        this.nomeProjeto = nomeProjeto;
        this.orientador = orientador;
    }

    public String getNomeProjeto() {
        return nomeProjeto;
    }

    public void setNomeProjeto(String nomeProjeto) {
        this.nomeProjeto = nomeProjeto;
    }

    public String getOrientador() {
        return orientador;
    }

    public void setOrientador(String orientador) {
        this.orientador = orientador;
    }
}
