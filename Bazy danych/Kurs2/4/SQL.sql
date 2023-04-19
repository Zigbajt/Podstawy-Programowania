Create or replace procedure cw_01
Begin 
/* Maciejski Dawid Kyryll Levkovych Grupa 214A zespół */

--zad1 a)Podać listę przedmiotów

SELECT id_przed,nazwa 
FROM przedmiot;

--zad2 b)Wyświetlić listę studentów z grupy o nazwie „Grupa 02”.

SELECT student.nr_albumu, student.nazwisko 
FROM student,grupa 
WHERE student.nr_gr=grupa.nr_gr 
AND grupa.nazwa='Grupa 02';

SELECT student.nr_albumu, student.nazwisko 
FROM student inner join grupa on student.nr_gr=grupa.nr_gr 
where nazwa ='Grupa 02';



--zad3 c)Podać do jakie grupy należy każdy student, dane posortować według nazwy grupy. 

SELECT student.nr_albumu,student.nazwisko,student.nr_gr,grupa.nazwa 
FROM student,grupa 
WHERE student.nr_gr=grupa.nr_gr 
ORDER BY grupa.nazwa;

SELECT student.nr_albumu,student.nazwisko,student.nr_gr,grupa.nazwa 
FROM student INNER JOIN grupa ON student.nr_gr=grupa.nr_gr 
ORDER BY grupa.nazwa;

--zad4 d)Podać jaki nauczyciel uczy jakiego przedmiotu

SELECT wykladowca.nr_wykl,wykladowca.nazwisko,przedmiot.id_przed,przedmiot.nazwa 
FROM wykladowca,pro_zaj,przedmiot 
WHERE wykladowca.nr_wykl=pro_zaj.nr_wykl AND przedmiot.id_przed=pro_zaj.id_przed 
ORDER BY wykladowca.nr_wykl;

SELECT wykladowca.nr_wykl,wykladowca.nazwisko,przedmiot.id_przed,przedmiot.nazwa 
FROM wykladowca INNER JOIN pro_zaj ON wykladowca.nr_wykl = pro_zaj.nr_wykl 
INNER JOIN przedmiot ON przedmiot.id_przed=pro_zaj.id_przed 
ORDER BY wykladowca.nr_wykl;

--zad5 e)Podać jakie przedmioty prowadzi każdy nauczyciel.

SELECT wykladowca.nr_wykl,wykladowca.nazwisko,przedmiot.id_przed,przedmiot.nazwa 
FROM wykladowca,pro_zaj,przedmiot 
WHERE wykladowca.nr_wykl=pro_zaj.nr_wykl AND przedmiot.id_przed=pro_zaj.id_przed 
ORDER BY wykladowca.nr_wykl,przedmiot.nazwa; 

SELECT wykladowca.nr_wykl,wykladowca.nazwisko,przedmiot.id_przed,przedmiot.nazwa 
FROM wykladowca INNER JOIN pro_zaj ON wykladowca.nr_wykl = pro_zaj.nr_wykl 
INNER JOIN przedmiot ON przedmiot.id_przed=pro_zaj.id_przed 
ORDER BY wykladowca.nr_wykl,przedmiot.nazwa; 

--zad6 f)Podać na jakie zajęcia chodzą poszczególne grupy (dane posortować według nazwy grupy, nazwy przedmiotu).

SELECT grupa.nr_gr,grupa.nazwa,przedmiot.id_przed,przedmiot.nazwa 
FROM przedmiot,gr_zaj,grupa 
WHERE przedmiot.id_przed=gr_zaj.id_przed AND grupa.nr_gr=gr_zaj.nr_gr 
ORDER BY grupa.nazwa,przedmiot.nazwa;

SELECT grupa.nr_gr,grupa.nazwa,przedmiot.id_przed,przedmiot.nazwa 
FROM przedmiot INNER JOIN gr_zaj ON gr_zaj.id_przed=przedmiot.id_przed 
INNER JOIN grupa ON grupa.nr_gr=gr_zaj.nr_gr 
ORDER BY grupa.nazwa,przedmiot.nazwa;

--zad7 g)Podać jakich przedmiotów uczą wykładowcy ze stopniem doktora.

SELECT przedmiot.id_przed,przedmiot.nazwa 
FROM przedmiot,pro_zaj,wykladowca 
WHERE przedmiot.id_przed=pro_zaj.id_przed AND wykladowca.nr_wykl=pro_zaj.nr_wykl 
AND wykladowca.stopien='dr' 
ORDER BY przedmiot.id_przed;

