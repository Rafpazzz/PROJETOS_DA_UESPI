package PROGRAMAS_EM_JAVA.EstruturaDeDados.AlgoritimosBasicos.Arrays.domain;

import java.util.Objects;

public class Contato {
    private String nome;
    private int contato;
    private String email;

    public Contato(String nome, int contato, String email) {
        this.nome = nome;
        this.contato = contato;
        this.email = email;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Contato contato1 = (Contato) o;
        return contato == contato1.contato && Objects.equals(nome, contato1.nome) && Objects.equals(email, contato1.email);
    }

    @Override
    public int hashCode() {
        return Objects.hash(nome, contato, email);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getContato() {
        return contato;
    }

    public void setContato(int contato) {
        this.contato = contato;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return "Contato{" +
                "nome='" + nome + '\'' +
                ", contato=" + contato +
                ", email='" + email + '\'' +
                '}';
    }
}
