import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

public class Symulator {
    private static BlockingQueue<String> info = new LinkedBlockingQueue<>();

    public static void main(String[] args) {
        int z=1;
        System.out.println("Podaj liczbe Mieszkan:");
        Scanner odczyt = new Scanner(System.in);
        int ilosc = odczyt.nextInt();

        System.out.println("Podaj prawdopodobieństwo wykrycia awarii:");
        Scanner odczyt1 = new Scanner(System.in);
        double praw = odczyt1.nextDouble();

        System.out.println("Podaj czas sprawdza stan swojego mieszkania w ms:");
        Scanner odczyt2 = new Scanner(System.in);
        int slep = odczyt2.nextInt();

        Thread tab[]=new Thread[ilosc];
        System.out.println("Start:");
        for(int i=0;i<ilosc;i++){
            tab[i] = new Thread(new Mieszkanie("Mieszkanie "+z,praw,slep));
            z++;
        }
        Thread k = new Thread(new Konserwator());
        for(int j=0;j<ilosc;j++){
            tab[j].start();
        }
        k.start();
    }
    static class Mieszkanie implements Runnable {
        String name;
        double pre;
        int slep;
        Random random = new Random();

        Mieszkanie(String name,double p,int s) {
            this.name = name;
            this.pre = p;
            this.slep=s;

        }
        @Override
        public void run() {
            while (true) {
                try {
                    if (random.nextDouble() < pre) {
                        info.put(name + ": awaria");
                        System.out.println(name + ": zgłoszono awarię");
                    }
                    Thread.sleep(slep);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
    static class Konserwator implements Runnable {
        Random random = new Random();
        @Override
        public void run() {
            while (true) {
                try {
                    String tekst = info.take();
                    System.out.println("Konserwator: otrzymał zgłoszenie od " + tekst);

                    Thread.sleep(random.nextInt(4000) + 1000);
                    System.out.println("Konserwator: naprawił awarię w " + tekst);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

