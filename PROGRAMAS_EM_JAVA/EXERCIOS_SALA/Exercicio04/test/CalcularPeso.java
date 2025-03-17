package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio04.test;

import java.io.IOException;
import java.util.*;

public class CalcularPeso {
    public static void main(String[] args) {
        Scanner myReader = new Scanner(System.in);
        try{
            System.out.print("Informe sua altura: ");
            double altura = myReader.nextDouble();
            myReader.nextLine();
            System.out.print("Informe seu sexo[M/F]: ");
            String sexo = myReader.nextLine().trim();
            System.out.println(pesoIdeal(altura, sexo));
        }catch(Exception e) {
            System.out.println("Digitos errados");
            e.printStackTrace();
        }finally{
            myReader.close();
        }

    }

    public static boolean pesoIdeal(double altura, String sexo) {
        double peso;
        if(sexo.equalsIgnoreCase("F")) {
            peso = (62.1 * altura) - 44.7;
            if(peso>46 && peso <54) return true;
            else return false;
        }else {
            peso = (72.7 * altura) - 58;
            if(peso>71 && peso <82) return true;
            else return false;
        }


    }
}
