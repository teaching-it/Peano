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

## Modalità di Accesso alla Rete

In un ambiente di virtualizzazione in generale, così come in Oracle VirtualBox, le macchine virtuali (VM) possono connettersi alla rete in modi diversi.

Due delle modalità di configurazione più comuni per i dispositivi di rete nelle VM sono la modalità NAT (Network Address Translation) e la modalità Bridge. Ognuna di queste modalità ha caratteristiche e usi specifici.

### 1. Modalità NAT (Network Address Translation)

#### Funzionamento

In modalità NAT, la macchina virtuale accede alla rete esterna attraverso il *network adaptar* (scheda di rete) dell'host. L'indirizzo IP della macchina virtuale non è visibile sulla rete esterna; invece, la VM condivide l'indirizzo IP dell'host.

#### Isolamento e Sicurezza

Questa modalità fornisce un certo livello di isolamento, poiché le VM non sono direttamente esposte alla rete esterna. È utile per gli ambienti in cui la sicurezza e l'isolamento sono importanti.

#### Limitazioni

Le macchine in modalità NAT possono avere difficoltà a fornire servizi alla rete esterna (ad esempio un servizio Web) a causa della natura della traduzione degli indirizzi.

### 2. Modalità Bridge

#### Funzionamento

In modalità bridge, la macchina virtuale è collegata direttamente alla rete fisica a cui è collegato l'host. Ciò significa che la VM appare sulla rete come qualsiasi altro dispositivo fisico, con il proprio indirizzo IP unico nella rete.

#### Visibilità e Accessibilità

Le VM in modalità bridge sono visibili e accessibili da altri dispositivi nella stessa rete. Questo le rende adatte per scenari in cui le VM devono funzionare come server o essere altrimenti direttamente accessibili dalla rete locale.

#### Requisiti di Rete

Questa modalità richiede che la rete possa fornire un indirizzo IP alla VM, solitamente attraverso un DHCP server.
Confronto e Scelta

### Scelta Progettuale

La scelta tra NAT e bridge dipende dalle esigenze specifiche. Se è necessario che la VM sia isolata dalla rete esterna e non richiede un accesso diretto da parte di altri dispositivi sulla rete, NAT è la scelta migliore. Se, invece, è importante che la VM sia visibile e accessibile sulla rete locale come un dispositivo indipendente, la modalità bridge è più appropriata.

### Considerazioni di Sicurezza

La modalità NAT offre un livello di sicurezza intrinseco attraverso l'isolamento, ma limita le funzionalità di rete. La modalità bridge offre più flessibilità di rete, ma richiede una maggiore attenzione alla sicurezza della VM poiché direttamente esposta alla rete di appartenenza della macchina ospitante.