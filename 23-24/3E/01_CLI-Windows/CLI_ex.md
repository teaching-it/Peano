## Ex 1 
Creare un file vuoto dal nome pippo.txt. Copiare il file pippo.txt all’interno del percorso C:\Users\nomeutente\Downloads.

```
type NUL > pippo.txt
copy pippo.txt C:\Users\nomeutente\Downloads
```

## Ex 2
Creare un file contenente il testo "Hello World". Creare una nuova cartella dal nome "Pippo" all’interno del percorso C:\Users\nomeutente\Desktop. Copiare il file creato all’interno di quest’ultimo percorso.

```
echo Hello World > newfile.txt
mkdir C:\Users\nomeutente\Desktop\Pippo
copy newfile.txt C:\Users\nomeutente\Desktop\Pippo
```

## Ex 3
Crea il file C:\Users\nomeutente\Desktop\pippo.txt che contenga il testo "Hello World". Se il file già esiste scrivere a video "Il file esiste"", altrimenti creare il file come indicato.

```
:: This is a comment!
REM This is an alternative way to define a comment!

IF EXIST C:\Users\nomeutente\Desktop\pippo.txt (
    echo Il file esiste

) ELSE (
    :: Soluzione no. 1
    :: Primo step: creazione file vuoto
    type NUL > pippo.txt
    :: Secondo step: inserimento testo all'interno del file
    echo Hello World >> pippo.txt

    :: Soluzione no. 2
    :: In un sol colpo si accorpano i due step precedenti
    echo Hello World >> pippo.txt

    :: Soluzione no. 3
    :: Utilizzo il percorso completo, poiché non sono certo del percorso corrente in cui sono posizionato
    echo Hello World >> C:\Users\nomeutente\Desktop\pippo.txt

    :: Soluzione no. 4
    :: Creo il file nel percorso corrente (al momento sconosciuto)
    echo Hello World >> pippo.txt
    :: Copio il file nel percorso di destinazione (potrebbe altrimenti essere opportuno spostarlo)
    copy pippo.txt C:\Users\nomeutente\Desktop\

    :: Soluzione no. 5
    :: Precondizione: si suppone che il percorso C:\Users\nomeutente\Desktop
    :: sia effettivamente già esistente (poiché percorso di "sistema")
    :: Accedo alla cartella richiesta
    cd C:\Users\nomeutente\Desktop
    :: Creo il file
    echo Hello World >> pippo.txt
)
```
**NB. 1: La soluzione no. 5 è probabilmente la più attinente alle richieste dell'esercizio.**

**NB. 2: Come potete notare, non esiste un'univoca soluzione corretta, bensì una vasta gamma di possibilità che possono tutte condurre ad una soluzione. Certamente, alcune soluzioni risultano più eleganti/efficaci/efficienti di altre.**

## Esercizi assegnati per casa, da svolgere per il 17 novembre 2023

### Ex 1

All’interno di un file di testo denominato cognomi.txt e posizionato all’interno del percorso C:\Users\nomeutente\Desktop\es_17-nov-23, inserire 5 stringhe di testo corrispondenti a 5 cognomi (es: Rossi, Bianchi, Verdi).
Verificare che il percorso esista, eventualmente creare le cartelle necessarie.
Successivamente, mostrare a video il contenuto del file ordinato in ordine alfabetico.

PLUS: Creare un nuovo file con il contenuto ordinato.

### Ex 2

Dichiarare una variabile dal nome "var" e valorizzarla con il testo "Hello".
Se il contenuto della variabile è "Hello" (IF-ELSE) creare la cartella Hello. Altrimenti stampare a video "Hello World".
