package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio04.domain;

import java.util.Scanner;

public class Funcionario {
    private String nome;
    private String departamento;
    private double salario;
    private String dataEntradaBanco;
    private String RG;
    private boolean ativo;
    Scanner myReader = new Scanner(System.in);

    public void aumentoSalario() {
        if(salario>= 1500 && salario<1750) {
            salario = salario + salario*0.12;
        }else if(salario>= 1750 && salario<2000) {
            salario = salario + salario*0.1;
        } else if (salario>= 2000 && salario<3000) {
            salario = salario + salario*0.07;
        }else{
            salario = salario  + salario*5;
        }
    }

    public boolean ehNomeValido(String nome){
        if(nome != null && nome.length() == 0){
            return false;
        }

        String[] partes = nome.split(" ");

        if(partes.length < 2) return false;

        for(String parte : partes) {
            if(parte.isEmpty() || !Character.isUpperCase(parte.charAt(0))){
                return false;
            }
        }

        return true;
    }

    public boolean demite() {
        return ativo = false;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getDepartamento() {
        return departamento;
    }

    public void setDepartamento(String departamento) {
        this.departamento = departamento;
    }

    public double getSalaio() {
        return salario;
    }

    public void setSalaio(double salaio) {
        this.salario = salaio;
    }

    public String getDataEntradaBanco() {
        return dataEntradaBanco;
    }

    public void setDataEntradaBanco(String dataEntradaBanco) {
        this.dataEntradaBanco = dataEntradaBanco;
    }

    public String getRG() {
        return RG;
    }

    public void setRG(String RG) {
        this.RG = RG;
    }

    public boolean isAtivo() {
        return ativo;
    }

    public void setAtivo(boolean ativo) {
        this.ativo = ativo;
    }
}
