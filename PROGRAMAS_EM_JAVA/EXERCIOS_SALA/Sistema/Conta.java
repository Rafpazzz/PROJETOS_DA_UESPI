package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Sistema;

public class Conta {
    private double saldo;
    public void deposita (double valor) {
        this.saldo += valor;
    }

    public double getSaldo() {
        return saldo;
    }
}
