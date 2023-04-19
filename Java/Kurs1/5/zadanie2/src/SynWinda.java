import java.util.LinkedList;
import java.util.Queue;

public class SynWinda {
    private int pietra;
    private Queue<Integer> wyborpietra;

    public SynWinda() {
        pietra = 1;
        wyborpietra = new LinkedList<>();
    }

    public synchronized void addDestinationFloor(int floor) {
        wyborpietra.add(floor);
        notifyAll();
    }

    public synchronized void move() throws InterruptedException {
        while (true) {
            while (wyborpietra.isEmpty()) {
                wait();
            }

            int wybor = wyborpietra.remove();
            System.out.println("Winda poruszająca się z piętra " + pietra + " na piętro " + wybor + "\n");

            while (pietra != wybor) {
                if (pietra < wybor) {
                    pietra++;
                } else {
                    pietra--;
                }
                Thread.sleep(1000);
                System.out.println("Winda na piętrze " + pietra);
            }
            System.out.println("Winda dojechała do piętra " + wybor + "\n");
        }
    }

    public static void main(String[] args) {
        SynWinda winda = new SynWinda();
        new Thread(() -> {
            try {
                winda.move();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }).start();

        new Thread(() -> winda.addDestinationFloor(5)).start();
        new Thread(() -> winda.addDestinationFloor(2)).start();
        new Thread(() -> winda.addDestinationFloor(7)).start();
    }
}