SELECT przedmiot.id_przed,przedmiot.nazwa 
FROM przedmiot INNER JOIN pro_zaj ON przedmiot.id_przed=pro_zaj.id_przed 
INNER JOIN wykladowca ON wykladowca.nr_wykl=pro_zaj.nr_wykl 
WHERE wykladowca.stopien='dr' 
ORDER BY przedmiot.id_przed;

--zad8 h)Dla każdego przedmiotu podać przez jakiego nauczyciela są wykładane.

SELECT przedmiot.id_przed,przedmiot.nazwa,wykladowca.nr_wykl,wykladowca.nazwisko 
FROM pro_zaj,przedmiot,wykladowca 
WHERE pro_zaj.id_przed=przedmiot.id_przed 
AND wykladowca.nr_wykl=pro_zaj.nr_wykl;

SELECT przedmiot.id_przed,przedmiot.nazwa,wykladowca.nr_wykl,wykladowca.nazwisko 
FROM pro_zaj INNER JOIN przedmiot ON pro_zaj.id_przed=przedmiot.id_przed 
INNER JOIN wykladowca ON wykladowca.nr_wykl=pro_zaj.nr_wykl;

--zad9 i)Podać jakich przedmiotów nikt nie prowadzi.

SELECT przedmiot.id_przed,przedmiot.nazwa 
FROM przedmiot 
MINUS(SELECT przedmiot.id_przed,przedmiot.nazwa 
FROM pro_zaj INNER JOIN przedmiot ON przedmiot.id_przed=pro_zaj.id_przed 
INNER JOIN wykladowca ON wykladowca.nr_wykl=pro_zaj.nr_wykl);

SELECT przedmiot.id_przed,przedmiot.nazwa 
FROM przedmiot 
MINUS(SELECT przedmiot.id_przed,przedmiot.nazwa 
FROM przedmiot,pro_zaj,wykladowca 
WHERE przedmiot.id_przed=pro_zaj.id_przed 
AND wykladowca.nr_wykl=pro_zaj.nr_wykl);

SELECT przedmiot.id_przed,przedmiot.nazwa FROM przedmiot WHERE NOT EXISTS(SELECT przedmiot.id_przed,przedmiot.nazwa FROM przedmiot,pro_zaj,wykladowca WHERE przedmiot.id_przed=pro_zaj.id_przed AND wykladowca.nr_wykl=pro_zaj.nr_wykl);

--zad10 j)Podać na jakie zajęcia prowadzone przez wykładowców nie chodzi żadna grupa.

SELECT przedmiot.id_przed,przedmiot.nazwa 
FROM przedmiot,pro_zaj,gr_zaj,grupa 
WHERE przedmiot.id_przed=pro_zaj.id_przed 
AND pro_zaj.nr_wykl=gr_zaj.nr_wykl AND grupa.nr_gr=gr_zaj.nr_gr 
AND grupa.liczba_st=0;

SELECT przedmiot.id_przed,przedmiot.nazwa 
FROM pro_zaj INNER JOIN przedmiot ON przedmiot.id_przed=pro_zaj.id_przed 
INNER JOIN gr_zaj ON pro_zaj.nr_wykl=gr_zaj.nr_wykl INNER JOIN grupa ON grupa.nr_gr=gr_zaj.nr_gr 
WHERE grupa.liczba_st=0;

--zad11 k)Podać na jakie przedmioty nie chodzi żaden student.

SELECT przedmiot.id_przed,przedmiot.nazwa 
FROM przedmiot 
MINUS(SELECT przedmiot.id_przed,przedmiot.nazwa 
FROM przedmiot WHERE przedmiot.id_przed 
IN(SELECT zaliczenie.id_przed FROM zaliczenie GROUP BY zaliczenie.id_przed));


--zad12 l)Podać jaki nauczyciel nie uczy żadnego przedmiotu.

SELECT wykladowca.nr_wykl,wykladowca.nazwisko 
FROM wykladowca 
MINUS (SELECT wykladowca.nr_wykl,wykladowca.nazwisko 
FROM wykladowca WHERE wykladowca.nr_wykl 
IN(SELECT pro_zaj.nr_wykl FROM pro_zaj GROUP BY pro_zaj.nr_wykl)); 

