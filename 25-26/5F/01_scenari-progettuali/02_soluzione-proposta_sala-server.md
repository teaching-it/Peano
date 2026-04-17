# Soluzione proposta – segmento progettuale sala server / locale tecnico / servers

## Sistemi e Reti 2025/2026 – Fac-simile traccia d’esame

## Introduzione

Nel progetto della rete di una azienda ospedaliera di medie dimensioni, la **sala server** rappresenta il cuore dell’infrastruttura informatica, perché ospita i sistemi che erogano i servizi più importanti: condivisione dei file, archiviazione dei referti clinici, autenticazione degli utenti, backup e accesso controllato ai dati.

In un contesto sanitario non è sufficiente che i servizi siano semplicemente funzionanti: essi devono essere anche **affidabili, sicuri, scalabili e disponibili nel tempo**, perché un malfunzionamento potrebbe compromettere il normale svolgimento delle attività mediche e amministrative.

Per questo motivo, il segmento relativo al locale tecnico deve essere progettato con particolare attenzione, separando i server dalla rete degli utenti e prevedendo soluzioni che facilitino la gestione, la protezione dei dati e la continuità del servizio.

---

## 1. Impostazione generale della sala server

Nel locale tecnico si collocano i principali apparati centrali dell’infrastruttura:

- il **router/firewall**;
- uno **switch di aggregazione** (switch aggregator/core);
- i **server fisici** su cui predisporre un ambiente di virtualizzazione;
- il **NAS** o sistema di storage per backup e archiviazione (si veda approfondimento in calce);
- eventuali **UPS** per garantire continuità elettrica.

Una soluzione coerente e semplice facilmente argomentabile consiste nell’adottare un **router con tre interfacce fisiche**, in modo da separare chiaramente i diversi ambiti di traffico:

- **una interfaccia verso Internet**;
- **una interfaccia verso la rete interna degli host**, collegata allo switch aggregator;
- **una interfaccia verso la rete server**, collegata a uno switch dedicato o direttamente al segmento server.

Questa scelta permette di organizzare meglio il traffico, aumentare la sicurezza e distinguere in modo ordinato la parte pubblica della rete dalla parte interna e dai servizi centrali.

---

## 2. Collegamento lato host e ruolo del router

Sul lato della rete interna si può prevedere un collegamento tra router e switch aggregator configurato in **trunk**, con gestione delle VLAN tramite **router-on-a-stick**.

In questo modo:

- lo switch aggregator raccoglie il traffico proveniente dai reparti;
- il router gestisce il traffico tra le diverse VLAN;
- ogni reparto può essere logicamente separato dagli altri;
- si mantiene una struttura ordinata e facilmente argomentabile;

Come discusso durante le attività di laboratorio, l’utilizzo di collegamenti in **fibra a 25 Gbps** tra apparati centrali rende questa scelta adeguata anche dal punto di vista prestazionale, poiché il backbone interno dispone di una capacità elevata e adatta a sostenere il traffico generato dai reparti e dai servizi centrali.

---

## 3. Organizzazione del segmento server

La rete server deve essere distinta dalla rete utenti, perché ospita risorse critiche e dati sensibili.

All’interno del locale tecnico si può quindi prevedere una **rete server dedicata**, nella quale collocare:

- i nodi fisici del cluster di virtualizzazione;
- le macchine virtuali GNU/Linux che erogano i servizi;
- il file server;
- il server web per accesso remoto controllato;
- il NAS per backup.

Questa separazione consente di:

- ridurre la superficie di esposizione dei sistemi più importanti;
- controllare meglio gli accessi;
- migliorare l’ordine progettuale;
- facilitare eventuali politiche di sicurezza e filtraggio.

---

## 4. Schema logico della soluzione proposta

Di seguito è riportato uno schema logico semplificato del segmento sala server.

