/*CREATE DATABASE straz;*/

CREATE TABLE zgloszenie(
	id_zgloszenie NUMBER(5) NOT NULL,
	rodzaj VARCHAR2(25),
	miejscowosc VARCHAR2(30) NOT NULL,
	ulica VARCHAR2(30) NOT NULL,
	nr_posesji VARCHAR2(4),
	PRIMARY KEY(id_zgloszenie)
);
CREATE TABLE zglaszajacy(
	id_zglaszajacy NUMBER(5) NOT NULL,
	imie VARCHAR2(25),
	nazwisko VARCHAR2(25),
	nr_telefonu NUMBER(9),
	id_zgloszenie NUMBER(5) NOT NULL,
	PRIMARY KEY(id_zglaszajacy),
	CONSTRAINT fk_id_zglaszajacy_zgloszenie
	FOREIGN KEY(id_zgloszenie)
	REFERENCES zgloszenie(id_zgloszenie)
);
CREATE TABLE dyspozytor(
	id_dyspozytor NUMBER(5) NOT NULL,
	imie VARCHAR2(25) NOT NULL,
	nazwisko VARCHAR2(25) NOT NULL,
	nr_stanowiska NUMBER(3),
	PRIMARY KEY(id_dyspozytor)
);
CREATE TABLE zarobki(
	id_zarobki NUMBER(5) NOT NULL,
	wysokosc NUMBER(5) NOT NULL,
	data_przelewu DATE NOT NULL,
	dodatki NUMBER(5),
	PRIMARY KEY(id_zarobki)
);	
CREATE TABLE badanie(
	id_badanie NUMBER(5) NOT NULL,
	data_rozpoczecia DATE NOT NULL,
	data_zakonczenia DATE NOT NULL,
	rodzaj_badania VARCHAR2(10) NOT NULL,
	PRIMARY KEY(id_badanie)
);
CREATE TABLE strazak(
	id_strazak NUMBER(5) NOT NULL,
	imie VARCHAR2(25) NOT NULL,
	nazwisko VARCHAR2(25) NOT NULL,
	stopien VARCHAR2(25),
	miejscowosc VARCHAR2(25) NOT NULL,
	ulica VARCHAR2(25) NOT NULL,
	nr_domu VARCHAR2(4) NOT NULL,
	id_badanie NUMBER(5) NOT NULL,
	id_zarobki NUMBER(5) NOT NULL,
	PRIMARY KEY(id_strazak),
	CONSTRAINT fk_strazak_badanie
	FOREIGN KEY(id_badanie)
	REFERENCES badanie(id_badanie),
	CONSTRAINT fk_strazak_zarobki
	FOREIGN KEY(id_zarobki)
	REFERENCES zarobki(id_zarobki)
);
CREATE TABLE badanie_techniczne(
	id_badanie_techniczne NUMBER(5) NOT NULL,
	data_rozpoczecia DATE NOT NULL,
	data_zakonczenia DATE NOT NULL,
	PRIMARY KEY(id_badanie_techniczne)
);
CREATE TABLE pojazd(
	id_pojazd NUMBER(5) NOT NULL,
	nr_rejestracyjny VARCHAR2(8) NOT NULL,
	liczba_osob NUMBER(2),
	rodzaj VARCHAR2(25),
	id_badanie_techniczne NUMBER(5) NOT NULL,
	PRIMARY KEY(id_pojazd),
	CONSTRAINT fk_id_pojazd_badanie_techniczne
	FOREIGN KEY(id_badanie_techniczne)
	REFERENCES badanie_techniczne(id_badanie_techniczne)
);
CREATE TABLE jednostka(
	id_jednostka NUMBER(5) NOT NULL,
	id_pojazd NUMBER(5) NOT NULL,
	id_strazak NUMBER(5) NOT NULL,
	PRIMARY KEY(id_jednostka),
	CONSTRAINT fk_id_jedkostka_pojazd
	FOREIGN KEY(id_pojazd)
	REFERENCES pojazd(id_pojazd),
	CONSTRAINT fk_jednostka_strazak
	FOREIGN KEY(id_strazak)
	REFERENCES strazak(id_strazak)
);
CREATE TABLE akcja(
	id_akcja NUMBER(5) NOT NULL,
	id_zgloszenie NUMBER(5) NOT NULL,
	id_dyspozytor NUMBER(5) NOT NULL,
	id_jednostka NUMBER(5) NOT NULL,
	PRIMARY KEY(id_akcja),
	CONSTRAINT fk_akcja_zgloszenie
	FOREIGN KEY(id_zgloszenie)
	REFERENCES zgloszenie(id_zgloszenie),
	CONSTRAINT fk_akcja_dyspozytor
	FOREIGN KEY(id_dyspozytor)
	REFERENCES dyspozytor(id_dyspozytor),
	CONSTRAINT fk_id_akcja_jednostka
	FOREIGN KEY(id_jednostka)
	REFERENCES jednostka(id_jednostka)
);