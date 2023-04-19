import java.io.File;
import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveTask;

public class A extends RecursiveTask<Long> {
    private final File plik;

    public A(File plik) {
        this.plik = plik;
    }

    @Override
    protected Long compute() {
        if (plik.isFile()) {
            return plik.length();
        }

        long ilosc = 0;
        File[] naxtplik = plik.listFiles();
        if (naxtplik != null) {
            A[] watek = new A[naxtplik.length];
            for (int i = 0; i < naxtplik.length; i++) {
                watek[i] = new A(naxtplik[i]);
                watek[i].fork();
            }

            for (A task : watek) {
                ilosc += task.join();
            }
        }

        return ilosc;
    }

    public static void main(String[] args) {
        String sciezka = "C:/aaa";
        File directory = new File(sciezka);

        ForkJoinPool fork = new ForkJoinPool();
        A watekA = new A(directory);
        long bit = fork.invoke(watekA);

        System.out.println("\n" + "Całkowity rozmiar plików w katalogu " + sciezka + " wynosi " + bit + " bitów.");
    }
}
