## Primo blocco di esercizi

### Ex 1

Creare un file vuoto dal nome pippo.txt. Copiare il file pippo.txt all’interno del percorso C:\Users\nomeutente\Downloads.

#### Una possibile soluzione
In classe abbiamo visto alcune differenti soluzioni.

In linea generale, preme ricordare che non esiste un'unica soluzione corretta, bensì una vasta gamma di possibilità che possono tutte condurre ad una soluzione. Certamente, alcune soluzioni risultano più **eleganti/efficaci/efficienti** di altre.

    REM Creazione di un file vuoto chiamato pippo.txt
    type NUL > pippo.txt

    REM Copia del file pippo.txt nella cartella Downloads dell'utente
    copy pippo.txt C:\Users\nomeutente\Downloads

    REM Conferma dell'avvenuta copia
    echo File pippo.txt copiato in C:\nomeutente\Downloads

    REM Mette in pausa lo script per permettere la verifica dell'esecuzione
    pause

### Ex 2

Creare un file contenente il testo "Hello World". Creare una nuova cartella dal nome "Pippo" all’interno del percorso C:\Users\nomeutente\Desktop. Copiare il file creato all’interno di quest’ultimo percorso.

#### Una possibile soluzione

    REM Creazione di un file di testo contenente "Hello World"
    echo Hello World > hello.txt

    REM Creazione della cartella Pippo sul Desktop
    mkdir C:\Users\nomeutente\Desktop\Pippo

    REM Copia del file hello.txt nella cartella Pippo
    copy hello.txt C:\Users\nomeutente\Desktop\Pippo

    REM Conferma dell'avvenuta copia
    echo File hello.txt copiato in C:\Users\nomeutente\Desktop\Pippo

    REM Mette in pausa lo script per permettere la verifica dell'esecuzione
    pause

### Ex 3

Crea il file C:\Users\nomeutente\Desktop\pippo.txt che contenga il testo "Hello World". Se il file già esiste scrivere a video “Il file esiste”, altrimenti creare il file come indicato.

#### Soluzione no. 1

    REM Verifica se il file esiste sul Desktop
    IF EXIST "C:\Users\nomeutente\Desktop\pippo.txt" (
        echo Il file esiste
    ) ELSE (
        REM Crea il file con il testo "Hello World" se non esiste
        
        echo Hello World > "C:\Users\nomeutente\Desktop\pippo.txt"
        
        echo File creato: C:\Users\nomeutente\Desktop\pippo.txt
    )

    REM Mette in pausa lo script per permettere la verifica dell'esecuzione
    pause


#### Soluzione no. 2

In questa seconda soluzione si propone l'utilizzo di una variabile, valorizzata in testa allo script e successivamente referenziata. Si ricorda che nel materiale didattico è presente un'apposita sezione sul tema.

    REM Percorso del file da controllare e creare
    set "filepath=C:\Users\nomeutente\Desktop\pippo.txt"

    REM Verifica se il file esiste
    IF EXIST "%filepath%" (
        echo Il file esiste
    ) ELSE (
        REM Crea il file con il testo "Hello World" se non esiste
        echo Hello World > "%filepath%"
        echo File creato: %filepath%
    )

    REM Mette in pausa lo script per permettere la verifica dell'esecuzione
    pause

## Esercizio assegnato in classe in data 11 novembre 2023.

Creare il file `C:\Users\nomeutente\Desktop\es_11-nov\text.txt` che contenga il testo "Hello World".
Qualora la cartella es_11-nov non esista (IF EXIST), allora creare la cartella, ovviamente prima di creare il file.
Qualora, invece, la cartella già esista (ramo ELSE), scrivere a video HELLO e non svolgere alcuna altra operazione.
Inserire il comando `pause` al termine dello script per verificarne l'esecuzione.

Ricorda di sostituire `nomeutente` con il tuo effettivo nome utente di Windows.

