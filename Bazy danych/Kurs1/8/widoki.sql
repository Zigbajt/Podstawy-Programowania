---zad 1------
CREATE SEQUENCE osoba_seq INCREMENT BY 1 START WITH 21;
CREATE SEQUENCE adres_seq INCREMENT BY 1 START WITH 16;
CREATE SEQUENCE pracownik_seq INCREMENT BY 1 START WITH 7;
CREATE SEQUENCE stanowisko_seq INCREMENT BY 1 START WITH 5;


INSERT INTO Adres
VALUES(adres_seq.nextval,'Warszawa','Polowa','56/9');

INSERT INTO Osoba 
VALUES(osoba_seq.nextval,'Ariannaa','Grande',26,'wolna','+48(41)251-56-37','99999822796',adres_seq.currval);

INSERT INTO Stanowisko
VALUES (stanowisko_seq.nextval, 'PREZES','PREZES');

INSERT INTO Pracownik 
VALUES(pracownik_seq.nextval,osoba_seq.currval,stanowisko_seq.currval,6,4500);





---- zad 2 ----------------------------------
CREATE OR REPLACE FORCE VIEW zadanie2_A AS SELECT * FROM Zlecenie ;

CREATE OR REPLACE VIEW zadanie2_B AS SELECT * FROM Zlecenie WITH READ ONLY;

CREATE OR REPLACE VIEW zadanie2_C AS SELECT * FROM Zlecenie WITH CHECK OPTION;

SELECT * FROM zadanie2_A;
SELECT * FROM zadanie2_B;
SELECT * FROM zadanie2_C;



----zad 3-----------------------------------------
CREATE OR REPLACE VIEW zadanie_3 AS SELECT SUM(U.Cena) as Suma,U.Opis FROM Usluga U JOIN Zlecenie Z ON U.ID_Uslugi=Z.ID_Uslugi WHERE Z.Data_zlozenia
BETWEEN (SELECT sysdate-7 FROM dual) AND (SELECT sysdate FROM dual)  GROUP BY Opis  FETCH FIRST 1 ROW ONLY;

SELECT * FROM zadanie_3;

--ZAD 4------------------------------------------------

CREATE OR REPLACE VIEW zadanie_4 AS
SELECT UNIQUE Osoba.*,Usluga.Opis  FROM Pracownik ,Usluga ,Zlecenie,Osoba  WHERE Osoba.ID_Osoby=Pracownik.ID_Pracownika AND Pracownik.ID_Pracownika=Zlecenie.ID_pracownika AND Usluga.ID_Uslugi=Zlecenie.ID_Uslugi AND Usluga.Opis=(
SELECT U.Opis FROM Usluga U JOIN Zlecenie Z ON U.ID_Uslugi=Z.ID_Uslugi 
JOIN Pracownik Pr ON Pr.ID_pracownika=Z.ID_pracownika GROUP BY Opis ORDER BY COUNT(Z.ID_Uslugi) OFFSET 0 ROWS FETCH NEXT 1 ROWS ONLY);


SELECT * FROM zadanie_4;

--ZAD 5--------------------------------------
CREATE OR REPLACE VIEW zadanie_5 AS SELECT Ad.Miasto, SUM(Us.Cena)as Zarobki_ze_zlecen FROM Zlecenie Zl JOIN Usluga Us ON Zl.ID_Uslugi=Us.ID_Uslugi
JOIN Pracownik Pr ON Zl.ID_pracownika=Pr.ID_pracownika JOIN Osoba Os ON Pr.ID_osoby=Os.ID_osoby 
JOIN Adres Ad ON Os.ID_adres=Ad.ID_adres GROUP BY Ad.Miasto ORDER BY Zarobki_ze_zlecen desc;

SELECT * FROM zadanie_5;

--ZAD 6--------------------------------------
CREATE OR REPLACE VIEW zad_6 AS
SELECT Osoba.* FROM Osoba WHERE Osoba.ID_Osoby=
(SELECT Osoba.ID_Osoby
FROM Osoba,Klient,Zlecenie,Usluga 
WHERE Osoba.ID_osoby=Klient.ID_osoby AND Klient.ID_klienta=Zlecenie.ID_klienta 
AND Usluga.ID_Uslugi=Zlecenie.ID_Uslugi AND Zlecenie.Data_zlozenia>= SYSDATE-7 
AND Zlecenie.Data_zlozenia< SYSDATE GROUP BY Osoba.ID_Osoby 
ORDER BY SUM(Usluga.cena) desc OFFSET 0 ROWS FETCH NEXT 1 ROWS ONLY) OR OSOBA.ID_Osoby=
(SELECT Osoba.ID_Osoby
FROM Osoba,Klient,Zlecenie,Usluga 
WHERE Osoba.ID_osoby=Klient.ID_osoby AND Klient.ID_klienta=Zlecenie.ID_klienta 
AND Usluga.ID_Uslugi=Zlecenie.ID_Uslugi AND Zlecenie.Data_zlozenia>= SYSDATE-7 
AND Zlecenie.Data_zlozenia< SYSDATE GROUP BY Osoba.ID_Osoby 
ORDER BY SUM(Usluga.cena) desc OFFSET 1 ROWS FETCH NEXT 1 ROWS ONLY);

SELECT * FROM zad_6;


--ZAD 7--------------------------------------
CREATE SEQUENCE zlecenie_seq INCREMENT BY 1 START WITH 30;
INSERT INTO Zlecenie
VALUES(zlecenie_seq.NEXTVAL,1,5,6,SYSDATE);


--ZAD 7--------------------------------------
CREATE SEQUENCE zlecenie_seq INCREMENT BY 1 START WITH 30;
INSERT INTO Zlecenie
VALUES(zlecenie_seq.NEXTVAL,1,5,6,SYSDATE);