SELECT wykladowca.nr_wykl,wykladowca.nazwisko 
FROM wykladowca 
WHERE NOT EXISTS(SELECT pro_zaj.nr_wykl 
FROM pro_zaj 
WHERE pro_zaj.nr_wykl=wykladowca.nr_wykl);

---
--zad13 m

SELECT przedmiot.id_przed,przedmiot.nazwa 
FROM przedmiot,gr_zaj,grupa 
WHERE przedmiot.id_przed=gr_zaj.id_przed AND gr_zaj.nr_gr=grupa.nr_gr 
ORDER BY przedmiot.id_przed;



--zad 14 n) Podać nazwy przedmiotów które odbywają się w sali 405.

SELECT DISTINCT przedmiot.id_przed, przedmiot.nazwa 
FROM przedmiot, gr_zaj
WHERE przedmiot.id_przed=gr_zaj.id_przed AND gr_zaj.sala = '405'
ORDER BY przedmiot.id_przed;

SELECT DISTINCT przedmiot.id_przed, przedmiot.nazwa 
FROM przedmiot, gr_zaj 
WHERE przedmiot.id_przed=gr_zaj.id_przed AND gr_zaj.sala = '405' 
ORDER BY przedmiot.id_przed;


--zad 15 o) Podać listę studentów którzy mają zajęcia w sali 405.

SELECT DISTINCT student.nr_albumu, student.nazwisko, student.imie 
FROM student, grupa, gr_zaj
WHERE student.nr_gr = grupa.nr_gr AND grupa.nr_gr = gr_zaj.nr_gr 
AND gr_zaj.sala = '405' ORDER BY student.nr_albumu;

SELECT DISTINCT student.nr_albumu, student.nazwisko, student.imie 
FROM student WHERE student.nr_gr 
IN(SELECT gr_zaj.nr_gr 
FROM gr_zaj WHERE gr_zaj.sala = '405' 
GROUP BY gr_zaj.nr_gr) ORDER BY student.nr_albumu;

--zad 16 p) Podać listę studentów którzy nie mają zajęć w sali 405.

SELECT DISTINCT student.nr_albumu, student.nazwisko, student.imie 
FROM student MINUS(SELECT student.nr_albumu, student.nazwisko, student.imie 
FROM student WHERE student.nr_gr IN(SELECT gr_zaj.nr_gr 
FROM gr_zaj WHERE gr_zaj.sala = '405' GROUP BY gr_zaj.nr_gr));


SELECT DISTINCT student.nr_albumu, student.nazwisko, student.imie 
FROM student MINUS(SELECT DISTINCT student.nr_albumu, student.nazwisko, student.imie FROM student, grupa, gr_zaj
WHERE student.nr_gr = grupa.nr_gr AND grupa.nr_gr = gr_zaj.nr_gr AND gr_zaj.sala = '405');

SELECT DISTINCT student.nr_albumu, student.nazwisko, student.imie 
FROM student MINUS(SELECT student.nr_albumu, student.nazwisko, student.imie 
FROM student WHERE student.nr_gr IN(SELECT gr_zaj.nr_gr 
FROM gr_zaj WHERE gr_zaj.sala = '405' GROUP BY gr_zaj.nr_gr));

--zad 17 q) Podać listę studentów którzy chodzą na przedmiot o nazwie FIZYKA.

SELECT DISTINCT student.nr_albumu, student.nazwisko, student.imie 
FROM student WHERE student.nr_gr IN(SELECT przedmiot.id_przed FROM przedmiot WHERE przedmiot.nazwa = 'FIZYKA');

--zad 18 r) Podać na jakie zajęcia chodzą studenci o imieniu Bartek

SELECT DISTINCT przedmiot.id_przed,przedmiot.nazwa 
FROM przedmiot,gr_zaj,student
WHERE student.nr_gr = gr_zaj.nr_gr 
AND przedmiot.id_przed = gr_zaj.id_przed
AND student.imie = 'Bartek';

SELECT DISTINCT przedmiot.id_przed,przedmiot.nazwa 
FROM przedmiot,gr_zaj,student
WHERE student.nr_gr = gr_zaj.nr_gr 
AND przedmiot.id_przed = gr_zaj.id_przed
AND student.imie = 'Bartek' ORDER BY przedmiot.id_przed;

--zad 19 s) Podać nazwiska studentów których uczy mgr Wyk_1

