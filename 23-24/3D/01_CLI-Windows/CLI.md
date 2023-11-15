# Introduzione al Funzionamento della Command Line Interface (CLI)

## 1. Concetti Base della Command Line Interface

### 1.1. Apertura della Command Line

Per accedere alla command line su sistemi Windows, si utilizza la combinazione di tasti `Logo + R`, digitando `cmd` nella finestra che appare.

### 1.2. Struttura Iniziale della Command Line

All’apertura, la command line mostra il percorso `C:\Users\nomeutente>`. Questo indica che ci si trova all'interno del percorso `C:\Users\nomeutente`, equivalente all'accesso via GUI alla cartella `Utenti` e poi alla cartella `nomeutente` sull'unità `C:`.

### 1.3 Comprensione di Unità Logiche e Filesystem nella Command Line Interface

#### 1.3.1 Unità Logiche e Disco Fisso

`C:` si riferisce a un'unità logica, che è un'entità non necessariamente corrispondente alla totalità dell'unità fisica del disco fisso. Ad esempio, se si dispone di un disco fisico partizionato, un'unità logica (come `C:`) può corrispondere a una specifica e singola partizione di questo disco.

#### 1.3.2 Filesystem: Organizzazione dei Dati

Il filesystem è il modo in cui i contenuti (dati), ovvero cartelle e file, sono organizzati e rappresentati all'interno di un'unità disco (struttura ad albero).

#### 1.3.3 Apertura della Command Line

All'apertura della command line, il prompt `C:\Users\nomeutente>` indica che la command line posiziona automaticamente l'utente all'interno del percorso `C:\Users\nomeutente`. Questo è analogo a navigare, mediante la GUI, all'interno dell'unità `C:`, accedendo prima alla cartella `Users` (Utenti) e poi alla cartella specifica dell'utente (`nomeutente`).

## 2. Navigazione e Gestione dei File in CLI

### 2.1. Comandi Fondamentali

- `dir`: Visualizza i contenuti (file e cartelle) del percorso corrente.
- `cd [percorso]`: Cambia la cartella corrente o entra nella cartella specificata.

### 2.3 Pseudo-Cartelle nella Command Line Interface: `..` e `.`

#### 2.3.1 La Pseudo-Cartella `..`

- **Rappresentazione**: La pseudo-cartella `..` rappresenta la cartella "padre", ovvero la cartella che contiene la cartella corrente.
- **Funzione del Comando `cd ..`**: Usando `cd ..`, si esce dalla cartella corrente e si accede alla cartella padre, salendo di un livello nella struttura delle directory.

#### 2.3.2 La Pseudo-Cartella `.`

- **Rappresentazione**: La pseudo-cartella `.` rappresenta la cartella corrente, cioè il percorso in cui ci si trova attualmente.

## 3. Utilizzo Avanzato dei Comandi CLI

### 3.1. Sintassi Generale dei Comandi

La sintassi generale di un comando in Command Line Interface (CLI) segue il formato: `[comando] [opzione/i] [argomento/i]`. In questo schema:

- **[comando]** rappresenta il comando specifico che si desidera eseguire. Esempi comuni includono `dir`, `cd`, `copy`, tra gli altri.

- **[opzione/i]** si riferisce alle opzioni aggiuntive che possono modificare o estendere il comportamento del comando. Spesso sono precedute da un `-` o `/`. Per esempio, in `dir /w`, `/w` è un'opzione che modifica il modo in cui vengono visualizzati i risultati.

- **[argomento/i]** sono i parametri o i percorsi specifici sui quali il comando agirà. Ad esempio, in `cd Documents`, `Documents` è l'argomento che indica la cartella verso cui spostarsi.

Questa struttura permette una grande flessibilità e precisione nell'esecuzione dei comandi, consentendo agli utenti di specificare esattamente cosa vogliono fare e come vogliono che venga fatto. È importante notare che non tutti i comandi richiedono opzioni o argomenti; alcuni possono funzionare con solo il comando stesso.

### 3.2 Uso dell'Opzione `/?` nei Comandi CLI

Utilizzando `/?` al termine di un comando nella Command Line Interface, è possibile visualizzare le specifiche di funzionamento di quel comando. Ad esempio, eseguendo `copy /?`, si stampa a video la scheda informativa del comando `copy`.

### 3.3. Creazione di File

