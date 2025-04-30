package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio08_1;

public class Ponto implements PrimitivaGrafica {
    private double x;
    private double y;
    private int e;

    public Ponto() {
        x = 1;
        y = 1;
    }

    public  Ponto(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void desloca(double dx, double dy) {
        x = x+dx;
        y = y+dy;
    }

    @Override
    public String toString() {
        return "("+getX()+", "+getY()+")";
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public void setY(String y) {
        double newY = Double.parseDouble(y);
        this.y = newY;
    }

    public void setX(String x) {
        double newX = Double.parseDouble(x);
        this.x = newX;
    }

    public void desloca(String dx, String dy) {
        double newDx = Double.parseDouble(dx);
        double newDy = Double.parseDouble(dy);

        x = x+newDx;
        y = y+newDy;
    }

    @Override
    public double area() {
        double a, b,c;
        a = x*y;
        return a;
    }

    @Override
    public void setEspessura(int e) {
        this.e = e;
    }

    @Override
    public String getNome() {
        return "Quadrado";
    }
}
