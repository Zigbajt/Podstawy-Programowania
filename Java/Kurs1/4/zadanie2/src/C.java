import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

class DaneC {
    private int zmienna;
    private ReentrantReadWriteLock lock = new ReentrantReadWriteLock();
    private Lock czLock = lock.readLock();
    private Lock pLock = lock.writeLock();
    public int pobierz() {
        czLock.lock();
        try {
            return zmienna;
        } finally {
            czLock.unlock();
        }
    }

    public void ustaw(int value) {
        pLock.lock();
        try {
            zmienna = value;
        } finally {
            pLock.unlock();
        }
    }
}

class CzytelnikC extends Thread {
    private DaneC wiadomosc;
    public CzytelnikC(DaneC w) {
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

class PisarzC extends Thread {
    private DaneC wiadomosc;
    public PisarzC(DaneC w) {
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

public class C {
    public static void main(String[] args) {
        DaneC dane_c = new DaneC();
        CzytelnikC czytelnik_c1 = new CzytelnikC(dane_c);
        CzytelnikC czytelnik_c2 = new CzytelnikC(dane_c);
        PisarzC pisarz_c = new PisarzC(dane_c);
        czytelnik_c1.start();
        czytelnik_c2.start();
        pisarz_c.start();
    }
}
