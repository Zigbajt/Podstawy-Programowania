CREATE OR REPLACE PROCEDURE zad1 IS
Nazwa VARCHAR2(30):='Osoba_k';
BEGIN
	EXECUTE IMMEDIATE 'CREATE TABLE '||Nazwa||'(
		ID_osoby_k NUMBER,
		Imie_k VARCHAR2(15) NOT NULL,
		Nazwisko_k VARCHAR2(30) NOT NULL,
		Wiek_k NUMBER NOT NULL,
		Stan_cywilny_k VARCHAR2(12) NOT NULL,
		Telefon_k VARCHAR2(20),
		Pesel_k CHAR(11) NOT NULL ,
		ID_adres_k NUMBER NOT NULL
	)';
	EXECUTE IMMEDIATE 'INSERT INTO '||Nazwa||' SELECT * FROM Osoba';
END;
/

EXEC zad1;
select * from Osoba_k;

-------------------------//////////////////----------------------------------------
/*
CREATE OR REPLACE PROCEDURE stworz_kopie(Nazwa IN VARCHAR2)
AS
BEGIN
EXECUTE IMMEDIATE 'CREATE TABLE '||Nazwa||'(
		ID_osoby_k NUMBER,
		Imie_k VARCHAR2(15) NOT NULL,
		Nazwisko_k VARCHAR2(30) NOT NULL,
		Wiek_k NUMBER NOT NULL,
		Stan_cywilny_k VARCHAR2(12) NOT NULL,
		Telefon_k VARCHAR2(20),
		Pesel_k CHAR(11) NOT NULL ,
		ID_adres_k NUMBER NOT NULL
	)';
END;
/
CREATE OR REPLACE PROCEDURE usun_kopie(Nazwa IN VARCHAR2)
AS
BEGIN
EXECUTE IMMEDIATE 'DROP TABLE '||Nazwa||' CASCADE CONSTRAINTS';
END;
/
CREATE OR REPLACE PROCEDURE wypelnij(Nazwa IN VARCHAR2)
AS
BEGIN
EXECUTE IMMEDIATE 'INSERT INTO '||Nazwa||'
	SELECT * FROM Osoba';
END;
/
CREATE OR REPLACE TRIGGER AIUD_Kopia
AFTER INSERT OR UPDATE OR DELETE
ON Osoba
FOR EACH ROW
DECLARE
BEGIN
	EXEC usun_kopie(Osoba_kopia);
	EXEC stworz_kopie(Osoba_kopia);
	EXEC wypelnij(Osoba_kopia);
END;
/
*/
---zad2---

CREATE TABLE Wpis (
Wydarzenie_Data Date,
Typ VARCHAR2(20),
Names VARCHAR2(20),

Old_id_zlecenia NUMBER,
Old_id_uslugi NUMBER,
Old_id_klienta NUMBER,
Old_id_pracownika NUMBER ,
Old_data_zlozenia DATE ,

New_id_zlecenia NUMBER,
New_id_uslugi NUMBER,
New_id_klienta NUMBER,
New_id_pracownika NUMBER,
New_data_zlozenia DATE
);

CREATE OR REPLACE TRIGGER AIUD_wpis
AFTER INSERT OR UPDATE OR DELETE
ON Zlecenie
FOR EACH ROW
DECLARE
BEGIN
		INSERT INTO Wpis
		(
			Wydarzenie_Data,
			Typ,
			Names,
			Old_id_zlecenia,
			Old_id_uslugi,
			Old_id_klienta,
			Old_id_pracownika,
			Old_data_zlozenia,
			New_id_zlecenia,
			New_id_uslugi,
			New_id_klienta,
			New_id_pracownika,
			New_data_zlozenia
		)
		VALUES
		(
			SYSDATE,
			'INSERT',
			'user',
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			:NEW.ID_Zlecenia,
			:NEW.ID_Uslugi,
			:NEW.ID_klienta,
			:NEW.ID_pracownika,
			:NEW.Data_zlozenia
		);
