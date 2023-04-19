load data
infile 'przed.csv'
append
into table przedmiot
fields terminated by ","
(
	id_przed,
	nazwa,
	typ
);