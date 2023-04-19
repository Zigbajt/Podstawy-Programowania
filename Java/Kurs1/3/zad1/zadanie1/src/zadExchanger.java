import java.util.concurrent.Exchanger;

public class zadExchanger {
    public static void main(String[] args) {
        Exchanger<String> exchanger = new Exchanger<>();

        Thread thread1 = new Thread(new Runnable() {
            @Override
            public void run() {
                for(int i=0;i<2;i++){
                    try {
                        String data = "Dane wątku 1";
                        String data1 = exchanger.exchange(data);
                        System.out.println("Wątek 1 otrzymał: " + data1);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        });

        Thread thread2 = new Thread(new Runnable() {
            @Override
            public void run() {
                for(int i=0;i<2;i++){
                    try {
                        String data = "Dane wątku 2";
                        String data1 = exchanger.exchange(data);
                        Thread.sleep(100);
                        System.out.println("Wątek 2 otrzymał: " + data1);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        });

        thread1.start();
        thread2.start();
    }
}
