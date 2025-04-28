package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio08;

public class Impresa {
    public static void main(String[] args) {
        Funcionario f1 = new Funcionario();
        Gerente f2 = new Gerente();

        f1.setSalario(2000);
        f2.setSalario(3000);
        f2.setBonus(1000);

        System.out.println("Salario funcionario: "+f1.calcularSalario());
        System.out.println("Salario gerente: "+f2.calcularSalario());
    }
}
