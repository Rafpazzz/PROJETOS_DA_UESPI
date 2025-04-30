package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio08_1;

public class Quadrado implements PrimitivaGrafica{
    private int espessura;
    Ponto p1 = new Ponto(5,5);
    Ponto p2 = new Ponto(5,5);


    @Override
    public double area() {
        return p1.getX()*p1.getY();
    }

    @Override
    public void setEspessura(int e) {
        this.espessura = e;
    }

    @Override
    public String getNome() {
        return "Quadrado";
    }
}