La creazione di file nella Command Line Interface (CLI) può essere eseguita tramite diversi comandi, a seconda delle necessità.

- **Creazione di un File di Testo con Contenuto Specifico**

    Per creare un file di testo denominato `file.txt` che contenga il testo "testo", utilizzare il comando:

    ```
    echo testo >> file.txt
    ```

    Qui, `>>` è un operatore di redirezione che aggiunge il testo al file specificato. Se il file non esiste, viene creato automaticamente.

- **Creazione di un File Vuoto**

    Per creare un file vuoto, ad esempio `nuovo-file.txt`, si usa il comando:

    ```
    type NUL > nuovo-file.txt
    ```

    In questo caso, `>` è un operatore di redirezione che crea un nuovo file e vi scrive l'output del comando a sinistra, in questo caso il risultato di `type NUL` (che è nullo).

### 3.4 Operatori di Redirezione

Gli operatori di redirezione, come `>` e `>>`, sono utilizzati nella CLI per dirigere l'output di un comando verso una destinazione specifica, che può essere un file o un altro comando. La differenza principale tra `>` e `>>` è che `>` sovrascrive il file di destinazione, mentre `>>` aggiunge all'esistente senza cancellare il contenuto precedente. Questi operatori facilitano complesse operazioni di gestione file e contenuti.

### 3.5 Copia di File tramite Command Line Interface

L'obiettivo è copiare un file, ad esempio `file.txt`, in una posizione specifica utilizzando il comando `copy`. La sintassi generale del comando è:

```
copy [argomento 1: percorso file sorgente] [argomento 2: percorso di destinazione]`
```

#### 3.5.1 Esempi di Utilizzo del Comando `copy`

- **Copia del File in una Cartella Specifica**
    Per copiare `file.txt` all'interno del percorso `C:\Users\nomeutente\Pictures`, il comando sarà:

    ```
    copy file.txt C:\Users\nomeutente\Pictures
    ```

    Questo comando sposta `file.txt` dalla sua posizione attuale alla cartella specificata.

- **Copia del File Nello Stesso Percorso con Cambio di Nome**

    Esempio di comando eseguito da `C:\Users\nomeutente\Desktop`:

    ```
    copy file.txt new-file-name.txt
    ```

    In questo caso, il file `file.txt` è copiato nello stesso percorso, ma il suo nome è cambiato in `new-file-name.txt`. Questa operazione è utile per creare una copia del file con un nome diverso nella stessa cartella.

- **Copia del File nella Radice dell'Unità C**
    Esempio di comando eseguito da `C:\Users\nomeutente\Desktop`:

    ```
    copy file.txt C:\
    ```

    Questo comando copia `file.txt` nella radice dell'unità `C:\`. È un metodo veloce per spostare file in posizioni di alto livello sull'unità disco.

### 3.6 Utilizzo del Comando `mkdir` nella Command Line Interface

Il comando `mkdir` è usato per creare nuove cartelle in un sistema operativo basato su Windows o Unix/Linux. La sintassi base del comando è:

    mkdir [nome della cartella]

#### 3.6.1 Esempio di Utilizzo

- **Creazione di una Singola Cartella**
    Per creare una nuova cartella chiamata `new-folder` nella posizione corrente, il comando è:

    ```
    mkdir new-folder
    ```

- **Creazione di Cartelle Multiple**
    È anche possibile creare più cartelle contemporaneamente. Ad esempio, per creare due cartelle chiamate `folder-1` e `folder-2` simultaneamente, si usa:

    ```
    mkdir folder-1 folder-2
    ```

Il comando `mkdir` è fondamentale per organizzare i file in cartelle separate e mantenere un ambiente di lavoro ordinato e strutturato.

### 3.7 Aprire File e Programmi dalla Command Line Interface

L'apertura di file e l'avvio di programmi dalla Command Line Interface (CLI) è una funzionalità essenziale per una rapida interazione con il sistema operativo.

#### 3.7.1 Apertura di File con Notepad

Per aprire un file di testo con Notepad direttamente dalla CLI, il comando è:

    notepad [percorso del file]

Ad esempio, per aprire un file chiamato `documento.txt` situato sul Desktop, si utilizzerebbe:
notepad C:\Users\nomeutente\Desktop\documento.txt

#### 3.7.2 Avvio Generale di Programmi

- Per lanciare qualsiasi programma dalla CLI, si digita il nome eseguibile del programma seguito (eventualmente preceduto da `start`), se necessario, dal percorso del file o da altri parametri. Ad esempio:
    Per avviare un browser web come Google Chrome:

    ```
    start chrome
    ```

- Per eseguire un programma specifico dal suo percorso, si inserisce il percorso completo dell'eseguibile, come:

    ```
    start C:\Path\To\Your\Program.exe
    ```

### 3.8 Comando Echo

Il comando `echo` è utilizzato per visualizzare linee di testo o variabili specifiche nella command line. È molto utile per mostrare messaggi all'utente o per il debug.

### 3.9 Blocco Condizionale IF-THEN-ELSE

Il blocco condizionale `IF-THEN-ELSE` permette di eseguire differenti comandi in base al risultato di una condizione specifica. È una struttura fondamentale per la creazione di script .bat più complessi e funzionali.

#### 3.9.1 Esempio di Utilizzo

Questo blocco controlla se il file `file.txt` esiste. Se esiste, stampa "Il file esiste"; altrimenti, stampa "Il file non esiste".

    IF EXIST file.txt (
        echo Il file esiste
    ) ELSE (
        echo Il file non esiste
    )

### 3.10 Commenti all'Interno dello Script

I commenti sono usati per annotare lo script e renderlo più leggibile. In Batch, i commenti possono essere aggiunti usando `::` o `REM`.

#### 3.10.1 Esempio di Utilizzo

    :: Questo è un commento
    REM Questo è un altro commento

ChatGPT
Ecco un piccolo paragrafo in Markdown che spiega il comando set var e fornisce un breve inciso sulle variabili nella Command Line Interface (CLI):

markdown
Copy code

### 3.11 Dichiarazione Variabili: Uso del Comando `set var`

Il comando `set` nella CLI è utilizzato per creare o modificare variabili d'ambiente. Quando usato nella forma `set var=value`, assegna il valore `value` alla variabile `var`.

#### 3.11.1 Esempio di Utilizzo

    set var=Hello

Questo comando assegna la stringa "Hello" alla variabile `var`. D'ora in poi, ogni volta che si fa riferimento a `%var%` nello script, verrà sostituito con "Hello". **Nota bene:** la variabile è referenziabile utilizzado il carattere `%` prima e dopo il nome della variabile stessa.

#### 3.11.2 Inciso sulle Variabili nella CLI

Le variabili nella CLI di Windows non sono tipizzate, il che significa che non richiedono una dichiarazione di tipo (come int, string, ecc.) prima dell'uso. Possono contenere una varietà di dati, inclusi numeri, testo e percorsi. Questa flessibilità le rende strumenti potenti ma richiede attenzione nella loro gestione, soprattutto per quanto riguarda la loro espansione e la distinzione tra variabili locali e variabili d'ambiente (di cui parleremo, eventualmente, in seguito).

#### 3.11.3 Uso dei Doppi Apici in uno Script `.bat`

L'utilizzo dei doppi apici attorno alle variabili e ai loro valori in uno script `.bat` è una pratica comune che può prevenire errori e migliorare la leggibilità. Di seguito sono illustrate alcune situazioni in cui l'uso dei doppi apici è consigliato:

1. **Prevenzione di Errori**

    Quando si confronta una variabile con un valore, l'uso dei doppi apici assicura che l'espressione rimanga valida anche se la variabile è vuota. Ad esempio, `if "%var%"=="Hello"` funzionerà correttamente anche se `%var%` è vuota, mentre `if %var%==Hello` potrebbe causare errori.

2. **Gestione di Spazi e Caratteri Speciali**

    Se il valore della variabile include spazi o caratteri speciali, i doppi apici sono necessari. Questo garantisce che l'intero valore sia trattato come un singolo elemento. Per esempio, `if "%var%"=="Hello World"` è corretto, ma `if %var%==Hello World` risulterebbe in un errore.

3. **Coerenza e Leggibilità**

    L'uso dei doppi apici può anche migliorare la coerenza e la leggibilità dello script, specialmente in quelli più complessi.

L'utilizzo dei doppi apici attorno alle variabili e ai loro valori, quindi, è una buona pratica per garantire che uno script `.bat` funzioni correttamente in vari contesti, specialmente in presenza di valori vuoti, spazi, o caratteri speciali.
