import java.util.Scanner;
class Prostokat {
    private final double x;
    private final double y;
    private final double Bx;
    private final double By;
    private final double width;
    private final double height;

    public Prostokat(double x, double y, double width, double height) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.Bx = x+width;
        this.By = y+height;
    }
    public Prostokat obroc(int liczba) {
        // obróć prostokąt o wielokrotność 90 stopni
        if (liczba % 90 != 0) {
            throw new IllegalArgumentException("liczba musi być obrocona o 90");
        }
        double NewBy = height;
        double NewBx = width;
        if (liczba % 360 == 90 || liczba % 360 == 270) {
            NewBy = height;
            NewBx = width;
        }
        return new Prostokat(y, x, NewBy, NewBx);
    }
    public Prostokat rozciagnij(double liczba) {
        // rozciągnij prostokąt o podany współczynnik
        return new Prostokat(x, y, width * liczba, height * liczba);
    }
    public Prostokat przesun(double dx, double dy) {
        // przesuń prostokąt o podane odległości
        return new Prostokat(x + dx, y + dy, width + dx, height + dy);
    }
    public double getX() {
        return x;
    }
    public double getY() {
        return y;
    }
    public double getXX() {
        return Bx;
    }
    public double getYY() {
        return By;
    }
}
public class Main {
    public static void main(String[] args) {
        System.out.println("Podaj x:");
        Scanner odczyt = new Scanner(System.in);
        int x = odczyt.nextInt();
        System.out.println("Podaj y:");
        Scanner odczyt1 = new Scanner(System.in);
        int y = odczyt1.nextInt();
        System.out.println("Podaj szerokosc:");
        Scanner odczyt2 = new Scanner(System.in);
        int Width = odczyt2.nextInt();
        System.out.println("Podaj wysokosc:");
        Scanner odczyt3 = new Scanner(System.in);
        int Height = odczyt3.nextInt();
        System.out.println("Stworzony prostokąt:");
        Prostokat figura = new Prostokat(x, y, Width, Height);
        System.out.println("A(" + figura.getX() + "," + figura.getY() + ") B(" + figura.getXX() + "," + figura.getYY() + ")");
        System.out.println("Rozciągnięty prostokąt:");
        figura = figura.rozciagnij(2);
        System.out.println("A(" + figura.getX() + "," + figura.getY() + ") B(" + figura.getXX() + "," + figura.getYY() + ")");
        System.out.println("Obrócony prostokąt:");
        figura = figura.obroc(90);
        System.out.println("A(" + figura.getX() + "," + figura.getY() + ") B(" + figura.getXX() + "," + figura.getYY() + ")");
        System.out.println("Przesunięty prostokąt:");
        figura = figura.przesun(10, 10);
        System.out.println("A(" + figura.getX() + "," + figura.getY() + ") B(" + figura.getXX() + "," + figura.getYY() + ")");

        System.out.println("Koniec Programu!");
    }
}