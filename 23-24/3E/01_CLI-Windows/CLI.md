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

#### 3.3.1 Inciso su Operatori di Redirezione

Gli operatori di redirezione, come `>` e `>>`, sono utilizzati nella CLI per dirigere l'output di un comando verso una destinazione specifica, che può essere un file o un altro comando. La differenza principale tra `>` e `>>` è che `>` sovrascrive il file di destinazione, mentre `>>` aggiunge all'esistente senza cancellare il contenuto precedente. Questi operatori facilitano complesse operazioni di gestione file e contenuti.

### 3.4 Copia di File tramite Command Line Interface

L'obiettivo è copiare un file, ad esempio `file.txt`, in una posizione specifica utilizzando il comando `copy`. La sintassi generale del comando è:

```
copy [argomento 1: percorso file sorgente] [argomento 2: percorso di destinazione]`
```

#### 3.4.1 Esempi di Utilizzo del Comando `copy`

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

### 3.5 Utilizzo del Comando `mkdir` nella Command Line Interface

Il comando `mkdir` è usato per creare nuove cartelle in un sistema operativo basato su Windows o Unix/Linux. La sintassi base del comando è:

    mkdir [nome della cartella]

#### 3.5.1 Esempio di Utilizzo

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

### 3.6 Aprire File e Programmi dalla Command Line Interface

L'apertura di file e l'avvio di programmi dalla Command Line Interface (CLI) è una funzionalità essenziale per una rapida interazione con il sistema operativo.

#### 3.6.1 Apertura di File con Notepad

Per aprire un file di testo con Notepad direttamente dalla CLI, il comando è:

    notepad [percorso del file]

Ad esempio, per aprire un file chiamato `documento.txt` situato sul Desktop, si utilizzerebbe:
notepad C:\Users\nomeutente\Desktop\documento.txt

#### Avvio Generale di Programmi

- Per lanciare qualsiasi programma dalla CLI, si digita il nome eseguibile del programma seguito, se necessario, dal percorso del file o da altri parametri. Ad esempio:
- Per avviare Microsoft Word, si digita:

  ```
  winword
  ```

- Per avviare un browser web come Google Chrome:

  ```
  chrome
  ```

- Per eseguire un programma specifico dal suo percorso, si inserisce il percorso completo dell'eseguibile, come:

  ```
  C:\Path\To\Your\Program.exe
  ```