package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio05.test;

public class NumerosImpares {
    public static void main(String[] args) {
        numersoImpares();
    }

    public static void numersoImpares() {
        int cont = 0;
        int i = 1;
        while(cont<60) {
            if(cont%2==1){
                System.out.println(i +". "+cont);
                i++;
            }
            cont++;

        }
    }
}
