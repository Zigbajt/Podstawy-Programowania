import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.concurrent.*;

class Winda {
    private int pietro;
    private Queue<Integer> wyborpietra;

    private ExecutorService ex = Executors.newSingleThreadExecutor();
    private boolean czyruch;

    public Winda() {
        pietro = 1;
        wyborpietra = new LinkedList<>();
        czyruch = false;
    }

    public void wyborpietra(int p) {
        wyborpietra.add(p);
        pietro(p);
    }
    public Future<Integer> pietro(int wybor){
        return ex.submit(new Callable<Integer>() {
            @Override
            public Integer call() throws Exception {
                System.out.println("Winda poruszająca się z piętra " + pietro + " na pietro " + wybor + "\n");
                while (pietro != wybor) {
                    if (pietro < wybor) {
                        pietro++;
                    } else {
                        pietro--;
                    }
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    System.out.println("Winda na piętrze " + pietro);
                }
                System.out.println("Winda dojechała do piętra " + wybor + "\n");
                return pietro;
            }
        });
    }
}

public class AktWinda {
    public static void main(String[] args) {
        Winda winda = new Winda();
        List<Future<?>> result = new CopyOnWriteArrayList<Future<?>>();
        result.add(winda.pietro(5));
        result.add(winda.pietro(2));
        result.add(winda.pietro(7));
    }
}

