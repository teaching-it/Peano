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

    :: Soluzione no. 6
    :: Precondizione: si suppone che il percorso C:\Users\nomeutente\Desktop
    :: sia effettivamente già esistente (poiché percorso di "sistema")
    :: Accedo alla cartella richiesta
    cd C:\Users\nomeutente\Desktop
    :: Creo il file
    echo Hello World >> pippo.txt
)
```
**NB. 1: La soluzione no. 6 è probabilmente la più attinente alle richieste dell'esercizio.**

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

### Ex 1

All’interno di un file di testo denominato cognomi.txt e posizionato all’interno del percorso C:\Users\nomeutente\Desktop\es_17-nov-23, inserire 5 stringhe di testo corrispondenti a 5 cognomi (es: Rossi, Bianchi, Verdi).
Verificare che il percorso esista, eventualmente creare le cartelle necessarie.
Successivamente, mostrare a video il contenuto del file ordinato in ordine alfabetico.

PLUS: Creare un nuovo file con il contenuto ordinato.

**Possibile soluzione no. 1 (vista in classe)**

```
REM Presuppongo che il percorso C:\Users\nomeutente\Desktop
REM già esista, poiché percorso di DEFAULT del Sistema Operativo Windows.

REM Poiché non conosco il percorso all'interno del quale
REM verrà eseguito lo script corrente, devo sincerarmi
REM che il percorso di partenza sia effettivamente
REM C:\Users\nomeutente\Desktop

cd C:\Users\nomeutente\Desktop

REM Due modalità di utilizzo del blocco condizionale

REM Modalità 1.

IF EXIST es_17-nov-23 (
    REM Ramo TRUE del blocco IF
) ELSE (
    REM Ramo FALSE del blocco IF
    mkdir es_17-nov-23
)

REM Modalità 2.

IF NOT EXIST es_17-nov-23 (
    REM Ramo TRUE del blocco IF
    mkdir es_17-nov-23
) ELSE (
    REM Ramo FALSe del blocco IF
)

cd es_17-nov-23

REM Creo il file cognomi.txt

REM Questo comando è superfluo, poiché i comandi successivi
REM vanno comunque a generare il file di testo
type NUL > cognomi.txt

echo Cecchi >> cognomi.txt
echo Brugnoli>> cognomi.txt
echo Carcasci>> cognomi.txt
echo Cappelli>> cognomi.txt
echo Cascio >> cognomi.txt

REM Sintassi alternativa per inserimento di righe di testo all'interno
REM di un file
echo Brugnoli>>Carcasci>>Cappelli>>cognomi.txt

REM Il comando sort ordina in ordine alfabetico il contenuto del file
sort cognomi.txt

REM Con l'operatore di redirezione ">" redirigo l'output del comando
REM all'interno di un altro file.
sort cognomi.txt > cognomi_ordinati.txt

pause
```

**Possibile soluzione no. 2**.

In questa soluzione si utilizzano percorsi assoluti, ovvero percorsi completi (estesi/assoluti) a partire dall'unità radice C.

```
REM Verifica dell'esistenza della cartella e creazione, se necessario
IF NOT EXIST C:\Users\nomeutente\Desktop\es_17-nov-23 (
    mkdir C:\Users\nomeutente\Desktop\es_17-nov-23
)

REM Creazione del file cognomi.txt e inserimento dei cognomi
echo Rossi>Bianchi>Verdi>Neri>Gialli> C:\Users\nomeutente\Desktop\es_17-nov-23\cognomi.txt

REM Ordinamento del contenuto e visualizzazione
echo Contenuto ordinato del file cognomi.txt:
sort C:\users\nomeutente\Desktop\es_17-nov-23\cognomi.txt

REM Creazione di un nuovo file con contenuto ordinato
sort C:\users\nomeutente\Desktop\es_17-nov-23\cognomi.txt > C:\users\nomeutente\Desktop\es_17-nov-23\sorted_cognomi.txt
echo Il file ordinato è stato salvato come sorted_cognomi.txt
```

**Possibile soluzione no. 3**.

```
REM Cambia la directory corrente
cd C:\Users\nomeutente\Desktop\

