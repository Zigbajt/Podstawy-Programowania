DROP TABLE zaliczenie;
DROP TABLE przedmiot;
DROP TABLE wykladowca;
DROP TABLE student;

CREATE TABLE przedmiot(
	id_przed NUMBER(3,0) NOT NULL PRIMARY KEY,
	nazwa VARCHAR2(15) NOT NULL,
	typ VARCHAR2(15) NOT NULL
);
CREATE TABLE student(
	nr_albumu NUMBER(3,0) NOT NULL PRIMARY KEY,
	nazwisko VARCHAR2(15) NOT NULL,
	imie VARCHAR2(15) NOT NULL,
	wiek NUMBER(3,0) NOT NULL,
	grupa VARCHAR2(15) NOT NULL
);
CREATE TABLE wykladowca(
	nr_wykl NUMBER(3,0) NOT NULL PRIMARY KEY,
	nazwisko VARCHAR2(15) NOT NULL,
	imie VARCHAR2(15) NOT NULL,
	stopen VARCHAR2(15) NOT NULL
);
CREATE TABLE zaliczenie(
	id_zaliczenie NUMBER(3,0) NOT NULL PRIMARY KEY,
	id_przed NUMBER(3,0) NOT NULL,
	nr_albumu NUMBER(3,0) NOT NULL,
	nr_wykl NUMBER(3,0) NOT NULL,
	ocena NUMBER(1),
	termin VARCHAR2(15) NOT NULL,
	data_zaliczenia DATE,
	CONSTRAINT "fk_id_przed_przedmiot_id_przed"
	FOREIGN KEY(id_przed)
	REFERENCES przedmiot(id_przed),
	CONSTRAINT "fk_nr_albumu_student_nr_albumu"
	FOREIGN KEY(nr_albumu)
	REFERENCES student(nr_albumu),
	CONSTRAINT "fk_nr_wykl_wykladowca_nr_wykl"
	FOREIGN KEY(nr_wykl)
	REFERENCES wykladowca(nr_wykl)
);