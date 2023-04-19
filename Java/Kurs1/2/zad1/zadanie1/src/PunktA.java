import java.util.HashSet;

public class PunktA {
    private static HashSet<Integer> hashSet = new HashSet<>();

    public static void main(String[] args) {
        Thread t1 = new Thread(new Zapis(11));
        Thread t2 = new Thread(new Zapis(12));
        Thread t3 = new Thread(new Zapis(13));
        Thread t4 = new Thread(new Zapis(14));
        Thread t5 = new Thread(new Zapis(15));

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
            synchronized (hashSet) {
                hashSet.add(value);
                System.out.println("Dodano " + value + " - wątek " + Thread.currentThread().getName());
            }
        }
    }

    static class Odczyt implements Runnable {
        @Override
        public void run() {
            synchronized (hashSet) {
                for (Integer i : hashSet) {
                    System.out.println("Odczytano " + i + " - wątek " + Thread.currentThread().getName());
                }
            }
        }
    }
}
