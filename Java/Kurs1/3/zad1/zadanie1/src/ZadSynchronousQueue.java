import java.util.concurrent.SynchronousQueue;

public class ZadSynchronousQueue {
    public static void main(String[] args) {
        Thread p = new Thread(() -> {
            try {
                Producent();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        Thread k = new Thread(() -> {
            try {
                Konsument();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        p.start();
        k.start();
    }
    // Tworzymy synchronous queue
    private static SynchronousQueue<Integer> queue = new SynchronousQueue<>();
    public static void Konsument() throws InterruptedException {
        while (true) {
            int liczba = queue.take();
            System.out.println("Konsument: " + liczba);
        }
    }
    public static void Producent() throws InterruptedException {
        while (true) {
            int liczba = (int) (Math.random() * 10);
            System.out.println("Producent: " + liczba);
            queue.put(liczba);
        }
    }
}

