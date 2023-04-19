class WatekB implements Runnable {
    public void run() {
        while (!Thread.currentThread().isInterrupted()) {
            // tutaj kod zadania, który ma być wykonywany
            System.out.println("Wykonuję B zadanie");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}

public class B {
    public static void main(String[] args) {
        WatekB task = new WatekB();
        Thread thread = new Thread(task);
        thread.start();

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        thread.interrupt();
        System.out.println("Zadanie zakończone");
    }
}

