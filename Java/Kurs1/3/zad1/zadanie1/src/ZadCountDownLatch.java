import java.util.concurrent.CountDownLatch;

public class ZadCountDownLatch {
    public static void main(String[] args) {
        final CountDownLatch latch = new CountDownLatch(3);
        Thread task1 = new Thread(() -> {
            System.out.println("Wątek 1.");
            latch.countDown();
        });
        Thread task2 = new Thread(() -> {
            System.out.println("Wątek 2.");
            latch.countDown();
        });
        Thread task3 = new Thread(() -> {
            System.out.println("Wątek 3.");
            latch.countDown();
        });

        task1.start();
        task2.start();
        task3.start();

        try {
            latch.await();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Koniec Programu.");
    }
}
