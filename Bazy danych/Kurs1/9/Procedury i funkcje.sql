-----1.-----
CREATE SEQUENCE war INCREMENT BY 1 START WITH 15;
CREATE OR REPLACE PROCEDURE zadanie_1 (ID_osoby  NUMBER, Znizka  NUMBER)
IS
BEGIN
INSERT INTO Klient(ID_klienta , ID_osoby ,Znizka )
VALUES(war.nextval,ID_osoby,Znizka);
COMMIT;
END;
/
EXECUTE zadanie_1(17,0);

-----2.-----
CREATE OR REPLACE FUNCTION zadanie_2
RETURN NUMBER
IS
sr NUMBER;
BEGIN
SELECT AVG(U.Cena) INTO sr FROM Usluga U JOIN Zlecenie Z ON U.ID_Uslugi=Z.ID_Uslugi
WHERE Z.Data_zlozenia BETWEEN (SELECT sysdate-14 FROM dual) AND (SELECT sysdate FROM dual);
RETURN sr;
END;
/
SELECT zadanie_2 FROM DUAL;

------3.-------

CREATE SEQUENCE oso INCREMENT BY 1 START WITH 21;
CREATE SEQUENCE adr INCREMENT BY 1 START WITH 16;
CREATE OR REPLACE PROCEDURE zadanie_3 IS 
i NUMBER:=1;
j NUMBER:=1;
BEGIN
LOOP
EXIT WHEN i=4;
INSERT INTO Adres VALUES(adr.nextval, dbms_random.string('L', 10),dbms_random.string('L', 10),dbms_random.string('L', 10));
INSERT INTO Osoba VALUES(oso.nextval,dbms_random.string('L', 10),dbms_random.string('L', 10),dbms_random.value(1,90),dbms_random.string('L', 10),dbms_random.string('L', 10),dbms_random.string('L', 10),adr.currval);
i:=i+1;
END LOOP;
WHILE j<4 LOOP
INSERT INTO Adres VALUES(adr.nextval, dbms_random.string('L', 10),dbms_random.string('L', 10),dbms_random.string('L', 10));
INSERT INTO Osoba VALUES(oso.nextval,dbms_random.string('L', 10),dbms_random.string('L', 10),dbms_random.value(1,90),dbms_random.string('L', 10),dbms_random.string('L', 10),dbms_random.string('L', 10),adr.currval);
j:=j+1;
END LOOP;
FOR z IN 1..3
LOOP
INSERT INTO Adres VALUES(adr.nextval, dbms_random.string('L', 10),dbms_random.string('L', 10),dbms_random.string('L', 10));
INSERT INTO Osoba VALUES(oso.nextval,dbms_random.string('L', 10),dbms_random.string('L', 10),dbms_random.value(1,90),dbms_random.string('L', 10),dbms_random.string('L', 10),dbms_random.string('L', 10),adr.currval);
END LOOP;
END;
/
EXECUTE zadanie_3


--------zad_4------------------

CREATE SEQUENCE prac INCREMENT BY 1 START WITH 7;
CREATE SEQUENCE osob INCREMENT BY 1 START WITH 1 MAXVALUE 21;
CREATE OR REPLACE PROCEDURE zadanie_4 (tryb VARCHAR2,ID_praca NUMBER,ID_oso NUMBER,ID_stan NUMBER,Staze NUMBER,Pensje NUMBER )
IS
BEGIN
CASE tryb
WHEN 'D' THEN INSERT INTO Pracownik VALUES(prac.nextval,osob.nextval,ID_stan,Staze,Pensje);
WHEN 'A' THEN UPDATE Pracownik SET ID_stanowiska=ID_stan,Staz=Staze,Pensja=Pensje WHERE ID_pracownika=ID_praca;
WHEN 'U' THEN DELETE FROM Pracownik WHERE ID_pracownika=ID_praca;
END CASE;
END;
/

EXECUTE zadanie_4('D',17,17,3,3,7000);
--EXECUTE zadanie_4('A',2,11,2,6,1000); czasami wystepuje blad
EXECUTE zadanie_4('U',1,17,3,3,7000);

-----Zad5------------

CREATE OR REPLACE FUNCTION zad5A
RETURN Number
IS
nr NUMBER;
BEGIN
	Select ID_Zlecenia into nr From Zlecenie Order BY Data_zlozenia DESC OFFSET 0 ROWS FETCH NEXT 1 ROWS ONLY;
	return nr;
END;
/
CREATE OR REPLACE FUNCTION zad5B
RETURN Number
IS
pr NUMBER;
BEGIN
	Select ID_pracownika into pr From Zlecenie Order BY Data_zlozenia DESC OFFSET 0 ROWS FETCH NEXT 1 ROWS ONLY;
	return pr;
END;
/
CREATE OR REPLACE FUNCTION zad5C
RETURN Number
IS
kl NUMBER;
BEGIN
	Select ID_klienta into kl From Zlecenie Order BY Data_zlozenia DESC OFFSET 0 ROWS FETCH NEXT 1 ROWS ONLY;
	return kl;
