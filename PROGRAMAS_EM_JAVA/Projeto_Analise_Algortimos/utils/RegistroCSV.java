package PROGRAMAS_EM_JAVA.Projeto_Analise_Algortimos.utils;

import PROGRAMAS_EM_JAVA.Projeto_Analise_Algortimos.domain.Resultado;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class RegistroCSV {

    private PrintWriter writer;

    public void iniciarArquivo(String caminho) {
        try {
            writer = new PrintWriter(new FileWriter(caminho));
            writer.println("Algoritmo,Tamanho,Cenario,Tempo(ns),Tempo(ms),Comparacoes,Atribuicoes");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void registrarResultado(String algoritmo, int tamanho, Cenario cenario, long tempoNano, double tempoMs, Resultado r) {
        writer.printf("%s,%d,%s,%d,%.4f,%d,%d%n",
                algoritmo,
                tamanho,
                cenario,
                tempoNano,
                tempoMs,
                r.getComparacoes(),
                r.getAtribuicoes());
    }

    public void fechar() {
        if (writer != null) writer.close();
    }
}
