package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio05.test;

public class Quadrado {
    public double lado;

    public Quadrado(double lado) {
        this.lado = lado;
    }

    public double area() {
        return lado*lado;
    }

    public double perimetro() {
        return lado*4;
    }

    public static void main(String[] args) {
        Quadrado q1 = new Quadrado(4);
        System.out.println("Area: " + q1.area());
        System.out.println("Perimetro: " + q1.perimetro());
    }
}