SELECT DISTINCT student.nr_albumu, student.nazwisko, student.imie 
FROM student, gr_zaj, wykladowca
WHERE  student.nr_gr = gr_zaj.nr_gr 
AND wykladowca.nr_wykl = gr_zaj.nr_wykl
AND wykladowca.stopien = 'mgr'
AND wykladowca.nazwisko = 'Wyk_1';

SELECT DISTINCT student.nr_albumu, student.nazwisko, student.imie 
FROM student, gr_zaj, wykladowca
WHERE  student.nr_gr = gr_zaj.nr_gr 
AND wykladowca.nr_wykl = gr_zaj.nr_wykl
AND wykladowca.stopien = 'mgr'
AND wykladowca.nazwisko = 'Wyk_1' 
ORDER BY student.nr_albumu;




---



-- 2.3 Agregacja danych


--zad1 a) Podać ile każdy wykładowca prowadzi przedmiotów.

SELECT wykladowca.nr_wykl,wykladowca.nazwisko,COUNT(pro_zaj.id_przed) AS "ILOSC" 
FROM wykladowca,pro_zaj WHERE wykladowca.nr_wykl=pro_zaj.nr_wykl 
GROUP BY wykladowca.nazwisko, wykladowca.nr_wykl 
ORDER BY wykladowca.nr_wykl;

--zad2 b) Podać nazwy grup dla których grupa.liczba_st <> zliczona ilość wierszy.

SELECT grupa.nr_gr,grupa.nazwa,grupa.liczba_st,
COUNT(student.nr_gr) AS "ZLICZONA ILOSC WIERSZY" 
FROM grupa,student WHERE student.nr_gr = grupa.nr_gr 
GROUP BY grupa.nr_gr,grupa.nazwa,grupa.liczba_st 
HAVING COUNT(student.nr_gr)<>grupa.liczba_st;

--zad3 c)Podać z iloma grupami każdy wykładowca ma zajęcia.

SELECT wykladowca.nr_wykl,wykladowca.nazwisko,
COUNT(grupa.nr_gr) AS "ILOSC GRUP" 
FROM grupa,wykladowca,gr_zaj 
WHERE wykladowca.nr_wykl=gr_zaj.nr_wykl AND gr_zaj.nr_gr=grupa.nr_gr 
GROUP BY wykladowca.nazwisko,wykladowca.nr_wykl 
ORDER BY wykladowca.nr_wykl;

SELECT wykladowca.nr_wykl,wykladowca.nazwisko,
COUNT(grupa.nr_gr) AS "ILOSC GRUP" FROM grupa JOIN gr_zaj ON gr_zaj.nr_gr=grupa.nr_gr 
JOIN wykladowca ON wykladowca.nr_wykl=gr_zaj.nr_wykl 
GROUP BY wykladowca.nazwisko,wykladowca.nr_wykl 
ORDER BY wykladowca.nr_wykl;

--zad4 d) Podać ile każdy student ma przedmiotów.

SELECT student.nr_albumu,student.nazwisko,
COUNT(gr_zaj.id_przed) AS "ILOSC PRZEDMIOTÓW" 
FROM student,gr_zaj 
WHERE student.nr_gr = gr_zaj.nr_gr 
GROUP BY student.nr_albumu,student.nazwisko 
ORDER BY student.nr_albumu;

SELECT student.nr_albumu,student.nazwisko,
COUNT(gr_zaj.id_przed) AS "ILOSC PRZEDMIOTÓW" 
FROM student JOIN gr_zaj ON student.nr_gr=gr_zaj.nr_gr 
GROUP BY student.nr_albumu,student.nazwisko  
ORDER BY student.nr_albumu;

--zad5 e) Podać ilu studentów uczęszcza na każdy przedmiot.

SELECT przedmiot.id_przed,przedmiot.nazwa,
COUNT(student.nr_albumu) AS "LICZBA STUDENTÓW" 
FROM przedmiot,student,gr_zaj 
WHERE przedmiot.id_przed=gr_zaj.id_przed AND gr_zaj.nr_gr=student.nr_gr 
GROUP BY przedmiot.id_przed,przedmiot.nazwa 
ORDER BY COUNT(student.nr_albumu) DESC;

SELECT przedmiot.id_przed,przedmiot.nazwa,
COUNT(student.nr_albumu) AS "LICZBA STUDENTÓW" 
FROM student INNER JOIN gr_zaj ON student.nr_gr = gr_zaj.nr_gr 
INNER JOIN przedmiot ON przedmiot.id_przed=gr_zaj.id_przed 
GROUP BY przedmiot.id_przed,przedmiot.nazwa 
ORDER BY COUNT(student.nr_albumu) DESC;

