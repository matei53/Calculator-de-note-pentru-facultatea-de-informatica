# Calculator de note pentru studenții de informatică din cadrul FMI

## Descriere generală
Această aplicație ajută la calcularea mediei finale pentru domeniul informatică, anul universitar 2024-2025.
Mai întâi se alege seria, apoi se selectează materiile opționale și cele facultative, iar la final se inserează toate notele primite pentru fiecare materie (e.g. nota de la examen, nota de la colocviu, nota pe activitatea la curs/seminar/laborator).
Dacă nota nu a fost introdusă corect, butonul de salvare va deveni roșu.
Dacă nota introdusă sau nota finală a unei materii este sub pragul de promovare, căsuța cu numele materiei va deveni roșie, indicând picarea materiei.

## Clase
Clasa Aplicatie și clasa Obiect - cu clasele derivate Buton, TextInput (căsuță pentru introducerea notelor) și TitleText (căsuță de text simplă) - sunt utilizate pentru a crea interfața.
Clasele Materie, Notare și Evaluare sunt folosite pentru a reține toate materiile și metoda de evaluare pentru fiecare dintre acestea. Fiecare materie are trei metode de evaluare separate, una pentru fiecare serie.
Clasa InvalidFilePathError este folosita atunci cand fisierul cu informatiile despre materii sau cel cu fontul textului nu pot fi incarcate.
Clasa InvalidFileContentError este folosita atunci cand fisierul cu informatiile despre materii nu contine informatii potrivite pentru program.
Clasa InvalidInputError este folosita atunci cand este introdusa o nota invalida.

## Resurse
[SFML](https://github.com/SFML/SFML/tree/3.0.1) (Zlib)
