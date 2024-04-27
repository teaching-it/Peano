# Bash scripting

## Analisi del sistema tramite /proc
Il filesystem `/proc` è una funzionalità specifica dei sistemi operativi basati su Linux che fornisce una “vista” dinamica del sistema operativo e del suo stato corrente. Piuttosto che essere un filesystem vero e proprio con dati salvati su disco, `/proc` è un filesystem virtuale che risiede in memoria. Fornisce un'interfaccia attraverso la quale i dati del kernel e delle informazioni di sistema possono essere accessibili dall’utente, permettendo di interrogare o modificare alcune impostazioni del sistema operativo in tempo reale.

### Obiettivo
Creare uno script Bash che analizzi informazioni specifiche dalla directory `/proc` per monitorare alcune risorse fondamentali del sistema.

1. Leggere il file `/proc/cpuinfo` per ottenere e visualizzare le seguenti informazioni relative alla CPU: modello della CPU, velocità di clock (in MHz), quantità di memoria cache (espressa in KB), numero di core disponibili. In base ai valori estratti (e opportunamente processati) determinare se il sistema è idoneo a svolgere attività quotidiane standard, che non richiedono elevate prestazioni, basandosi sui seguenti criteri: velocità di clock deve essere maggiore o uguale a 1.5 GHz, il numero di core deve essere maggiore o uguale a 2. In base all'esito della valutazione, stampare a video un messaggio (opportunamente formattato) che indichi se il sistema è adatto o meno per attività standard.

2. Calcolare l'uso totale della memoria e la memoria libera: utilizzare il file `/proc/meminfo` per determinare/estrarre questi due dati, esprimendo il risultato in MB.

3. Identificare il numero di processi in esecuzione: calcolare il numero di processi in esecuzione leggendo il contenuto della directory `/proc` e contando le directory che hanno nomi numerici, che rappresentano gli identificativi dei processi (programmi applicativi in esecuzione nel sistema). Qualora il numero dei processi in esecuzione sia superiore alle 200 unità e la memoria RAM disponibile sia inferiore a 1GB, produrre un alert opportunamente formattato.

4. `/proc/version` contiene informazioni sulla versione del kernel, il compilatore (GCC) usato per la sua compilazione. Estrarre e stampare a video questo due informazioni.

5. Utilizzando il comando `lspci` è possibile visualizzare l’elenco delle periferiche installate all’interno del sistema. Filtrare l’output visualizzando i soli dispositivi di rete ed in particolare unicamente le informazioni relative a marca e modello.
