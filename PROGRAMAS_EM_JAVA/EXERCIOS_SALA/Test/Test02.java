package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Test02 {
    public static void main(String[] args) {
        String csvFile = "output.csv";
        String line;

        try(PrintWriter writer = new PrintWriter(new File(csvFile)))
        {
            writer.println("Nome,idade,Sexo");
            writer.println("Rafael,21,Masculino");
            writer.println("Maria,19,Feminino");
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

        List<List<String>> regs = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(csvFile)))
        {
            while((line = br.readLine()) != null) {
                String [] lins = line.split(",");
                regs.add(Arrays.asList(lins));
                System.out.println(lins[0] + " - " + lins[1] + " - " + lins[2]);
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
