load data
infile 'Student.csv'
append
into table Student
fields terminated by ","
(nr_albumu,nazwisko,imie,wiek,grupa)