--zad6 f) Podać liczbą studentów w grupach. 

SELECT grupa.nr_gr,grupa.nazwa,grupa.liczba_st,
COUNT(student.nr_albumu) AS "ZLICZONA ILOŚĆ WIERSZY" 
FROM grupa,student 
WHERE student.nr_gr = grupa.nr_gr 
GROUP BY grupa.nazwa,grupa.nr_gr,grupa.liczba_st 
ORDER BY grupa.nr_gr;

SELECT grupa.nr_gr,grupa.nazwa,grupa.liczba_st,
COUNT(student.nr_albumu) AS "ZLICZONA ILOŚĆ WIERSZY" 
FROM grupa INNER JOIN student ON student.nr_gr = grupa.nr_gr 
GROUP BY grupa.nazwa,grupa.nr_gr,grupa.liczba_st 
ORDER BY grupa.nr_gr;

--zad7 g) Podać nazwy grup dla których grupa.liczba_st = zliczona ilość wierszy.

SELECT grupa.nr_gr,grupa.nazwa,grupa.liczba_st,
(SELECT COUNT(*)FROM student WHERE grupa.nr_gr=student.nr_gr) AS "ZLICZONA ILOSC WIERSZY" 
FROM grupa WHERE (SELECT COUNT(*)FROM student 
WHERE grupa.nr_gr=student.nr_gr)=grupa.liczba_st 
GROUP BY grupa.nr_gr,grupa.nazwa,grupa.liczba_st 
ORDER BY nr_gr;



--zad1 a) Utwórz widok imiona, który będzie zawierał listę imion studentów. Jako wynik podać wynik instrukcji selekt z widoku.

CREATE OR REPLACE VIEW imiona AS 
SELECT student.imie FROM student ORDER BY imie;

SELECT * FROM imiona;


CREATE VIEW imiona AS SELECT student.imie FROM student;

SELECT * FROM imiona;

--zad2 b) Utwórz tabele imiona_w. Wpisz do niej imiona wszystkich wykładowców. Jako wynik podać wynik instrukcji selekt z widoku.

CREATE TABLE imiona_w AS 
SELECT wykladowca.imie FROM wykladowca 
ORDER BY wykladowca.imie;
CREATE OF REPLACE VIEW zad AS 
SELECT * FROM imiona_w;
SELECT * FROM zad;



CREATE TABLE imiona_ww(imie VARCHAR2(50));
INSERT INTO imiona_ww 
SELECT wykladowca.imie 
FROM wykladowca 
ORDER BY wykladowca.imie; 
CREATE OR REPLACE VIEW zad AS SELECT * FROM imiona_ww;
SELECT * FROM zad;

--zad3 c) Napisz zapytanie, które każdemu studentowi, który jeszcze nie ma zaliczenia z przedmiotu fizyka (uwaga może być kilka przedmiotów pasujących do nazwy), wpisze je w trzecim terminie ocena 3, z dzisiejszą datą. Jako wynik podać wynik instrukcji selekt z wpisanymi wierszami. Po wykonaniu załadować od nowa dane.

SET SERVEROUTPUT ON;
BEGIN
	FOR i IN (SELECT DISTINCT zaliczenie.id_przed,zaliczenie.nr_albumu FROM przedmiot,zaliczenie WHERE zaliczenie.id_przed = przedmiot.id_przed AND zaliczenie.ocena=2 AND zaliczenie.termin=3 AND przedmiot.nazwa LIKE 'FIZYKA%')
    LOOP
        DBMS_OUTPUT.PUT(i.id_przed);
        DBMS_OUTPUT.PUT_LINE(i.nr_albumu);
        UPDATE zaliczenie SET zaliczenie.ocena=3,zaliczenie.data=SYSDATE WHERE zaliczenie.nr_albumu=i.nr_albumu and zaliczenie.id_przed=i.id_przed and zaliczenie.termin=3;
    END LOOP;
END;
/
SELECT DISTINCT zaliczenie.id_przed,zaliczenie.nr_albumu FROM przedmiot,zaliczenie WHERE zaliczenie.id_przed = przedmiot.id_przed AND zaliczenie.ocena=2 AND zaliczenie.termin=3 AND przedmiot.nazwa LIKE 'FIZYKA%'


