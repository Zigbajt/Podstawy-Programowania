import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

class WatekD implements Runnable {
    private final BlockingQueue<Integer> queue;

    public WatekD(BlockingQueue<Integer> queue) {
        this.queue = queue;
    }

    public void run() {
        while (true) {
                try{
                Integer p = queue.take();
                if (p == -1) {
                    System.out.println("Zadanie zakończone");
                    break;
                }
                System.out.println("Wykonuję D zadanie");
                Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
        }

    }
}

public class D {
    public static void main(String[] args) {
        BlockingQueue<Integer> queue = new ArrayBlockingQueue<Integer>(1024);
        WatekD task = new WatekD(queue);
        Thread thread = new Thread(task);
        thread.start();

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        for(int i=1;i<=6;i++){
            if(i==5){
                queue.offer(-1);
            }else {
                queue.offer(i);
            }
        }
    }
}