END;
/
CREATE OR REPLACE FUNCTION zad5D
RETURN Date
IS
da date;
BEGIN
	Select Zlecenie.Data_zlozenia into da From Zlecenie Order BY Data_zlozenia DESC OFFSET 0 ROWS FETCH NEXT 1 ROWS ONLY;
	return da;
END;
/
DECLARE
kl NUMBER;
nr NUMBER;
pr NUMBER;
da DATE;
Begin
nr:=zad5A();
pr:=zad5B();
kl:=zad5C();
da:=zad5D();
dbms_output.put_line('NUMER zamowienia: '||nr);
dbms_output.put_line('NUMER klienta: '||kl);
dbms_output.put_line('NUMER pracownika: '||pr);
dbms_output.put_line('Data zamowienia: '||da);
dbms_output.put_line('Data obecna: '||sysdate);
dbms_output.put_line('-----------IF---------');
IF da=sysdate THEN
DBMS_OUTPUT.PUT_LINE('Zamowienie złozone dzis');
ELSIF da=(sysdate-1) THEN
DBMS_OUTPUT.PUT_LINE('Zamowienie złozone wczoraj');
ELSE
DBMS_OUTPUT.PUT_LINE('inna data');
END IF;
dbms_output.put_line('-----------CASE----------');
CASE da
WHEN sysdate THEN DBMS_OUTPUT.PUT_LINE('Zamowienie złozone dzis');
WHEN (sysdate-1) THEN DBMS_OUTPUT.PUT_LINE('Zamowienie złozone wczoraj');
ELSE DBMS_OUTPUT.PUT_LINE('inna data');
END CASE;
dbms_output.put_line('-----------CASE z wyszukiwaniem----------');
CASE
WHEN da = sysdate THEN DBMS_OUTPUT.PUT_LINE('Zamowienie złozone dzis');
WHEN da = (sysdate-1) THEN DBMS_OUTPUT.PUT_LINE('Zamowienie złozone wczoraj');
ELSE DBMS_OUTPUT.PUT_LINE('inna data');
END CASE;
dbms_output.put_line('-----------------------');
dbms_output.put_line('NUMER zamowienia: '||nr);
dbms_output.put_line('Klient:');
END;
/
Select Osoba.Imie,Osoba.Nazwisko,Adres.* From Klient,Osoba,Adres Where Klient.ID_osoby=Osoba.ID_osoby AND Osoba.ID_adres=Adres.ID_adres AND Klient.ID_klienta=(Select zad5C() from dual);
Begin
dbms_output.put_line('Pracownik:');
END;
/
Select Osoba.Imie,Osoba.Nazwisko,Adres.*,Stanowisko.Nazwa From Pracownik,Osoba,Adres,Stanowisko Where Pracownik.ID_stanowiska=Stanowisko.ID_stanowiska AND Osoba.ID_adres=Adres.ID_adres AND Pracownik.ID_osoby=Osoba.ID_osoby AND Pracownik.ID_pracownika=(Select zad5B() from dual);

-----Zad6------------


CREATE OR REPLACE PROCEDURE zad6(w1 IN VARCHAR2,w2 OUT NUMBER,W3 IN  NUMBER)
IS
BEGIN
dbms_output.put_line('Cena mniejsza od '||w1||' .Ile dni do tylu: '||w3);
Select count(Usluga.Cena) into w2 from Usluga,Zlecenie Where Usluga.ID_Uslugi=Zlecenie.ID_Uslugi AND Usluga.Cena<w1 AND Zlecenie.Data_zlozenia>Sysdate-w3;

END;
/
DECLARE
ww2 NUMBER;
ww3 NUMBER;
ww1 NUMBER;
Begin
zad6(50,ww2,5);
dbms_output.put_line('Ilosc znalezionych uslug: '||ww2);
END;
/
---LUB----

CREATE OR REPLACE PROCEDURE zad6(w1 IN VARCHAR2,w2 OUT NUMBER,W3 IN OUT NUMBER)
IS
BEGIN
dbms_output.put_line('Cena mniejsza od '||w1||' .Ile dni do tylu: '||w3);
Select count(Usluga.Cena) into w2 from Usluga,Zlecenie Where Usluga.ID_Uslugi=Zlecenie.ID_Uslugi AND Usluga.Cena<w1 AND Zlecenie.Data_zlozenia>Sysdate-w3;

END;
/
DECLARE
ww2 NUMBER;
ww3 NUMBER;
ww1 NUMBER;
Begin
zad6(50,ww2,ww3);
dbms_output.put_line('Ilosc znalezionych uslug: '||ww2);
END;
/

-----Zad7------------
CREATE OR REPLACE FUNCTION zad7(od NUMBER,do NUMBER) 
RETURN NUMBER
IS
su NUMBER;
BEGIN
	SELECT SUM(Pracownik.Pensja) into su FROM Stanowisko,Pracownik WHERE Stanowisko.ID_stanowiska=Pracownik.ID_stanowiska AND Pracownik.ID_pracownika>=od AND Pracownik.ID_pracownika<=do;
	return su;
END;
/
Select zad7(od=>1,do=>3) AS "SUMA WYPLAD DLA PRACOWNIKOW" from dual;
Select zad7(1,2) "SUMA WYPLAD DLA PRACOWNIKOW" from dual;