package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Test;

import PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Sistema.Conta;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Teste {
    public static void main (String[] args) {
        File f= new File("Test.csv");
        String line;
        try(FileWriter fw = new FileWriter(f); BufferedWriter br = new BufferedWriter(fw))
        {
            br.write("Nome,idade, sexo");
            br.newLine();
            br.write("Rafael,21, Masculino");
            br.newLine();
            br.write("Maria,19, Feminino");
        }catch(IOException e)
        {
            e.printStackTrace();
        }

        List<List<String>> regs = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(f)))
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
