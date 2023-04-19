import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.concurrent.*;

class DrukarkaA {
    private boolean czydrukuje;

    private ExecutorService ex = Executors.newSingleThreadExecutor();
    private Queue<String> dokument;

    public DrukarkaA() {
        czydrukuje = false;
        dokument = new LinkedList<>();
    }

    public Future<String> druk(String plik){
        return ex.submit(new Callable<String>() {
            @Override
            public String call() throws Exception {
                czydrukuje = true;
                System.out.println("Drukuje: " + plik);
                try {
                    Thread.sleep(5000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                return plik;
            }
        });
    }
}

public class AktDruk {
    public static void main(String[] args) {
        DrukarkaA drukarka = new DrukarkaA();
        List<Future<?>> result = new CopyOnWriteArrayList<Future<?>>();
        result.add(drukarka.druk("Dokument 1"));
        result.add(drukarka.druk("Dokument 2"));
        result.add(drukarka.druk("Dokument 3"));
    }
}
