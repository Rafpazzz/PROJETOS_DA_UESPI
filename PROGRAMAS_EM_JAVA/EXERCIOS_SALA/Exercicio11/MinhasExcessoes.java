package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio11;

public class MinhasExcessoes {

    public void recebeString(String str) {
            if(!Character.isLetter(str.charAt(0))){
                System.out.println("String inicia com numeros");
                throw new RuntimeException();
            }
            for(int i = 0; i<str.length(); i++) {
                if (!Character.isUpperCase(str.charAt(i))) {
                    System.out.println("String possue letras minusculas");
                    throw new RuntimeException();
                }
            }
    }

    public static void main(String[] args) {
        String str = "RAFAEl";
        MinhasExcessoes m = new MinhasExcessoes();
        m.recebeString(str);
    }
}
