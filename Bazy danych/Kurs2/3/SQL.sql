
--Napisać zapytanie, które dla każdego studenta poda następujące dane:
--i. nr_albumu, id_przed, średnia_ocen

Select nr_albumu,id_przed,AVG(ocena) From zaliczenie GROUP BY ROLLUP(nr_albumu,id_przed,ocena);

Select nr_albumu,id_przed,AVG(ocena) From zaliczenie GROUP BY CUBE(nr_albumu,id_przed,ocena);

--ii. nr_albumu, średnia_ocen

Select nr_albumu,AVG(ocena) From zaliczenie GROUP BY ROLLUP(nr_albumu);

Select nr_albumu,AVG(ocena) From zaliczenie GROUP BY CUBE(nr_albumu);

--b. Napisać zapytanie, które dla każdego przedmiotu poda średnią według następujące dane:
--i. id_przed, nr_albumu, średnia_ocen

SELECT id_przed,nr_albumu,AVG(ocena) FROM zaliczenie GROUP BY GROUPING SETS((id_przed,nr_albumu)) ORDER BY id_przed,nr_albumu;

--ii. id_przed, termin, średnia_ocen

SELECT id_przed,termin,AVG(ocena) FROM zaliczenie GROUP BY GROUPING SETS((id_przed,termin)) ORDER BY id_przed,termin;

--iii. id_przed, średnia_ocen

SELECT id_przed,AVG(ocena) FROM zaliczenie GROUP BY GROUPING SETS(id_przed);

--2. Partycje obliczeniowe.
--Napisać zapytanie, które poda następujące dane:
--a. id_przed, termin, ocena, procent z daną oceną

SELECT DISTINCT id_przed,termin,ocena,round(100*(count(ocena) over(PARTITION BY ocena))/(select count(*) FROM zaliczenie)) AS "PROCENT Z DANA OCENA" FROM zaliczenie ORDER BY id_przed,termin,ocena;

--b. id_przed, ocena, procent

SELECT DISTINCT id_przed,ocena,round(100*(count(ocena) over(PARTITION BY ocena))/(select count(*) FROM zaliczenie)) AS "PROCENT Z DANA OCENA" FROM zaliczenie ORDER BY id_przed,ocena;

--3. Okna. Napisać zapytanie które poda następujące dane:
--a. id_przed, nr_albumu, termin , średnia_ocen

SELECT DISTINCT id_przed,nr_albumu,termin,AVG(ocena) FROM zaliczenie WHERE EXTRACT(YEAR FROM zaliczenie.data_zaliczenia) BETWEEN 2020 AND EXTRACT(YEAR FROM SYSDATE) GROUP BY id_przed,nr_albumu,termin;

--b. id_przed, nr_albumu, średnia_ocen

SELECT DISTINCT id_przed,nr_albumu,AVG(ocena) FROM zaliczenie WHERE EXTRACT(YEAR FROM zaliczenie.data_zaliczenia) BETWEEN 2021 AND EXTRACT(YEAR FROM SYSDATE) GROUP BY id_przed,nr_albumu;

--Funkcje rankingowe.
--Podać ranki studentów od najlepszej do najgorszej średniej:
--a. Nr_albumu, id_przed, średnia_ocen, ranking

SELECT DISTINCT nr_albumu,id_przed,AVG(ocena),DENSE_RANK() OVER (ORDER BY AVG(ocena) DESC) AS "RANKING" FROM zaliczenie GROUP BY nr_albumu,id_przed;

--b. Nr_albumu, średnia_ocen, ranking

SELECT DISTINCT nr_albumu,AVG(ocena),DENSE_RANK() OVER (ORDER BY AVG(ocena) DESC) AS "RANKING" FROM zaliczenie GROUP BY nr_albumu;

--5. Do każdego z poprzednich punktów napisać trzy inne dowolne zapytania.

--1 Operator ROLLUP i CUBE. 

Select nr_albumu,id_przed,data_zaliczenia,AVG(ocena) From zaliczenie GROUP BY ROLLUP(nr_albumu,id_przed,ocena,data_zaliczenia);

Select nr_albumu,id_przed,data_zaliczenia,AVG(ocena) From zaliczenie GROUP BY CUBE(nr_albumu,id_przed,ocena,data_zaliczenia);

Select nr_albumu,id_przed,data_zaliczenia,nr_wykl,AVG(ocena) From zaliczenie GROUP BY ROLLUP(nr_albumu,id_przed,ocena,data_zaliczenia,nr_wykl);

Select nr_albumu,id_przed,data_zaliczenia,nr_wykl,AVG(ocena) From zaliczenie GROUP BY CUBE(nr_albumu,id_przed,ocena,data_zaliczenia,nr_wykl);

Select nr_wykl,AVG(ocena) From zaliczenie GROUP BY ROLLUP(nr_wykl);

Select nr_wykl,AVG(ocena) From zaliczenie GROUP BY CUBE(nr_wykl);

--2 Partycje obliczeniowe.

SELECT id_przed,nr_wykl,AVG(ocena) FROM zaliczenie GROUP BY GROUPING SETS((id_przed,nr_wykl)) ORDER BY id_przed,nr_wykl;

SELECT id_przed,nr_wykl,termin,AVG(ocena) FROM zaliczenie GROUP BY GROUPING SETS((id_przed,termin,nr_wykl)) ORDER BY id_przed,nr_wykl,termin;

SELECT nr_wykl,termin,AVG(ocena) FROM zaliczenie GROUP BY GROUPING SETS((termin,nr_wykl)) ORDER BY nr_wykl,termin;

--3. Okna.

SELECT DISTINCT id_przed,nr_wykl,termin,AVG(ocena) FROM zaliczenie WHERE EXTRACT(YEAR FROM zaliczenie.data_zaliczenia) BETWEEN 2020 AND EXTRACT(YEAR FROM SYSDATE) GROUP BY id_przed,nr_wykl,termin;

SELECT DISTINCT id_przed,nr_wykl,AVG(ocena) FROM zaliczenie WHERE EXTRACT(YEAR FROM zaliczenie.data_zaliczenia) BETWEEN 2020 AND EXTRACT(YEAR FROM SYSDATE) GROUP BY id_przed,nr_wykl;

SELECT DISTINCT nr_wykl,termin,AVG(ocena) FROM zaliczenie WHERE EXTRACT(YEAR FROM zaliczenie.data_zaliczenia) BETWEEN 2020 AND EXTRACT(YEAR FROM SYSDATE) GROUP BY nr_wykl,termin;

--4. Funkcje rankingowe.

SELECT DISTINCT nr_wykl,id_przed,AVG(ocena),DENSE_RANK() OVER (ORDER BY AVG(ocena) DESC) AS "RANKING" FROM zaliczenie GROUP BY nr_wykl,id_przed;

SELECT DISTINCT nr_wykl,AVG(ocena),DENSE_RANK() OVER (ORDER BY AVG(ocena) DESC) AS "RANKING" FROM zaliczenie GROUP BY nr_wykl;

SELECT DISTINCT nr_wykl,termin,AVG(ocena),DENSE_RANK() OVER (ORDER BY AVG(ocena) DESC) AS "RANKING" FROM zaliczenie GROUP BY nr_wykl,termin;