```text
                           Internet
                               |
                       [ Router / Firewall ]
                      /          |           \
                     /           |            \
                    /            |             \
                 WAN      LAN utenti/VLAN      Rete server
                                 |                      |
                                 |                      |
                    [ Switch aggregator ]           [ Switch server ]
                      /         |         \             /    |     \
                     /          |          \           /     |      \
                    /           |           \         /      |       \
              Reparto A    Reparto B    Reparto C  Proxmox1 Proxmox2 NAS
                                                      |        |
                                                      |        |
                                                   VM Linux e servizi
```

Lo schema evidenzia che il router/firewall si trova al centro delle comunicazioni principali e svolge tre funzioni fondamentali:

- connessione verso Internet;
- instradamento e controllo del traffico interno;
- separazione della rete server dalla rete host.

---

## 5. Soluzione server proposta

Per garantire affidabilità e flessibilità, si propone di installare **almeno due server fisici** configurati come **piccolo cluster Proxmox** (rispetto a Proxmox si prenda visione dell'approfondimento in calce).

Questa scelta è particolarmente adatta perché consente di:

- ospitare più servizi su macchine virtuali separate;
- semplificare la gestione dell’infrastruttura;
- ridurre il numero di server fisici necessari;
- migliorare la continuità operativa in caso di guasto di un nodo.

### Servizi previsti sulle macchine virtuali

Le VM Linux possono essere organizzate in modo da distribuire i diversi servizi:

- **VM file server SMB** per offrire uno spazio di archiviazione privato al personale sanitario, nonché per consentire la condivisione interna dei documenti tra operatori autorizzati (rispetto al protocollo SMB, è presente un approfondimento in calce).
- **VM web server** per consentire l’accesso remoto ai referti tramite autenticazione;
- **VM per autenticazione e gestione utenti** (richiederebbe un approfondimento specifico, magari avremo modo di discuterne nelle prossime settimane).

La virtualizzazione permette di separare logicamente i servizi senza dover acquistare un server fisico per ogni funzione. In questo modo la rete risulta più ordinata, più semplice da amministrare e più facile da espandere in futuro.

---

## 6. Caratteristiche hardware dei server

I server fisici devono avere caratteristiche adeguate a un ambiente professionale e a un contesto sanitario, nel quale l’affidabilità è essenziale.

Una configurazione coerente può essere la seguente:

- processore **Intel Xeon** o equivalente di classe server;
- **64 GB di RAM**;
- supporto alla virtualizzazione hardware;
- storage interno su dischi SSD o SAS di classe enterprise;
- **alimentatore ridondato**;
- almeno **2 o 4 interfacce di rete** ad alta velocità (meglio se in fibra ottica);

Queste caratteristiche si giustificano nel seguente modo:

- il processore server-grade garantisce stabilità e continuità di funzionamento;
- più interfacce di rete consentono di separare traffico di servizio, gestione e backup;
- l’alimentatore ridondato aumenta l’affidabilità del sistema.

---

## 7. Accesso ai file clinici e ai referti

Il progetto prevede due modalità principali di accesso ai dati, differenti in base al tipo di utente.

### Accesso interno

Per il personale ospedaliero si utilizza un **file server SMB** collocato nella rete server interna. Questo servizio consente di:

- centralizzare l’archiviazione dei referti (spazio di archiviazione privato per ciascun utente);
- condividere cartelle e documenti tra utenti autorizzati;
- applicare permessi differenziati in base al ruolo;

### Accesso remoto

Per gli utenti (clienti) che devono consultare i propri referti dall’esterno, si prevede un **server web** che fornisca accesso tramite autenticazione.

L’accesso remoto avviene attraverso:

- **HTTPS**;
- pubblicazione controllata del servizio tramite **NAT statico** o **port forwarding** sul router/firewall;
- regole di filtraggio (ACL) che consentano solo il traffico necessario.

In questo modo l’utente esterno non accede direttamente al file server SMB, ma utilizza un servizio web più controllato, più semplice da proteggere e più coerente con un contesto sanitario.

---

## 8. Indirizzamento IP del segmento server

Per la rete server si può adottare una sottorete privata dedicata, ad esempio una **/28**, sufficiente per una piccola server farm.

### Proposta di rete server

| Voce | Valore |
|---|---|
| Rete | 192.168.40.0 |
| Prefisso | /28 |
| Subnet mask | 255.255.255.240 |
| Gateway | 192.168.40.14 |
| Range host utilizzabili | 192.168.40.1 - 192.168.40.13 |
| Broadcast | 192.168.40.15 |

### Possibile assegnazione degli indirizzi

| Dispositivo / Servizio | Indirizzo IP |
|---|---|
| Gateway rete server | 192.168.40.14 |
| Nodo Proxmox 1 | 192.168.40.2 |
| Nodo Proxmox 2 | 192.168.40.3 |
| VM File Server SMB | 192.168.40.4 |
| VM Web Server referti | 192.168.40.5 |
| VM autenticazione / directory | 192.168.40.6 |
| NAS backup | 192.168.40.7 |

Questa scelta permette una numerazione ordinata, semplice da gestire e sufficiente per i dispositivi previsti nel locale tecnico.

---

## 9. Collegamento a Internet e pubblicazione dei servizi

Il router/firewall si collega alla connettività Internet in fibra ottica simmetrica a **10 Gbps** fornita dall’operatore.

Per la pubblicazione dei servizi esterni, il provider può assegnare:

- un singolo **IP pubblico**, nel caso in cui si utilizzi il NAT verso il server web;
- oppure una piccola rete pubblica, ad esempio **/30** o **/29**, se si desidera una maggiore flessibilità.

Dal punto di vista progettuale, è importante specificare che:

- il router possiede almeno una interfaccia WAN con indirizzamento pubblico;
- il traffico in ingresso viene filtrato (firewall policies/ACL);
- solo il servizio web necessario per la consultazione dei referti viene pubblicato verso l’esterno;
- le altre risorse della rete server restano private.

Questa scelta migliora la sicurezza e mantiene un corretto livello di controllo sui servizi esposti.

---

## 10. Switch del segmento server

Accanto ai server è opportuno installare uno **switch dedicato al segmento server**, separato da quello utilizzato per gli utenti.

### Caratteristiche consigliate

- managed switch;
- supporto **VLAN**;
- almeno **8 o 16 porte Ethernet** (meglio se in fibra);
- supporto a velocità elevate, ad esempio **10/25 Gbps** per i collegamenti centrali;
- throughput complessivo (caratteristiche prestazionali) adeguato al traffico dei server e dei backup.

### Motivazione tecnica

Lo switch dedicato ai server consente di:

- mantenere ordinato il cablaggio della sala server;
- separare il traffico dei server dal traffico delle postazioni di lavoro;
- collegare in modo efficiente cluster, NAS e apparati centrali;
- predisporre eventuali espansioni future.

---

## 11. NAS dedicato e strategia di backup

Per proteggere i dati è necessario affiancare ai server una **unità NAS dedicata** alle copie di sicurezza.

Il NAS svolge funzioni molto importanti:

- conserva i backup delle macchine virtuali;
- conserva copie dei dati clinici e amministrativi;
- permette il ripristino dei servizi in caso di errore o guasto;
- contribuisce alla continuità operativa.

I backup devono essere eseguiti in modo pianificato e automatico, ad esempio:

- backup giornalieri incrementali;
- backup completi periodici;
- conservazione di più versioni;
- eventuale copia esterna o offline per maggiore sicurezza.

È importante sottolineare che il backup è un elemento essenziale soprattutto in ambiente sanitario, dove la perdita di dati può avere conseguenze gravi sia sul piano organizzativo sia sul piano della tutela delle informazioni sensibili.

---

## 12. Continuità del servizio nel locale tecnico

La continuità operativa è uno degli obiettivi principali del progetto. Per questo motivo il segmento server deve essere progettato con criteri di affidabilità.

### Soluzioni adottate

- **due server fisici** nel cluster, così da non dipendere da una sola macchina;
- **alimentatori ridondati**;
- **NAS dedicato** per i backup;
- **UPS** per proteggere da blackout e sbalzi di tensione;
- separazione logica tra rete utenti e rete server;
- pubblicazione controllata dei soli servizi necessari verso Internet.

### Benefici

Queste scelte permettono di ottenere:

- riduzione dei tempi di fermo;
- maggiore disponibilità dei servizi;
- migliore protezione dei dati clinici;
- maggiore continuità delle attività sanitarie e amministrative.

In particolare, la presenza di due nodi fisici rende possibile il ripristino dei servizi virtualizzati su un nodo alternativo in caso di guasto, limitando l’impatto operativo.

---

## 13. Recap

Il segmento progettuale della sala server deve essere realizzato come un’area separata e protetta dell’infrastruttura di rete. La scelta di un router/firewall con tre interfacce fisiche, di uno switch dedicato ai server, di due server fisici in cluster Proxmox e di un NAS per i backup costituisce una soluzione tecnicamente valida e ben motivabile.

Tale proposta è particolarmente adatta a una struttura ospedaliera, perché garantisce ordine progettuale, controllo degli accessi, affidabilità dei servizi e maggiore continuità operativa. Inoltre, l’uso della virtualizzazione e della segmentazione logica rende il sistema facilmente espandibile e più semplice da amministrare nel tempo.

---

## 14. Approfondimenti

### 14.1 Nota sul RAID

Il tema del **RAID** può essere citato come elemento aggiuntivo, anche se non costituisce il nucleo principale del progetto di rete.

Il RAID è una tecnica che utilizza più dischi per migliorare affidabilità e, in alcuni casi, prestazioni. In ambito server le soluzioni più note sono:

- **RAID 0**, che distribuisce i dati su più dischi per aumentare le prestazioni, ma non offre ridondanza;
- **RAID 1**, basato sulla duplicazione dei dati su due dischi;
- **RAID 5**, che utilizza parità distribuita;
- **RAID 10**, che combina mirroring e striping.

Un esempio semplice di **RAID 1** è il seguente: se un server dispone di **due dischi da 1 TB**, i dati vengono scritti in modo identico su entrambi. In questo caso, la capacità utile rimane **1 TB** e non 2 TB, perché il secondo disco contiene una copia speculare del primo. Se uno dei due dischi si guasta, il server può continuare a funzionare utilizzando l’altro disco, senza perdita immediata dei dati.

È però importante specificare che **il RAID non è un sistema di backup**. Il RAID protegge dal guasto fisico di un disco, ma non da cancellazioni accidentali, errori umani, virus, ransomware o corruzione dei file. Per questo motivo, anche in presenza di RAID, resta comunque necessario prevedere copie di sicurezza su NAS o su altri sistemi dedicati al backup.

A margine, si può quindi aggiungere che i server possono essere dotati di dischi configurati in RAID per aumentare la tolleranza ai guasti, precisando però che questo aspetto costituisce un approfondimento hardware accessorio rispetto alla progettazione della rete.

### 14.2 Nota sul protocollo SMB

Per la condivisione interna dei file tra medici, personale amministrativo e server, il protocollo più adatto è **SMB** (**Server Message Block**).

SMB è pensato specificamente per la **condivisione di file e cartelle in rete locale** e permette di:

- accedere a cartelle condivise come se fossero risorse del proprio computer;
- gestire utenti, gruppi e permessi di accesso;
- integrare il servizio con sistemi Windows e Linux.

Rispetto ad **HTTP**, SMB è più adatto quando si vuole offrire una vera condivisione di rete interna, perché HTTP è nato soprattutto per la pubblicazione e consultazione di contenuti web tramite browser.

Rispetto a **FTP**, SMB risulta più comodo nella normale operatività d’ufficio, perché non serve solo a trasferire file, ma a lavorare direttamente su cartelle condivise con una gestione più naturale dei permessi e delle risorse di rete.

Un eventuale accesso remoto da parte di utenti esterni, come detto, può essere affidato a un servizio web dedicato.

### 14.3 Nota su Proxmox

Proxmox Virtual Environment è una piattaforma open source per la virtualizzazione che consente di gestire macchine virtuali e container su server fisici. È particolarmente adatta in ambito professionale perché integra in un’unica soluzione strumenti per la gestione delle risorse hardware, dello storage e della rete.

Proxmox si basa su tecnologie consolidate:

- **KVM (Kernel-based Virtual Machine)** per la virtualizzazione completa delle macchine;
- **LXC (Linux Containers)** per la virtualizzazione leggera tramite container;

Tra le principali funzionalità si possono evidenziare:

- creazione e gestione di **macchine virtuali** con sistemi operativi diversi;
- interfaccia **web centralizzata** per l’amministrazione;
- gestione di **cluster** di più nodi fisici;
- supporto a **snapshot e backup** delle VM;
- possibilità di migrazione delle macchine virtuali tra nodi (live migration, se supportata);

Nel contesto del progetto, l’utilizzo di Proxmox permette di:

- consolidare più servizi su un numero ridotto di server fisici;
- separare logicamente i diversi servizi (file server, web server, autenticazione);
- semplificare la gestione e la manutenzione;
- migliorare la continuità operativa grazie alla presenza di più nodi nel cluster;

Ad esempio, se uno dei due server fisici si guasta, le macchine virtuali possono essere riavviate sull’altro nodo, riducendo il tempo di interruzione dei servizi.

È importante sottolineare che, pur offrendo strumenti di backup integrati, Proxmox non sostituisce una strategia di backup esterna: resta necessario salvare i dati anche su un NAS o su sistemi dedicati, come già previsto nel progetto.

### 14.4 Nota sul NAS

Il **NAS (Network Attached Storage)** è un dispositivo di archiviazione collegato direttamente alla rete, progettato per conservare e condividere dati in modo centralizzato tra più sistemi.

A differenza di un semplice disco esterno, il NAS è dotato di un proprio sistema operativo e può essere gestato tramite interfaccia web, rendendolo un elemento attivo dell’infrastruttura di rete.

Le principali caratteristiche di un NAS sono:

- accesso ai dati tramite rete (LAN);
- supporto a protocolli di condivisione come **SMB**, NFS o FTP;
- gestione di utenti e permessi;
- possibilità di configurare dischi in **RAID** per aumentare l’affidabilità;
- esecuzione di backup automatici e pianificati;

Nel contesto del progetto, il NAS svolge un ruolo fondamentale perché:

- conserva i **backup delle macchine virtuali**;
- mantiene copie dei **dati clinici e amministrativi**;
- consente il **ripristino dei servizi** in caso di guasto o errore;
- contribuisce alla continuità operativa dell’infrastruttura;

Ad esempio, è possibile configurare il sistema in modo che ogni notte vengano salvate copie aggiornate delle VM presenti nel cluster, riducendo il rischio di perdita dei dati.

È importante sottolineare che il NAS non sostituisce completamente altre strategie di sicurezza: per una protezione più completa, è consigliabile prevedere anche copie **off-site** o offline.

### 14.5 Nota sulla sicurezza nell’accesso ai dati tramite web server

Nel progetto proposto, il server web esposto verso Internet consente agli utenti esterni di consultare i referti, accedendo ai dati memorizzati nel file server interno basato su protocollo SMB. Questa soluzione è funzionalmente corretta, ma introduce alcune considerazioni rilevanti dal punto di vista della sicurezza.

Il principale rischio è legato al fatto che il web server rappresenta un punto di contatto tra l’esterno e la rete interna: in caso di compromissione del servizio web (ad esempio per vulnerabilità applicative o credenziali deboli), un attaccante potrebbe tentare di accedere indirettamente al file server, con conseguente esposizione di dati sensibili.

Per ridurre questo rischio è opportuno adottare alcune misure progettuali:

- separare logicamente il web server dalla rete server interna, ad esempio tramite una **DMZ (zona demilitarizzata)**;
- tale separazione può essere realizzata predisponendo una **quarta interfaccia del router/firewall** (anche logica, ad esempio tramite VLAN), sulla quale collegare il web server e definire una **sottorete dedicata**;
- limitare le comunicazioni tra web server e file server alle sole porte e ai soli servizi strettamente necessari;
- utilizzare account dedicati con **permessi minimi** per l’accesso ai dati;
- evitare, quando possibile, l’accesso diretto via SMB, preferendo meccanismi intermedi più controllati;
- applicare politiche di sicurezza sul firewall e mantenere aggiornato il server web;

Queste soluzioni permettono di mantenere la funzionalità del sistema, riducendo al tempo stesso la superficie di attacco e migliorando la protezione dei dati clinici.

### 14.6 Nota sui servizi DHCP e DNS

All’interno dell’infrastruttura di rete è necessario prevedere anche i servizi di configurazione automatica degli host e di risoluzione dei nomi, rispettivamente DHCP e DNS.

Il servizio **DHCP (Dynamic Host Configuration Protocol)** può essere erogato direttamente dal router/firewall, in quanto questo dispositivo è sempre attivo e già coinvolto nella gestione delle VLAN e dell’instradamento del traffico. In questo modo è possibile assegnare automaticamente gli indirizzi IP ai client delle diverse sottoreti, semplificando la configurazione e la gestione della rete.

Il servizio **DNS (Domain Name System)** può invece essere collocato su una macchina virtuale nella rete server, così da gestire la risoluzione dei nomi all’interno dell’infrastruttura (ad esempio per raggiungere i server tramite nomi simbolici anziché indirizzi IP). Il DNS interno può inoltre essere configurato per inoltrare (forwarding) le richieste verso server DNS pubblici per la risoluzione dei nomi esterni.

Dal punto di vista della sicurezza e dell’organizzazione, è importante che:

- il DNS interno non sia esposto direttamente verso Internet;
- il servizio DHCP sia limitato alle reti interne e non venga esteso alla DMZ.

### 14.7 Nota sul sistema operativo del router/firewall (pfSense)

Il router/firewall rappresenta un elemento centrale dell’infrastruttura di rete e può essere realizzato non solo tramite dispositivi hardware dedicati, ma anche attraverso soluzioni software installate su sistemi standard.

Una delle soluzioni più diffuse in ambito professionale è **pfSense**, un sistema operativo open source basato su FreeBSD, progettato specificamente per svolgere funzioni di routing e firewalling.

pfSense offre numerose funzionalità integrate, tra cui:

- firewall con gestione avanzata delle regole (ACL);
- supporto al **NAT** e al port forwarding;
- gestione di **VLAN** e interfacce multiple;
- server **DHCP** e funzionalità di base per il DNS;
- supporto a **VPN** (ad esempio OpenVPN e IPsec);
- interfaccia web per la configurazione e il monitoraggio;

Nel contesto del progetto, l’utilizzo di pfSense consente di implementare un router/firewall flessibile e facilmente configurabile, in grado di gestire le diverse reti (LAN utenti, rete server, eventuale DMZ) anche tramite interfacce logiche basate su VLAN.

È importante sottolineare che, pur essendo una soluzione software, pfSense offre livelli di affidabilità e sicurezza adeguati anche a contesti professionali, a condizione che venga eseguito su hardware idoneo e correttamente configurato. A questo proposito, **Netgate**, azienda che sviluppa e supporta pfSense, propone anche soluzioni hardware dedicate e certificate, progettate per garantire prestazioni e affidabilità in ambito professionale.