END;
/
/*
CREATE TABLE Wpis (
Wydarzenie_Data Date,
Typ VARCHAR2(20),
Names VARCHAR2(20),

Old_id_zlecenia NUMBER,
Old_id_uslugi NUMBER,
Old_id_klienta NUMBER,
Old_id_pracownika NUMBER ,
Old_data_zlozenia DATE ,

New_id_zlecenia NUMBER,
New_id_uslugi NUMBER,
New_id_klienta NUMBER,
New_id_pracownika NUMBER,
New_data_zlozenia DATE
);

CREATE OR REPLACE TRIGGER AIUD_wpis
AFTER INSERT OR UPDATE OR DELETE
ON Zlecenie
FOR EACH ROW
DECLARE
BEGIN
	CASE
	WHEN INSERTING THEN
		INSERT INTO Wpis
		(
			Wydarzenie_Data,
			Typ,
			Names,
			Old_id_zlecenia,
			Old_id_uslugi,
			Old_id_klienta,
			Old_id_pracownika,
			Old_data_zlozenia,
			New_id_zlecenia,
			New_id_uslugi,
			New_id_klienta,
			New_id_pracownika,
			New_data_zlozenia
		)
		VALUES
		(
			SYSDATE,
			'INSERT',
			'user',
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			:NEW.ID_Zlecenia,
			:NEW.ID_Uslugi,
			:NEW.ID_klienta,
			:NEW.ID_pracownika,
			:NEW.Data_zlozenia
		);
	WHEN UPDATING THEN
		INSERT INTO Wpis
		(
			Wydarzenie_Data,
			Typ,
			Names,
			Old_id_zlecenia,
			Old_id_uslugi,
			Old_id_klienta,
			Old_id_pracownika,
			Old_data_zlozenia,
			New_id_zlecenia,
			New_id_uslugi,
			New_id_klienta,
			New_id_pracownika,
			New_data_zlozenia
		)
		VALUES
		(
			SYSDATE,
			'UPDATE',
			'user',
			:OLD.ID_Zlecenia,
			:OLD.ID_Uslugi,
			:OLD.ID_klienta,
			:OLD.ID_pracownika,
			:OLD.Data_zlozenia
			:NEW.ID_Zlecenia,
			:NEW.ID_Uslugi,
			:NEW.ID_klienta,
			:NEW.ID_pracownika,
			:NEW.Data_zlozenia
		);
	WHEN DELETING THEN
		INSERT INTO Wpis
		(
			Wydarzenie_Data,
			Typ,
			Names,
			Old_id_zlecenia,
			Old_id_uslugi,
			Old_id_klienta,
			Old_id_pracownika,
			Old_data_zlozenia,
			New_id_zlecenia,
			New_id_uslugi,
			New_id_klienta,
			New_id_pracownika,
			New_data_zlozenia
		)
		VALUES
		(
			SYSDATE,
			'UPDATE',
			'user',
			:OLD.ID_Zlecenia,
			:OLD.ID_Uslugi,
			:OLD.ID_klienta,
			:OLD.ID_pracownika,
			:OLD.Data_zlozenia
			NULL,
			NULL,
			NULL,
			NULL,
			NULL
		);
	END CASE;
END;
/
*/

---Zad3---
CREATE OR REPLACE TRIGGER AU_osoba
AFTER DELETE ON Osoba
FOR EACH ROW
DECLARE
BEGIN

	DELETE FROM Pracownik WHERE ID_osoby=:OLD.ID_osoby;
	DELETE FROM Klient WHERE ID_osoby=:OLD.ID_osoby;
END;
/
Select * from Osoba WHERE ID_osoby=1;
DELETE FROM Osoba WHERE ID_osoby=1;
Select * from Pracownik;
Select * from Klient;


CREATE OR REPLACE TRIGGER AU_osoba
BEFORE DELETE ON Osoba
FOR EACH ROW
DECLARE
    id_k NUMBER;
    id_p NUMBER;
BEGIN
    Select ID_pracownika into id_p from Pracownik WHERE ID_osoby=:OLD.ID_osoby;
    Select ID_klienta into id_k from Klient WHERE ID_osoby=:OLD.ID_osoby;
	dbms_output.put_line('ID_pracownika'||id_p);
	dbms_output.put_line('ID_klienta'||id_k);
    IF id_p IS NOT NULL THEN
	DELETE FROM Pracownik WHERE ID_pracownika=id_p;
	ELSIF id_k IS NOT NULL THEN
	DELETE FROM Klient WHERE ID_klienta=id_k;
	ELSE
	dbms_output.put_line('Nie było NIC');
	END IF;
END;
/
Select * from Osoba WHERE ID_osoby=1;
--Select * from Osoba;
DELETE FROM Osoba WHERE ID_osoby=1;
Select ID_pracownika  from Pracownik WHERE ID_osoby=1;
Select ID_klienta from Klient WHERE ID_osoby=1;
---Select * from Pracownik;
---Select * from Klient;


