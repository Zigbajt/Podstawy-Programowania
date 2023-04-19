import java.util.concurrent.ConcurrentSkipListSet;

public class PunktC {
    private static ConcurrentSkipListSet<Integer> set = new ConcurrentSkipListSet<>();

    public static void main(String[] args) {
        // Tworzenie wątków zapisujących dane w zbiorze
        Thread t1 = new Thread(new Zapis(31));
        Thread t2 = new Thread(new Zapis(32));
        Thread t3 = new Thread(new Zapis(33));
        Thread t4 = new Thread(new Zapis(34));
        Thread t5 = new Thread(new Zapis(35));

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
