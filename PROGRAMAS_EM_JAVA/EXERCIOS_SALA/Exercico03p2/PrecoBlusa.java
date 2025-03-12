package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercico03p2;

public class PrecoBlusa {
    public static void main(String[] args) {
        double preco = 100;

        if(preco >140) {
            preco = preco - preco*0.3;
        }else if(preco<140 && preco>80) {
            preco = preco - preco*0.2;
        }else if(preco<80 && preco>60) {
            preco = preco - preco*0.1;
        }else if(preco<60) {
            preco = preco - preco*0.05;
        }

        System.out.println("Valor final: " + preco);
    }
}
