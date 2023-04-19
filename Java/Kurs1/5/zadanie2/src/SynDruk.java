class Drukarka {
    private boolean czydrukuje;
    public synchronized void print(String dokument) throws InterruptedException {
        while (czydrukuje) {
            wait();
        }
        czydrukuje = true;
        System.out.println("Drukuje: " + dokument);
        Thread.sleep(5000);
        czydrukuje = false;
        notifyAll();
    }
}

public class SynDruk {
    public static void main(String[] args) {
        Drukarka drukarka = new Drukarka();
        new Thread(() -> {
            try {
                drukarka.print("Dokument 1");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }).start();

        new Thread(() -> {
            try {
                drukarka.print("Dokument 2");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }).start();

        new Thread(() -> {
            try {
                drukarka.print("Dokument 3");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }).start();
    }
}
