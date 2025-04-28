package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio08;

public class Gerente extends Funcionario{
    private double bonus;

    public double getBonus() {
        return bonus;
    }

    public void setBonus(double bonus) {
        this.bonus = bonus;
    }

    public double calcularSalario() {
        return getSalario() + bonus;
    }
}