REM Verifica dell'esistenza della cartella e creazione, se necessario
IF NOT EXIST es_17-nov-23 (
    mkdir es_17-nov-23
)

REM Cambia la directory nella cartella creata
cd es_17-nov-23

REM Creazione del file cognomi.txt e inserimento dei cognomi
echo Rossi > cognomi.txt
echo Bianchi >> cognomi.txt
echo Verdi >> cognomi.txt
echo Neri >> cognomi.txt
echo Gialli >> cognomi.txt

REM Ordinamento del contenuto e visualizzazione
echo Contenuto ordinato del file cognomi.txt:
sort cognomi.txt

REM Creazione di un nuovo file con contenuto ordinato
sort cognomi.txt > sorted_cognomi.txt
echo Il file ordinato è stato salvato come sorted_cognomi.txt
```

### Ex 2

Dichiarare una variabile dal nome "var" e valorizzarla con il testo "Hello".
Se il contenuto della variabile è "Hello" (IF-ELSE) creare la cartella Hello. Altrimenti stampare a video "Hello World".

```
REM Dichiarazione della variabile var e assegnazione del valore
set var=Hello

REM Controllo del contenuto della variabile
IF "%var%"=="Hello" (
    mkdir Hello
    echo Cartella "Hello" creata.
) ELSE (
    echo Hello World
)
```

Si rimanda alla lettura del materiale didattico rispetto all'uso dei doppi apici `"` nella riga di codice in cui è coinvolto il costrutto `IF` e quindi la valutazione del contenuto di una variabile.

## Esercizio assegnati per casa, da svolgere per il 25 novembre 2023

L'obiettivo è creare uno script che esegua automaticamente il **backup** (copia di sicurezza) di tutti i files con estensione `.txt` contenuti all'interno di un determinato percorso.

Lo script dovrà:

1. Dopo aver controllato che il percorso non esista già, creare la cartella `C:\Users\nomeutente\Desktop\Backup`.
2. Generare almeno 3 files di testo, con estensione `
.txt` e contenuto a scelta, all'interno di un percorso anch'esso a scelta (ma differente da quello indicato al precedente punto 1).
3. Copiare tutti i files di testo (di cui al precedente punto 2) all'interno della cartella `Backup` creata in precedenza. **Importante:** La copia dovrà essere svolta utilizzando un unico comando (copia di tutti i files con una determinata estensione).
4. Rinominare la cartella `Backup` con la data odierna.

**Soluzione proposta e commentata in classe**

```

REM Poiché percorso di default del Sistema Operativo
REM posso presupporre che il percorso già esista.
REM Presuppongo, inoltre, che all'interno del Sistema
REM Operativo esista un utente che si chiama nomeutente.

cd C:\Users\nomeutente\Desktop\

IF NOT EXIST Backup (
    mkdir Backup
    REM verrà creata la cartella C:\Users\nomeutente\Desktop\Backup
)

REM Genero 3 files di testo, con contenuto a scelta, all'interno
REM del percorso C:\Users\nomeutente\Desktop\files

mkdir files
cd files

echo pippo >> pippo.txt
echo pluto  >> pluto.txt
echo topolino >> topolino.txt

REM In questo momento sono posizionato all'interno del percorso
REM C:\Users\pardini\Desktop\files

REM Soluzione no. 1
REM copy [percorso file sorgente] [percorso di destinazione]`
    copy *.txt                    ..\Backup

REM Soluzione no. 2
copy *.txt  C:\Users\pardini\Desktop\Backup

cd ..

REM Rinominazione della cartella con la data odierna
REM Soluzione no. 1 ("corretta" ma non elegante)
ren Backup 18-11-2023

REM Soluzione no. 2
REM Obiettivo: trovare il modo di estrapolare la data odierna
REM utilizzando un qualche comando della CLI e, eventualmente,
REM valorizzando una variabile.

pause

```