# Soluzione proposta – segmento progettuale sala server / locale tecnico / servers

## Sistemi e Reti 2025/2026 – Fac-simile traccia d’esame

## Introduzione

Nel progetto della rete di una azienda ospedaliera di medie dimensioni, la **sala server** rappresenta il cuore dell’infrastruttura informatica, perché ospita i sistemi che erogano i servizi più importanti: condivisione dei file, archiviazione dei referti clinici, autenticazione degli utenti, backup e accesso controllato ai dati.

In un contesto sanitario non è sufficiente che i servizi siano semplicemente funzionanti: essi devono essere anche **affidabili, sicuri, scalabili e disponibili nel tempo**, perché un malfunzionamento potrebbe compromettere il normale svolgimento delle attività mediche e amministrative.

Per questo motivo, il segmento relativo al locale tecnico deve essere progettato con particolare attenzione, separando i server dalla rete degli utenti e prevedendo soluzioni che facilitino la gestione, la protezione dei dati e la continuità del servizio.

---

## 1. Impostazione generale della sala server

Nel locale tecnico si collocano i principali apparati centrali dell’infrastruttura:

- il **router/firewall** verso Internet;
- uno **switch di aggregazione** o switch centrale;
- i **server fisici** dedicati alla virtualizzazione;
- il **NAS** o sistema di storage per backup e archiviazione;
- eventuali **UPS** per garantire continuità elettrica.

Una soluzione coerente e semplice da motivare consiste nell’adottare un **router con tre interfacce fisiche**, in modo da separare chiaramente i diversi ambiti di traffico:

- **una interfaccia verso Internet**;
- **una interfaccia verso la rete interna degli host**, collegata allo switch di aggregazione;
- **una interfaccia verso la rete server**, collegata a uno switch dedicato o direttamente al segmento server.

Questa scelta permette di organizzare meglio il traffico, aumentare la sicurezza e distinguere in modo ordinato la parte pubblica della rete dalla parte interna e dai servizi centrali.

---

## 2. Collegamento lato host e ruolo del router

Sul lato della rete interna si può prevedere un collegamento tra router e switch di aggregazione configurato in **trunk**, con gestione delle VLAN tramite **router-on-a-stick**.

In questo modo:

- lo switch di aggregazione raccoglie il traffico proveniente dai reparti;
- il router gestisce il traffico tra le diverse VLAN;
- ogni reparto può essere logicamente separato dagli altri;
- si mantiene una struttura ordinata e facilmente spiegabile in sede d’esame.

Come discusso durante le attività di laboratorio, l’utilizzo di collegamenti in **fibra a 25 Gbps** tra apparati centrali rende questa scelta adeguata anche dal punto di vista prestazionale, poiché il backbone interno dispone di una capacità elevata e adatta a sostenere il traffico generato dai reparti e dai servizi centrali.

---

## 3. Organizzazione del segmento server

La rete server deve essere distinta dalla rete utenti, perché ospita risorse critiche e dati sensibili.

All’interno del locale tecnico si può quindi prevedere una **rete server dedicata**, nella quale collocare:

- i nodi fisici del cluster di virtualizzazione;
- le macchine virtuali Linux che erogano i servizi;
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
                                 |                  |
                                 |                  |
                    [ Switch aggregator ]   [ Switch server ]
                      /         |         \         /    |     \
                     /          |          \       /     |      \
                    /           |           \     /      |       \
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

Per garantire affidabilità e flessibilità, si propone di installare **almeno due server fisici** configurati come **piccolo cluster Proxmox**.

Questa scelta è particolarmente adatta perché consente di:

- ospitare più servizi su macchine virtuali separate;
- semplificare la gestione dell’infrastruttura;
- ridurre il numero di server fisici necessari;
- migliorare la continuità operativa in caso di guasto di un nodo.

### Servizi previsti sulle macchine virtuali

Le VM Linux possono essere organizzate in modo da distribuire i diversi servizi:

- **VM file server SMB** per offrire uno spazio di archiviazione privato al personale sanitario, nonché per consentire la condivisione interna dei documenti tra operatori autorizzati;
- **VM web server** per consentire l’accesso remoto ai referti tramite autenticazione;
- **VM per autenticazione e gestione utenti**, se prevista;

La virtualizzazione permette di separare logicamente i servizi senza dover acquistare un server fisico per ogni funzione. In questo modo la rete risulta più ordinata, più semplice da amministrare e più facile da espandere in futuro.

---

## 6. Caratteristiche hardware dei server

I server fisici devono avere caratteristiche adeguate a un ambiente professionale e a un contesto sanitario, nel quale l’affidabilità è essenziale.

Una configurazione coerente può essere la seguente:

- processore **Intel Xeon** o equivalente di classe server;
- **64 GB di RAM ECC**;
- supporto alla virtualizzazione hardware;
- storage interno su dischi SSD o SAS di classe enterprise;
- **alimentatore ridondato**;
- almeno **2 o 4 interfacce di rete** ad alta velocità (possibilmente in fibra ottica);

Queste caratteristiche si giustificano nel seguente modo:

- la **RAM ECC** riduce il rischio di errori in memoria;
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
- regole di filtraggio che consentano solo il traffico necessario.

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
- il traffico in ingresso viene filtrato;
- solo il servizio web necessario per la consultazione dei referti viene pubblicato verso l’esterno;
- le altre risorse della rete server restano private.

Questa scelta migliora la sicurezza e mantiene un corretto livello di controllo sui servizi esposti.

---

## 10. Switch del segmento server

Accanto ai server è opportuno installare uno **switch dedicato al segmento server**, separato da quello utilizzato per gli utenti.

### Caratteristiche consigliate

- switch gestito;
- supporto **VLAN**;
- almeno **8 o 16 porte Ethernet** (meglio se in fibra);
- supporto a velocità elevate, ad esempio **10/25 Gbps** per i collegamenti centrali;
- throughput complessivo adeguato al traffico dei server e dei backup.

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