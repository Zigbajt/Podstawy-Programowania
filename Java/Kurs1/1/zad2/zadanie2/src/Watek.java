public class Watek {
    // zmienna współdzielona przez wątki
    private long liczba;
    private long czytaj() {
        System.out.println(liczba);
        return liczba;
    }
    private void zapisz(long value) {
        liczba = value;
    }
    public static void main(String[] args) {
        Watek W1 = new Watek();
        TestLong T1= new TestLong();

        Thread v1 = new Thread(() -> {
            while (true)
                T1.write();
        });
        Thread v2 = new Thread(() -> {
            while (true)
                T1.read();
        });

        Thread t2 = new Thread(() -> {
            while (true) {
                synchronized (W1) {
                    long value = W1.czytaj();
                    value += 1;
                    W1.zapisz(value);
                }
            }
        });

        Thread t3 = new Thread(() -> {
            while (true) {
                synchronized (W1) {
                    long value = W1.czytaj();
                    value += 1;
                    W1.zapisz(value);
                }
            }
        });

        Thread t4 = new Thread(() -> {
            while (true) {
                synchronized (W1) {
                    long value = W1.czytaj();
                    value += 1;
                    W1.zapisz(value);
                    W1.notify();
                }
            }
        });
        Thread t5 = new Thread(() -> {
            while (true) {
                synchronized (W1) {
                    try {
                        W1.wait();
                    } catch (InterruptedException e) {
                        System.out.println("Błąd");
                    }
                    long value = W1.czytaj();
                    value += 1;
                    W1.zapisz(value);
                }
            }
        });

        //v1.start();
        //v2.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
    }
    private static class TestLong {
        static volatile long i = 0;

        public static void write() {
            i = i++;
        }

        public static void read() {
            System.out.println(i);
            System.exit(0);
        }
    }
}
