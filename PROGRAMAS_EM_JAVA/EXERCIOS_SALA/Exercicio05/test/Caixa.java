package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio05.test;

public class Caixa {
    public static void main (String[] args) {
        ContaCorrente conta1 = new ContaCorrente();
        ContaCorrente conta2 = new ContaCorrente();
        ContaCorrente conta3 = new ContaCorrente();

        System.out.println ("Saldo inicial = " + conta1.getSaldo ());
        conta1.setDeposito (1400.00);
        System.out.println ("Novo saldo = " + conta1.getSaldo ());

        System.out.println ("Saldo inicial = " + conta2.getSaldo ());
        conta2.setDeposito (3300.00);
        System.out.println ("Novo saldo = " + conta2.getSaldo ());

        System.out.println ("Saldo inicial = " + conta3.getSaldo ());
        conta3.setDeposito (4200.00);
        System.out.println ("Novo saldo = " + conta3.getSaldo ());
    }
}

class ContaCorrente {
    private double saldo = 0;


    public void setDeposito (double valor) {
        saldo += valor;
    }

    public void setSaque (double valor) {
        saldo -= valor;
    }

    public double getSaldo () {
        return saldo;
    }
}

