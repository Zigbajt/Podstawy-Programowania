load data
infile 'zaliczenia.csv'
append
into table zaliczenie
fields terminated by ","
(
	id_zaliczenie,
	id_przed,
	nr_albumu,
	nr_wykl,
	ocena,
	termin,
	data
);