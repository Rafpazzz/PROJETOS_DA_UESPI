package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio08_1.Univercidade;

public class Funcionario extends Menbro{
    private String unidade;
    private double salario;

    public Funcionario(String unidade, double salario, String nome) {
        this.unidade = unidade;
        this.salario = salario;
        setNome(nome);
    }

    public void aumentaSalario(double aumento) {
        this.salario = this.salario+aumento;
    }

    public String getUnidade() {
        return unidade;
    }

    public void setUnidade(String unidade) {
        this.unidade = unidade;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }
}
