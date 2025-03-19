package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio05.test;

public class ConversaoDeTipos {
    public char a = 'a';
    public char b = 'b';
    public char c = 'c';
    public int n1 = 1;
    public int n2 = 2;

    public static void main(String[] args) {
        ConversaoDeTipos convercao = new ConversaoDeTipos();
        convercao.a = (char) ((char)convercao.n1 + convercao.a);
        convercao.b += convercao.n1;

        System.out.println(convercao.a);
    }
}
