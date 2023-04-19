SELECT Osoba.Imie, Osoba.Nazwisko, Osoba.Wiek From Osoba;
SELECT Osoba.Imie, Osoba.Nazwisko, Osoba.Telefon FROM Osoba ORDER BY Osoba.Nazwisko ASC;
SELECT Osoba.Imie, Osoba.Nazwisko, Osoba.Wiek FROM Osoba WHERE Osoba.Wiek<40;

SELECT Osoba.Imie, Osoba.Nazwisko, Osoba.Wiek FROM Osoba WHERE Osoba.Wiek<40 AND Osoba.Wiek>30;
SELECT Osoba.Imie, Osoba.Nazwisko, Osoba.Wiek FROM Osoba WHERE Osoba.Wiek BETWEEN 30 AND 40;

SELECT Osoba.Imie, Osoba.Nazwisko, Osoba.Pesel AS "Numer identyfikacyjny" FROM osoba;
SELECT Osoba.Imie, Osoba.Nazwisko FROM osoba WHERE osoba.nazwisko NOT LIKE 'P%' AND osoba.nazwisko NOT LIKE 'R%' AND osoba.nazwisko NOT LIKE 'S%';
SELECT Osoba.id_Osoby AS "Identyfikator", Osoba.Imie AS "IM", Osoba.Nazwisko AS "NA", Osoba.Wiek AS "WI", Osoba.Stan_cywilny AS "S_c", Osoba.Telefon AS "TEL", Osoba.Pesel AS "PES" FROM Osoba WHERE Osoba.Wiek>30 AND Osoba.Telefon IS NULL ORDER BY Osoba.Nazwisko ASC;
SELECT Adres.Ulica FROM Adres WHERE Adres.Miasto='Kielce';
SELECT Osoba.Imie, Osoba.Nazwisko, Adres.Miasto FROM Osoba,Adres WHERE Osoba.ID_adres=Adres.ID_adres AND Adres.Miasto!='Kielce';
SELECT TO_DATE('20211001','yyyymmdd') AS "Data rozpoczecia roku akademickiego", SYSDATE AS "Dzisiejsza data" FROM Zlecenie;
Select Osoba.Imie, Osoba.Nazwisko, Osoba.Telefon FROM Osoba WHERE Osoba.Telefon LIKE '%' ORDER BY Osoba.Imie DESC;
SELECT SYSDATE -91290 AS "Data - nr. indeksu" FROM Osoba;