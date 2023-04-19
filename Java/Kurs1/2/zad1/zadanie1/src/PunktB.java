import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

public class PunktB {
    private static Set<Integer> set = Collections.synchronizedSet(new HashSet<>());

    public static void main(String[] args) {
        // Tworzenie wątków zapisujących dane w zbiorze
        Thread t1 = new Thread(new Zapis(21));
        Thread t2 = new Thread(new Zapis(22));
        Thread t3 = new Thread(new Zapis(23));
        Thread t4 = new Thread(new Zapis(24));
        Thread t5 = new Thread(new Zapis(25));

        Thread t6 = new Thread(new Odczyt());

        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
        t6.start();
    }

    static class Zapis implements Runnable {
        int value;

        Zapis(int value) {
            this.value = value;
        }

        @Override
        public void run() {
            set.add(value);
            System.out.println("Dodano " + value + " - wątek " + Thread.currentThread().getName());
        }
    }

    static class Odczyt implements Runnable {
        @Override
        public void run() {
            for (Integer i : set) {
                System.out.println("Odczytano " + i + " - wątek " + Thread.currentThread().getName());
            }
        }
    }
}