package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio08_1.Univercidade;

public class Aluno extends Menbro{
    private String matricula;
    private String curso;

    public Aluno(String matricula, String curso,String nome) {
        this.matricula = matricula;
        this.curso = curso;
        setNome(nome);
    }

    public String getMatricula() {
        return matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }
}
