package utils;

public class TempoUtils {

    public static long medirNano(Runnable metodo) {
        long inicio = System.nanoTime();
        metodo.run();
        long fim = System.nanoTime();
        return fim - inicio;
    }

    public static double nanoParaMs(long nano) {
        return nano / 1_000_000.0;
    }
}
