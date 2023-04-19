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
CREATE TABLE jednostka(
	id_jednostka NUMBER(5) NOT NULL,
	miejscowosc VARCHAR2(25) NOT NULL,
	ulica VARCHAR2(25) NOT NULL,
	numer_posesji VARCHAR2(25) NOT NULL,
	PRIMARY KEY(id_jednostka)
);
CREATE TABLE strazak(
	id_strazak NUMBER(5) NOT NULL,
	imie VARCHAR2(25) NOT NULL,
	nazwisko VARCHAR2(25) NOT NULL,
	stopien VARCHAR2(25),
	wiek NUMBER(2) NOT NULL,
	miejscowosc VARCHAR2(25) NOT NULL,
	ulica VARCHAR2(25) NOT NULL,
	nr_domu VARCHAR2(4) NOT NULL,
	id_jednostka NUMBER(5) NOT NULL,
	CHECK(wiek>=18),
	PRIMARY KEY(id_strazak),
	CONSTRAINT fk_id_strazak_jednostka
	FOREIGN KEY(id_jednostka)
	REFERENCES jednostka(id_jednostka)
);
CREATE TABLE pojazd(
	id_pojazd NUMBER(5) NOT NULL,
	nr_rejestracyjny VARCHAR2(8) NOT NULL UNIQUE,
	liczba_osob NUMBER(2),
	rodzaj VARCHAR2(25),
	id_jednostka NUMBER(5) NOT NULL,
	PRIMARY KEY(id_pojazd),
	CONSTRAINT fk_id_pojazd_jednostka
	FOREIGN KEY(id_jednostka)
	REFERENCES jednostka(id_jednostka)
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