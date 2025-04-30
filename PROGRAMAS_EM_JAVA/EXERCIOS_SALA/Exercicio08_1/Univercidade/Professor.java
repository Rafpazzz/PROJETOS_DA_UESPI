package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio08_1.Univercidade;

public class Professor extends Funcionario{
    private String regimeDeTrabalho;

    public Professor(String unidade, double salario, String nome, String regimeDeTrabalho) {
        super(unidade, salario, nome);
        this.regimeDeTrabalho = regimeDeTrabalho;
    }

    public String getRegimeDeTrabalho() {
        return regimeDeTrabalho;
    }

    public void setRegimeDeTrabalho(String regimeDeTrabalho) {
        this.regimeDeTrabalho = regimeDeTrabalho;
    }
}
