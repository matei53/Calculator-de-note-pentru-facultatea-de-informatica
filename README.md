# Calculator de note pentru studenții de informatică din cadrul FMI

## Descriere generală
Această aplicație ajută la calcularea mediei finale pentru domeniul informatică, anul universitar 2024-2025.<br><br>
Mai întâi se alege seria, apoi se selectează materiile opționale și cele facultative. În cazul alegerii facultativelor, se pot alege orice număr de opțiuni. În cazul alegerii opționalelor, trebuie aleasă o materie pentru anul 2, sau 6 materii (3 din primele 23 afișate și 3 din celelalte 18) pentru anul 3.<br><br>
La final se inserează toate notele primite pentru fiecare materie (e.g. nota de la examen, nota de la colocviu, nota pe activitatea la curs/seminar/laborator).<br><br>
Dacă nota introdusă sau nota finală a unei materii este sub pragul de promovare, căsuța cu numele materiei va deveni roșie, indicând picarea materiei.

## Clase
### Clasele obiectelor și clasa aplicației
Clasa Aplicatie și clasa Obiect - cu clasele derivate Buton, TextInput (căsuță pentru introducerea notelor) și TitleText (căsuță de text simplă) - sunt utilizate pentru a crea interfața.
### Clasele materiilor
Clasele Materie, Notare și Evaluare sunt folosite pentru a reține toate materiile și metoda de evaluare pentru fiecare dintre acestea. Fiecare materie are trei metode de evaluare separate, una pentru fiecare serie.
### Clasele erorilor, derivate din std:exception
Clasa InvalidFilePathError este folosita atunci cand fisierul cu informatiile despre materii sau cel cu fontul textului nu pot fi incarcate. In acest caz, se va afisa un mesaj in terminal legat de problema.<br><br>
Clasa InvalidFileContentError este folosita atunci cand fisierul cu informatiile despre materii nu contine informatii potrivite pentru program. În acest caz, pe lângă mesaj, se va afisa și linia din fișierul text unde s-a găsit problema.<br><br>
Clasa InvalidInputError este folosita atunci cand este introdusa o nota invalida. În acest caz, culoarea de animație a butonului de salvare se va schimba în roșu.

## Resurse
[SFML](https://github.com/SFML/SFML/tree/3.0.1) (Zlib)
