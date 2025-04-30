package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio08_1;

public class Circulo implements PrimitivaGrafica{
    private final double PI = 3.14;
    private int espessura;
    Ponto p1 = new Ponto(5,5);
    private int raio;

    public int getRaio() {
        return raio;
    }

    public void setRaio(int raio) {
        this.raio = raio;
    }

    @Override
    public double area() {
        return p1.getX()*p1.getY()*PI;
    }

    @Override
    public void setEspessura(int e) {
        this.espessura = e;
    }

    @Override
    public String getNome() {
        return "Circulo";
    }
}
