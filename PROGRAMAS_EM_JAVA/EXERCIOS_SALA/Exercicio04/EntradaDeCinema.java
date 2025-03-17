package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio04;

import java.util.Scanner;

public class EntradaDeCinema {
    private int diaSemana;
    private static final int DOMINGO = 1;
    private static final int SEGUNDA = 2;
    private static final int TERCA = 3;
    private static final int QUARTA = 4;
    private static final int QUINTA = 5 ;
    private static final int SEXTA = 6;
    private static final int SABADO = 7;
    public static void main(String[] args) {
        Scanner myReader = new Scanner(System.in);
        EntradaDeCinema entrada  = new EntradaDeCinema();

        System.out.print("Informe sua idade: ");
        int idade = myReader.nextInt();
        entrada.setDiaSemana(3);       
        System.out.println("O valor a pagar no ingrssoe é " + calculaPreco(idade, entrada.getDiaSemana()) + " reais");     
    }
        
    public static float calculaPreco(int idade, int dia) {
        float ingressoValor;
        if(dia == getTERCA() || dia == getQUARTA()) {
            ingressoValor = 6;
            return ingressoValor;
        }else {
            if(idade>65 || idade<14) {
                ingressoValor = 6;
                return ingressoValor;
            }else{
                ingressoValor = 12;
                return ingressoValor;
            }
                
        }
    }
        
    public void setDiaSemana(int diaSemana) {
        this.diaSemana = diaSemana;
    }

    public int getDiaSemana() {
        return diaSemana;
    }

    public static int getDOMINGO() {
        return DOMINGO;
    }

    public static int getSEGUNDA() {
        return SEGUNDA;
    }

    public static int getTERCA() {
        return TERCA;
    }

    public static int getQUARTA() {
        return QUARTA;
    }

    public static int getQUINTA() {
        return QUINTA;
    }

    public static int getSEXTA() {
        return SEXTA;
    }

    public static int getSABADO() {
        return SABADO;
    }

}
