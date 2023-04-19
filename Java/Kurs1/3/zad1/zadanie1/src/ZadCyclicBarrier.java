import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;

public class ZadCyclicBarrier {
        private static final int numer = 4;
        private static final CyclicBarrier barrier = new CyclicBarrier(numer, new Runnable() {
            @Override
            public void run() {
                System.out.println("Wszystkie bolidy są gotowe!");
            }
        });

        public static void main(String[] args) {
            // Tworzymy i uruchamiamy wątki dla każdego bolidu
            for (int i = 0; i < numer; i++) {
                new Thread(new Bolid(i, barrier)).start();
            }
        }

        private static class Bolid implements Runnable {
            private final int numerStartowy;
            private final CyclicBarrier barrier;

            public Bolid(int carNumber, CyclicBarrier barrier) {
                this.numerStartowy = carNumber;
                this.barrier = barrier;
            }

            @Override
            public void run() {
                while (true) {
                    try {
                        // Przygotowanie bolidów do okrążenia
                        System.out.println("Bolid " + numerStartowy + " jest gotowy do wyścigu.");
                        barrier.await(); // Czekanie na pozostałe Bolidy

                        // Właściwe okrążenie
                        System.out.println("Bolid " + numerStartowy + " " +
                                "rozpoczyna okrążenie!");
                        Thread.sleep( 200);
                    } catch (InterruptedException | BrokenBarrierException e) {
                        // Przetwarzamy wyjątek
                    }
                }
            }
        }
    }
