import java.util.concurrent.*;

class WatekC extends Thread {
    public void run() {
        while (true) {
            System.out.println("Wykonuję C zadanie");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}

public class C {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newSingleThreadExecutor();
        Future<?> future = executor.submit(new WatekC());

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        future.cancel(true);
        executor.shutdown();
        System.out.println("Zadanie zakończone");
    }
}