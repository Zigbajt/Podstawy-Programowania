import java.util.concurrent.Phaser;

public class ZadPhaser {
    public static void main(String[] args) {
        Phaser phaser = new Phaser();

        Watek thread1 = new Watek(phaser, "Wątek 1");
        Watek thread2 = new Watek(phaser, "Wątek 2");
        Watek thread3 = new Watek(phaser, "Wątek 3");

        thread1.start();
        thread2.start();
        thread3.start();
    }
}

class Watek extends Thread {
    Phaser phaser;

    Watek(Phaser phaser, String name) {
        this.setName(name);
        this.phaser = phaser;
        this.phaser.register();
    }

    public void run() {
        System.out.println(getName() + " Rrozpoczoł phase 1");
        phaser.arriveAndAwaitAdvance();
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println(getName() + " Rrozpoczoł phase 2");
        phaser.arriveAndAwaitAdvance();
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println(getName() + " Rrozpoczoł phase 3");
        phaser.arriveAndAwaitAdvance();
    }
}
