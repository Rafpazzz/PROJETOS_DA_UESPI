package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio06.test;

public class ConsoanteVogal {
    public static void main(String[] args) {
        char[] vogais = {'A','E','I', 'O', 'U'};
        char[] conjuntoLetras = {'D','E','R', 'T', 'L', 'O', 'K', 'A', 'M'};
        int i = 0;
        int cont = 0;
        StringBuilder conjuntoVogais = new StringBuilder();
        StringBuilder conjuntoConsoante = new StringBuilder();
        conjuntoVogais.append("[");
        conjuntoConsoante.append("[");
        while(i<conjuntoLetras.length) {
            while(cont<vogais.length) {
                if(vogais[cont] == conjuntoLetras[i]) {
                    conjuntoVogais.append(conjuntoLetras[i]);
                    conjuntoVogais.append(" ");
                }
                cont++;
            }
            conjuntoConsoante.append(conjuntoLetras[i]);
            conjuntoConsoante.append(" ");
            cont = 0;
            i++;
        }
        conjuntoVogais.append("]");
        conjuntoConsoante.append("]");

        System.out.println(conjuntoVogais);
        System.out.println("=======================");
        System.out.println(conjuntoConsoante);
    }
}