-----zad4-------
/*
SELECT count(Pracownik.ID_pracownika) As Ilosc,Stanowisko.Nazwa From Pracownik,Stanowisko WHERE Stanowisko.ID_stanowiska=Pracownik.ID_stanowiska  group by Stanowisko.Nazwa;
CREATE TABLE Iloscstanowisko (
ID_iloscstanowiska NUMBER PRIMARY KEY,
Nazwa VARCHAR2(20),
ilosc Number
);

CREATE OR REPLACE TRIGGER zad4
AFTER INSERT OR UPDATE
ON Pracownik
FOR EACH ROW
DECLARE
ilosc number:=0;
nazwa varchar2(50);
BEGIN
SELECT count(Pracownik.ID_pracownika) into ilosc From Pracownik,Stanowisko WHERE Stanowisko.ID_stanowiska=Pracownik.ID_stanowiska  group by Stanowisko.Nazwa;
SELECT Stanowisko.Nazwa into nazwa From Pracownik,Stanowisko WHERE Stanowisko.ID_stanowiska=Pracownik.ID_stanowiska  group by Stanowisko.Nazwa;
dbms_output.put_line('ID_pracownika'||ilosc);
dbms_output.put_line('ID_klienta'||nazwa);
END;
/
*/

SELECT count(Pracownik.ID_pracownika) As Ilosc,Stanowisko.Nazwa From Pracownik,Stanowisko WHERE Stanowisko.ID_stanowiska=Pracownik.ID_stanowiska  group by Stanowisko.Nazwa;

CREATE OR REPLACE TRIGGER zad4
AFTER INSERT OR UPDATE
ON Pracownik
FOR EACH ROW
DECLARE
CURSOR grupy IS SELECT count(Pracownik.ID_pracownika) As Ilosc,Stanowisko.Nazwa As NN From Pracownik,Stanowisko WHERE Stanowisko.ID_stanowiska=Pracownik.ID_stanowiska  group by Stanowisko.Nazwa;
iter NUMBER :=1;
BEGIN
 FOR tmp IN grupy LOOP
 DELETE FROM Iloscstanowisko WHERE ID_iloscstanowiska=iter;
 INSERT INTO Iloscstanowisko VALUES(iter,tmp.Nazwa,tmp.Ilosc);
 dbms_output.put_line('Nr : '||iter);
 dbms_output.put_line('Ilosc : '||tmp.Ilosc);
 dbms_output.put_line('Stanowisko : '||tmp.NN);
 iter:=iter+1;
 END LOOP;
END;
/

---INSERT INTO Pracownik VALUES(7,5,2,5,5000);

---zad5-----
SELECT count(Pracownik.ID_pracownika) As Ilosc,Stanowisko.Nazwa From Pracownik,Stanowisko WHERE Stanowisko.ID_stanowiska=Pracownik.ID_stanowiska AND Stanowisko.Nazwa ='DYREKTOR' group by Stanowisko.Nazwa;

CREATE OR REPLACE TRIGGER zad5
AFTER INSERT OR UPDATE
ON Pracownik
FOR EACH ROW
DECLARE
 ilosc number:=0;
BEGIN
 SELECT count(Pracownik.ID_pracownika) into ilosc From Pracownik,Stanowisko WHERE Stanowisko.ID_stanowiska=Pracownik.ID_stanowiska AND Stanowisko.Nazwa ='DYREKTOR' group by Stanowisko.Nazwa;
 IF ilosc>1 THEN
    dbms_output.put_line('Nie mozna dodać dyrektora : '||ilosc);
	DELETE FROM Pracownik WHERE  ID_stanowiska=:NEW.ID_stanowiska;
 ELSE
	dbms_output.put_line('Dodano Dyrektora : '||ilosc);
 END IF;
END;
/

---INSERT INTO Pracownik VALUES(1,7,1,9,9000);

---zad6----


CREATE OR REPLACE VIEW zad6 AS SELECT ID_Uslugi ,ID_klienta ,ID_pracownika ,Data_zlozenia FROM Zlecenie;

SELECT * FROM zad6;
CREATE SEQUENCE sek INCREMENT BY 1 START WITH 31;
CREATE OR REPLACE TRIGGER wyzwalacz
INSTEAD OF INSERT ON zad6
DECLARE
wartosc NUMBER;
BEGIN
SELECT sek.currval INTO wartosc from dual;
END;
/
INSERT INTO Zlecenie VALUES(sek.nextval,2,11,6,(SELECT sysdate - round(dbms_random.value(1,10)) as "data" from dual));
declare
x number;
begin
SELECT sek.currval into x FROM dual;
DBMS_OUTPUT.PUT_LINE('Wartosc ID zlecenia: '||x);
end;

















