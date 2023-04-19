import java.util.concurrent.atomic.AtomicInteger;

class DaneA {
    private AtomicInteger zmienna = new AtomicInteger();
    public int pobierz() {
        return zmienna.get();
    }

    public void ustaw(int value) {
        zmienna.set(value);
    }
}

class CzytelnikA extends Thread {
    private DaneA wiadomosc;
    public CzytelnikA(DaneA w) {
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

class PisarzA extends Thread {
    private DaneA wiadomosc;
    public PisarzA(DaneA w) {
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

public class A {
    public static void main(String[] args) {
        DaneA dane_a = new DaneA();
        CzytelnikA czytelnik_a1 = new CzytelnikA(dane_a);
        CzytelnikA czytelnik_a2 = new CzytelnikA(dane_a);
        PisarzA pisarz_a = new PisarzA(dane_a);
        czytelnik_a1.start();
        czytelnik_a2.start();
        pisarz_a.start();
    }
}