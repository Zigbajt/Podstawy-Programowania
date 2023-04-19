import java.util.concurrent.CopyOnWriteArraySet;

public class PunktD {
    private static CopyOnWriteArraySet<Integer> set = new CopyOnWriteArraySet<>();

    public static void main(String[] args) {
        Thread t1 = new Thread(new Zapis(41));
        Thread t2 = new Thread(new Zapis(42));
        Thread t3 = new Thread(new Zapis(43));
        Thread t4 = new Thread(new Zapis(44));
        Thread t5 = new Thread(new Zapis(45));

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
