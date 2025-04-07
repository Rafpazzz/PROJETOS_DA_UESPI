package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio07;

public class PrecoTarifa {
    public final class fatorCalculoTarifa {
        public static final float FATOR_ZONA_LESTE = 0.45F;
        public static final float FATOR_ZONA_SUL = 0.25F;
        public static final float FATOR_ZONA_NORTE = 0.20F;
        public static final float FATOR_ZONA_OESTE = 0.10F;
    }
    public static void main(String[] args) {
        fatorCalculoTarifa tarifa = null;
        double zona = 0.1;
        final double FATOR_BASE = 2.95;
        double valorFinal = 0;
        if(zona == 0.45) {
            valorFinal = FATOR_BASE + (double) tarifa.FATOR_ZONA_LESTE;
        } else if(zona == 0.25){
            valorFinal = FATOR_BASE + (double)tarifa.FATOR_ZONA_SUL;
        } else if (zona == 0.2) {
            valorFinal = FATOR_BASE + (double)tarifa.FATOR_ZONA_NORTE;
        } else if (zona == 0.1) {
            valorFinal = FATOR_BASE + (double)tarifa.FATOR_ZONA_OESTE;
        }else {
            valorFinal = FATOR_BASE;
        }
        System.out.printf("Valor final = %.2f", valorFinal);
    }
}