SELECT ROW_NUMBER() OVER (ORDER BY name) rnum,zaliczenie.nr_albumu,przedmiot.nazwa FROM przedmiot,zaliczenie WHERE zaliczenie.id_przed = przedmiot.id_przed AND zaliczenie.ocena=2 AND zaliczenie.termin=2 AND przedmiot.nazwa LIKE 'FIZYKA%';

--zad4 d) Napisz zapytanie które studentom z grupy o nazwie „Grupa 01” usunie zaliczenia z przedmiotu o nazwie „POLSKI”. Jako wynik podać liczbę usuwanych wierszy. Po wykonaniu załadować od nowa dane.

SET SERVEROUTPUT ON;
DECLARE
ilosc NUMBER :=0;
BEGIN

	FOR i IN (SELECT DISTINCT zaliczenie.nr_albumu FROM zaliczenie,przedmiot,student,grupa WHERE przedmiot.id_przed=zaliczenie.id_przed and zaliczenie.nr_albumu=student.nr_albumu and student.nr_gr=grupa.nr_gr and przedmiot.nazwa LIKE 'POLSKI' and grupa.nazwa LIKE '%1')
    
    LOOP
        ilosc:=ilosc+1;
        DELETE FROM zaliczenie WHERE nr_albumu=i.nr_albumu;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE(ilosc);
END;
/

DELETE FROM zaliczenie WHERE ROWID IN (SELECT zaliczenie.ROWID FROM zaliczenie,przedmiot,student,grupa 
WHERE przedmiot.id_przed=zaliczenie.id_przed and zaliczenie.nr_albumu=student.nr_albumu 
and student.nr_gr=grupa.nr_gr and przedmiot.nazwa LIKE 'POLSKI' and grupa.nazwa LIKE '%1');



--zad5 e) Utwórz widok zal_stu_2, który będzie zawierał informacje o zaliczeniach studenta.Nr_albumu, nazwisko, id_przed, nazwa, typ, ocena Ocena – ostatnia ocena z zaliczeni. Jako wynik podać wynik instrukcji selekt zwidoku.




CREATE OR REPLACE VIEW zal_stu_2 AS SELECT zaliczenie.nr_albumu,student.nazwisko,zaliczenie.id_przed,przedmiot.nazwa,przedmiot.typ,zaliczenie.ocena FROM student,przedmiot,zaliczenie WHERE student.nr_albumu=zaliczenie.nr_albumu AND zaliczenie.id_przed=przedmiot.id_przed AND zaliczenie.ocena>2 ORDER BY zaliczenie.nr_albumu,zaliczenie.id_przed;
SELECT * FROM zaliczenie;  



DROP VIEW zal_stu_2;


CREATE VIEW zal_stu_2 AS
SELECT zaliczenie.nr_albumu, student.nazwisko, przedmiot.id_przed, przedmiot.nazwa, przedmiot.typ,  zaliczenie.ocena
FROM zaliczenie, student, przedmiot
WHERE student.nr_albumu = zaliczenie.nr_albumu 
AND przedmiot.id_przed = zaliczenie.id_przed 
AND zaliczenie.termin = 
    (
    SELECT MAX(z.termin) FROM zaliczenie z 
    WHERE z.id_przed = zaliczenie.id_przed 
    AND z.nr_albumu = zaliczenie.nr_albumu
    )
ORDER BY zaliczenie.nr_albumu;

SELECT * FROM zal_stu_2;



--zad6 f) Utwórz widok zal_stu_1, który będzie zawierał informacje o zaliczeniach studenta. Nr_albumu, nazwisko, id_przed, nazwa, typ, ocena Ocena – średnia ocen z zaliczenia. Jako wynik podać wynik instrukcji selekt z widoku


CREATE OR REPLACE VIEW zal_stu_1 AS
SELECT zaliczenie.nr_albumu, student.nazwisko, przedmiot.id_przed, przedmiot.nazwa, przedmiot.typ,  zaliczenie.ocena
FROM zaliczenie, student, przedmiot
WHERE student.nr_albumu = zaliczenie.nr_albumu 
AND przedmiot.id_przed = zaliczenie.id_przed 
AND zaliczenie.ocena = 
    (
    SELECT AVG(z.ocena) FROM zaliczenie z 
    WHERE z.id_przed = zaliczenie.id_przed 
    AND z.nr_albumu = zaliczenie.nr_albumu
    )
ORDER BY zaliczenie.nr_albumu;

SELECT * FROM zal_stu_1;




End

