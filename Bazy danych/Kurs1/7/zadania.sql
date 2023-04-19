/*Zadania1*/
SELECT * FROM Zlecenie;
/*Zadania2*/
SELECT Zlecenie.ID_Uslugi,COUNT(Zlecenie.ID_Uslugi) AS ilosc FROM Zlecenie GROUP BY Zlecenie.ID_Uslugi ORDER BY ilosc DESC;
SELECT Usluga.ID_Uslugi,Usluga.Cena FROM Zlecenie,Usluga Where Usluga.ID_Uslugi=2 OR Usluga.ID_Uslugi=3;
UPDATE Usluga Set Usluga.Cena=Usluga.Cena*130/100 Where Usluga.ID_Uslugi=2 OR Usluga.ID_Uslugi=3;
SELECT Usluga.ID_Uslugi,Usluga.Cena FROM Zlecenie,Usluga Where Usluga.ID_Uslugi=2 OR Usluga.ID_Uslugi=3;
/*Zadania3*/
Zadanie 3
UPDATE Usluga SET Cena=Cena+Cena*dbms_random.value(10,30)/100;
/*Zadania4*/
SELECT Pracownik.*,Adres.*,Stanowisko.* FROM Pracownik,Adres,Osoba,Stanowisko,Zlecenie WHERE Pracownik.ID_stanowiska=Stanowisko.ID_stanowiska AND Osoba.ID_osoby=Pracownik.ID_osoby AND Osoba.ID_adres=Adres.ID_adres AND Stanowisko.ID_stanowiska=Pracownik.ID_stanowiska AND Zlecenie.ID_pracownika=Pracownik.ID_pracownika;
/*Zadania5*/
Zadanie 5
SELECT Osoba.Imie,Osoba.Nazwisko,Osoba.Wiek,Stanowisko.Nazwa,Adres.Miasto,Adres.Ulica,Adres.Nr FROM Pracownik,Osoba,Adres,Stanowisko WHERE 
/*Zadania6*/
Zadanie 6
SELECT Usluga.Opis FROM Usluga,Zlecenie WHERE Usluga.Cena > (SELECT AVG(Cena) FROM Usluga) GROUP BY Opis
/*Zadania9*/
SELECT Osoba.Imie,Osoba.Nazwisko,Osoba.Wiek,Osoba.Stan_cywilny,Osoba.Telefon,Osoba.Pesel FROM Klient,Osoba,Zlecenie WHERE 
/*Zadania8*/
SELECT Zlecenie.Data_zlozenia,COUNT(Zlecenie.Data_zlozenia) as ilosc FROM Zlecenie GROUP BY Zlecenie.Data_zlozenia ORDER BY Zlecenie.Data_zlozenia;
/*Zadania10*/
SELECT Klient.Znizka From Klient WHERE Klient.Znizka> ANY(SELECT Klient.Znizka From Klient WHERE Klient.ID_Klienta=2 OR Klient.ID_Klienta=3);