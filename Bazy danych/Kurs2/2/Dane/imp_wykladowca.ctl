load data
infile 'Wykladowca.csv'
append
into table Wykladowca
fields terminated by ","
(
	nr_wykl,
	nazwisko,
	imie,
	stopien
);