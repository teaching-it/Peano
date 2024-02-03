# Oracle Virtual Box

Oracle VirtualBox è un software di virtualizzazione che permette agli utenti di eseguire diversi sistemi operativi in modo isolato all'interno di un sistema operativo principale.

## Funzionalità di Oracle VirtualBox

### 1. Virtualizzazione di Sistemi Operativi

Permette di installare e eseguire diversi sistemi operativi (come Windows, Linux, MacOS) in ambienti virtuali indipendenti.

### 2. Isolamento dell'Ambiente

Ogni sistema operativo ospitato (guest) funziona in un ambiente isolato. Ciò significa che le attività svolte su una macchina virtuale non influenzano il sistema operativo ospitante (host).

### 3. Gestione delle Risorse

VirtualBox consente di assegnare risorse del sistema, come CPU, memoria RAM, e spazio su disco, a ogni macchina virtuale in base alle esigenze.

### 4. Rete e Connettività

Supporta diverse configurazioni di rete, permettendo alle macchine virtuali di comunicare tra loro, con l'host, e con Internet.

### 5. Snapshot e Clonazione

Offre la possibilità di salvare gli stati correnti delle macchine virtuali (snapshot), che possono essere utilizzati per ripristinare il sistema a quel punto specifico. È anche possibile clonare intere macchine virtuali.

### 6. Supporto per Dispositivi USB e Periferiche

Permette di collegare dispositivi USB e altre periferiche direttamente alle macchine virtuali.

### 7. Condivisione Cartelle e Clipboard

È possibile condividere cartelle e la clipboard tra il sistema host e i sistemi guest, facilitando lo scambio di file e informazioni.

## Concetti di Macchina Ospitante (Host) e Ospitata (Guest)

### Macchina Ospitante (Host)

È il sistema operativo principale su cui viene eseguito Oracle VirtualBox.
Fornisce le risorse hardware (come CPU, memoria, spazio su disco) che vengono utilizzate dalle macchine virtuali.
Può essere qualsiasi sistema operativo supportato da VirtualBox, come Windows, Linux o MacOS.

### Macchina Ospitata (Guest)

È il sistema operativo eseguito all'interno di una macchina virtuale su VirtualBox.
Opera come se fosse un sistema indipendente, ma in realtà utilizza una porzione delle risorse dell'host.
Può essere un sistema operativo differente dall'host o una versione diversa dello stesso sistema.