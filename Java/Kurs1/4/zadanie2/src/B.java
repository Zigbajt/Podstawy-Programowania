import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class DaneB {
    private int zmienna;
    private Lock lock = new ReentrantLock();
    public int pobierz() {
        lock.lock();
        try {
            return zmienna;
        } finally {
            lock.unlock();
        }
    }

    public void ustaw(int value) {
        lock.lock();
        try {
            zmienna = value;
        } finally {
            lock.unlock();
        }
    }
}

class CzytelnikB extends Thread {
    private DaneB wiadomosc;
    public CzytelnikB(DaneB w) {
        this.wiadomosc = w;
    }

    public void run() {
        while (true) {
            System.out.println("Czytelnik odczytał: " + wiadomosc.pobierz());
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class PisarzB extends Thread {
    private DaneB wiadomosc;
    public PisarzB(DaneB w) {
        this.wiadomosc = w;
    }

    public void run() {
        while (true) {
            int licznik = wiadomosc.pobierz();
            wiadomosc.ustaw(licznik + 1);
            System.out.println("Pisadz zmodyfikował atrybut: " + wiadomosc.pobierz());
            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class B {
    public static void main(String[] args) {
        DaneB dane_b = new DaneB();
        CzytelnikB czytelnik_b1 = new CzytelnikB(dane_b);
        CzytelnikB czytelnik_b2 = new CzytelnikB(dane_b);
        PisarzB pisarz_b = new PisarzB(dane_b);
        czytelnik_b1.start();
        czytelnik_b2.start();
        pisarz_b.start();
    }
}
