ALTER TABLE zglaszajacy DROP CONSTRAINT fk_id_zglaszajacy_zgloszenie;
ALTER TABLE strazak DROP CONSTRAINT fk_id_strazak_jednostka;
ALTER TABLE pojazd DROP CONSTRAINT fk_id_pojazd_jednostka;
ALTER TABLE akcja DROP CONSTRAINT fk_akcja_zgloszenie;
ALTER TABLE akcja DROP CONSTRAINT fk_akcja_dyspozytor;
ALTER TABLE akcja DROP CONSTRAINT fk_id_akcja_jednostka;