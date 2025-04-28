package PROGRAMAS_EM_JAVA.EXERCIOS_SALA.Exercicio08;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Zoologico {
    public static void main(String[] args) {
        LinkedList<Animal> arr = new LinkedList<>();
        Animal a1 = new Animal();
        Gato a2 = new Gato();
        Gato a3 = new Gato();
        Cachorro a4 = new Cachorro();
        Cachorro a5 = new Cachorro();

        arr.add(a1);
        arr.add(a2);
        arr.add(a3);
        arr.add(a4);
        arr.add(a5);

        for(int i = 0; i<arr.size(); i++) {
            arr.get(i).fazerSom();
        }

    }
}