#### Soluzione no. 1

    REM Verifica se la cartella es_11-nov esiste
    IF NOT EXIST "C:\Users\nomeutente\Desktop\es_11-nov" (
        REM Se la cartella non esiste, la crea
        mkdir "C:\Users\nomeutente\Desktop\es_11-nov"

        REM Crea il file text.txt con il testo "Hello World"
        echo Hello World > "C:\Users\nomeutente\Desktop\es_11-nov\text.txt"
    ) ELSE (
        REM Se la cartella esiste, stampa "HELLO" a video
        echo HELLO
    )

    REM Mette in pausa lo script per permettere la verifica dell'esecuzione

#### Soluzione no. 2

Questa seconda versione dello script utilizza percorsi relativi, rendendolo più flessibile e adattabile a diverse configurazioni utente senza la necessità di modificare il percorso di destinazione.

    REM Cambia la directory corrente in Desktop
    cd C:\Users\nomeutente\Desktop

    REM Verifica se la cartella es_11-nov esiste
    IF NOT EXIST "es_11-nov" (
        REM Se la cartella non esiste, la crea
        mkdir "es_11-nov"

        REM Crea il file text.txt con il testo "Hello World" nella cartella es_11-nov
        echo Hello World > "es_11-nov\text.txt"
    ) ELSE (
        REM Se la cartella esiste, stampa "HELLO" a video
        echo HELLO
    )

    REM Mette in pausa lo script per permettere la verifica dell'esecuzione
    pause

## Esercizio assegnato per casa, da svolgere per venerdì 17 novembre

L'obiettivo è creare uno script che esegua automaticamente il **backup** (copia di sicurezza) di tutti i files con estensione `.txt` contenuti all'interno di un determinato percorso.

Lo script dovrà:

1. Dopo aver controllato che il percorso non esista già, creare la cartella `C:\Users\nomeutente\Desktop\Backup`.
2. Generare almeno 3 files di testo, con estensione `
.txt` e contenuto a scelta, all'interno di un percorso anch'esso a scelta (ma differente da quello indicato al precedente punto 1).
3. Copiare tutti i files di testo (di cui al precedente punto 2) all'interno della cartella `Backup` creata in precedenza. **Importante:** La copia dovrà essere svolta utilizzando un unico comando (copia di tutti i files con una determinata estensione).
4. Rinominare la cartella `Backup` con la data odierna.

#### Possibile soluzione

    REM Poiché percorso di default del Sistema Operativo
    REM posso presupporre che il percorso già esista.
    REM Presuppongo, inoltre, che all'interno del Sistema
    REM Operativo esista l'utente mariorossi.

    cd C:\Users\mariorossi\Desktop\

    IF NOT EXIST Backup (
        mkdir Backup
        REM verrà creata la cartella C:\Users\pardini\Desktop\Backup
    )

    REM Genero 3 files di testo, con contenuto a scelta, all'interno del percorso REM C:\Users\mariorossi\Desktop\files

    mkdir files
    cd files

    echo "pippo" >> pippo.txt
    echo "pluto" >> pluto.txt
    echo "topolino" >> topolino.txt

    REM Ricorda che, questo momento, sono posizionato all'interno del percorso
    REM C:\Users\pardini\Desktop\files

    REM Soluzione no. 1
    REM copy [percorso file sorgente] [percorso di destinazione]`
        copy *.txt                    ..\Backup

    REM Soluzione no. 2
    copy *.txt  C:\Users\pardini\Desktop\Backup

    cd ..

    REM Rinominazione della cartella con la data "odierna"
    REM Soluzione no. 1 ("corretta" ma non elegante)
    ren Backup 18-11-2023

    REM Soluzione no. 2
    REM Obiettivo: trovare il modo di estrapolare la data odierna
    REM utilizzando un qualche comando della CLI e, eventualmente,
    REM valorizzando una variabile.

    pause
