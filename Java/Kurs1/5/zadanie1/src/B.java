import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveAction;

public class B extends RecursiveAction {
    private int[] tab;
    private int poczatek;
    private int koniec;

    public B(int[] t, int p, int k) {
        this.tab = t;
        this.poczatek = p;
        this.koniec = k;
    }

    @Override
    protected void compute() {
        if (koniec - poczatek < 2) {
            return;
        }

        int srodek = (poczatek + koniec) / 2;
        B l = new B(tab, poczatek, srodek);
        B p = new B(tab, srodek, koniec);

        l.fork();
        p.compute();
        l.join();

        merge(poczatek, srodek, koniec);
    }

    private void merge(int start, int srodek, int koniec) {
        int[] temp = new int[koniec - start];
        int i = start, j = srodek, k = 0;

        while (i < srodek && j < koniec) {
            if (tab[i] <= tab[j]) {
                temp[k++] = tab[i++];
            } else {
                temp[k++] = tab[j++];
            }
        }

        while (i < srodek) {
            temp[k++] = tab[i++];
        }

        while (j < koniec) {
            temp[k++] = tab[j++];
        }

        System.arraycopy(temp, 0, tab, start, koniec - start);
    }

    public static void main(String[] args) {
        int[] tab = {1, 21, 33, 4, 12, 3, 1, 7, 16};
        ForkJoinPool fork = new ForkJoinPool();
        B watekB = new B(tab, 0, tab.length);
        fork.invoke(watekB);
        for (int i : tab) {
            System.out.print(i + " ");
        }
    }
}
