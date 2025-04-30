package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Test;

import PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Sistema.Conta;

public class Teste {
    public static void main (String[] args) {
        Conta c = new Conta ();
        c.deposita (1000);
        System.out.println(c.getSaldo());
    }
}
