package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio04.test;

import java.util.*;


public class Quilomatragem {
    public static void main(String[] args) {
        int quilimetrtosPercorridos;
        int quantidadeDeGasolina;
        float mediaPorLitro;
        int galoes;


        Scanner myReader = new Scanner(System.in);

        System.out.print("Informe a quantidade de quilometros percorrido: ");
        quilimetrtosPercorridos = myReader.nextInt();
        System.out.print("Informe quantos litros foram utilizados: ");
        quantidadeDeGasolina = myReader.nextInt();
        System.out.println("Informe o tamanho do seu galao de combustivel: ");
        galoes = myReader.nextInt();
        mediaPorLitro = (float)quilimetrtosPercorridos/quantidadeDeGasolina;

        System.out.println("=================================");

        System.out.printf("A media de combustivel gasto: %.2f" + mediaPorLitro);
        System.out.println("Quantidade de quilimtros percorridos: " + quilimetrtosPercorridos);
        System.out.println("Quantidade de galoes gasto: " + Math.ceil(quantidadeDeGasolina/galoes));
    }
}
