import java.util.concurrent.Semaphore;

public class ZadSemaphore {
        public static void main(String[] args) {
            Wyswietl w = new Wyswietl();
            Runnable info = () -> {
                try {
                    w.ekran("Hello World!");
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            };

            Thread w1 = new Thread(info);
            Thread w2 = new Thread(info);
            Thread w3 = new Thread(info);

            w1.start();
            w2.start();
            w3.start();
        }
}
class Wyswietl {
    private Semaphore semaphore = new Semaphore(1);

    public void ekran(String message) throws InterruptedException {
        semaphore.acquire();
        try {
            System.out.println(message);
        } finally {
            semaphore.release();
        }
    }
}