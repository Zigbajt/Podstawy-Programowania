class WatekA implements Runnable {
    private volatile boolean cancelled = false;

    public void run() {
        while (!cancelled) {
            System.out.println("Wykonuję A zadanie");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void cancel() {
        cancelled = true;
    }
}

public class A {
    public static void main(String[] args) {
        WatekA task = new WatekA();
        Thread thread = new Thread(task);
        thread.start();

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        task.cancel();
        System.out.println("Zadanie zakończone");
    }
}

