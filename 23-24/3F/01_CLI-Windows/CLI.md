# Windows CLI

Gli appunti che abbiamo strutturato insieme durante le lezioni di laboratorio sono ora disponibili in un formato più ordinato e completo.

## Interfacce Utente: CLI vs GUI

## Definizioni e Differenze

- **CLI (Command Line Interface)**: Interfaccia da linea di comando che permette di interagire con il Sistema Operativo e i suoi programmi applicativi. Generalmente, l'utilizzo di una tastiera è sufficiente per operare con la CLI.
- **GUI (Graphical User Interface)**: Interfaccia utente di tipo grafico che richiede strumenti hardware specifici per la sua piena funzionalità. Ad esempio, può essere necessario l'uso di un mouse, uno schermo touch, o altri dispositivi di input.

## Utilizzo della CLI in Windows

### Apertura Command Line

Combinazione di tasti: Tasto LOGO di Windows + tasto R; poi, digitare `cmd` e premere invio.

All’apertura della CLI (una finestra nera con un breve testo, in bianco, in alto a sinistra), ci viene mostrato un *prompt* con il quale interagire, ovvero al quale impartire comandi.

Più in generale, il termine *prompt* si riferisce a una breve linea di testo (solitamente terminata con un simbolo come **>**) in un'interfaccia a riga di comando.

Il seguente prompt `C:\Users\nomeutente>` significa che la CLI, automaticamente, ci posiziona all’interno del percorso del filesystem C:\Users\nomeutente` (è come se con la GUI accedessi all’unità C, poi alla cartella Users, poi alla cartella nomeutente). Ecco, quella specifica posizione rappresenta la cartella di lavoro.

## Struttura del Filesystem e Percorsi

- **Rappresentazione delle Unità Disco**:
  - `C:` si riferisce a una unità logica del disco fisso.
  - Esempi di partizionamento e gestione dello spazio su un SSD.
- **Navigazione nel Filesystem**:
  - `C:\Users\nomeutente>` rappresenta un percorso specifico all'interno del Filesystem.
  - Struttura ad albero delle cartelle e files.

## Comandi Base della CLI

- **Navigazione e Gestione File**:
  - `cd ..`: Salire di un livello nella struttura del filesystem.
  - `dir`: Visualizzare contenuti del percorso corrente.
  - `cd [percorso]`: Cambiare la cartella corrente.
  - `mkdir [nomecartella]`: Creare una nuova cartella.

## Creazione ed Esecuzione di Script nella CLI

- **Processi di Automazione**:
  - Gli script permettono l'automazione di processi mediante una sequenza di comandi.
- **Creazione di uno Script Base**:
  - Esempio di creazione di una cartella e di un file vuoto tramite script.
- **Esercizio Proposto**:
  - Script per creare una cartella con la data odierna e un file `hello.txt`.
