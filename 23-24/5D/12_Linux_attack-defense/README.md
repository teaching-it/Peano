#

## Esercizio 1: ARP Spoofing e rilevazione

### Scenario di attacco

- **Setup**: apri un terminale, ottieni i privilegi di amministratore.
- **Tool setup**: installa `arping` e `tcpdump` usando `apt-get install arping tcpdump`.
- **Attacco**: utilizza `arping` per inviare pacchetti ARP falsificati verso un dispositivo nella rete, cercando di associare il tuo MAC address all'indirizzo IP del gateway.
- **Monitoraggio attacco**: in un altro terminale, usa `tcpdump` (o meglio, `Wireshark`) per catturare il traffico ARP e osservare l'effetto del tuo attacco.

### Scenario di difesa

- **Setup difensivo**: avvia `tcpdump` (o meglio, `Wireshark`) per monitorare il traffico ARP.
- **Rilevazione**: identifica gli indirizzi MAC sospetti e verifica le modifiche non autorizzate alla cache ARP.
- **Misure di contenimento**: configura regole statiche ARP sul dispositivo target per prevenire cambiamenti.

### Approfondimento

L'attacco ARP Spoofing, come descritto nell'esercizio, può essere particolarmente pericoloso in diversi scenari in una rete aziendale o in altri ambienti organizzativi. 

- Intercezione di traffico di rete: l'ARP Spoofing può essere utilizzato per reindirizzare il traffico tra due parti attraverso il dispositivo dell'attaccante. Questo permette all'attaccante di ascoltare o modificare dati sensibili che transitano nella rete, come password, sessioni di accesso, dati finanziari e informazioni personali. L'intercettazione può avvenire in modo trasparente senza che le vittime si accorgano dell'attacco.

- Man-In-The-Middle (MITM) attack: con ARP Spoofing, un attaccante può posizionarsi tra due entità comunicanti, agendo come un proxy per ogni sessione di comunicazione. Questo permette non solo di intercettare, ma anche di alterare i dati inviati tra le due parti. Gli attacchi MITM possono essere utilizzati per manipolare transazioni, rubare credenziali, installare malware, o causare altre forme di danno.

- Denial of Service (DoS): l'attaccante può utilizzare ARP Spoofing per indirizzare il traffico di rete a un dispositivo inesistente o a se stesso senza inoltrarlo, causando un'interruzione dei servizi di rete per l'utente o il server target. Questo può essere utilizzato per rendere inaccessibili risorse critiche, come server web, database e altri servizi essenziali.

- "Sopravvento" sulla sessione (Session Hijacking): ARP Spoofing può facilitare il sopravvento su sessioni esistenti, permettendo all'attaccante di accedere a sessioni sicure, come quelle di e-commerce o servizi bancari, senza necessità di autenticazione, sfruttando le sessioni già autenticate dalla vittima.

- Riduzione della fiducia nella rete: gli attacchi ARP possono minare la fiducia generale nell'infrastruttura di rete di un'organizzazione. La frequente alterazione dei dati ARP può causare incertezze e difficoltà nel mantenere l'integrità e la sicurezza della rete, influenzando negativamente le operazioni quotidiane e la produttività.

## Esercizio 2: Simulazione e difesa da un Ping Flood

### Scenario di attacco

- **Setup**: apri un terminale, ottieni i privilegi di amministratore.
- **Installazione e attacco**: installa `hping3` con `apt-get install hping3`. Esegui un attacco Ping Flood su un indirizzo IP nella rete locale.
- **Monitoraggio attacco**: Utilizza `tcpdump` per monitorare i ping inviati e osservare l'effetto sull'host target.

### Scenario di difesa

- **Monitoraggio difensivo**: utilizzando `tcpdump` o `Wireshark`, monitora il traffico in ingresso sul dispositivo target.
- **Identificazione e mitigazione**: rileva l'aumento insolito dei pacchetti ICMP e implementa regole di rate limiting sul firewall per bloccare o limitare il traffico da IP sospetti.

### Approfondimento

Un attacco di tipo Ping Flood può essere particolarmente pericoloso in una rete locale in diverse situazioni specifiche:

- Saturazione della larghezza di banda: se una rete locale non dispone di sufficiente larghezza di banda, un Ping Flood può consumare rapidamente le risorse disponibili, rallentando o bloccando del tutto il traffico legittimo. Questo impedisce la normale operatività delle attività di rete, causando tempi di risposta lenti o interruzioni dei servizi (DoS).

- Sovraccarico dei dispositivi di rete: router, switch e firewall possono essere sovraccaricati da un alto volume di richieste ICMP (il protocollo utilizzato per i ping). Questo può portare a una gestione inefficace del traffico di rete, con possibili crash o riavvii dei dispositivi, compromettendo la stabilità della rete.

- Interruzione dei servizi essenziali: nelle reti dove sono ospitati servizi critici, come sistemi di controllo di accessi, telefonia IP, o sistemi di sicurezza, un Ping Flood può compromettere la disponibilità di questi servizi vitali, causando non solo perdite economiche, ma anche problemi di sicurezza e operatività.

- Distrazione da attacchi più gravi: a volte, un Ping Flood può essere usato come distrazione per mascherare attacchi più sofisticati o gravi. Mentre il team IT è impegnato a mitigare gli effetti del flood, gli attaccanti possono sfruttare altre vulnerabilità o esfiltrare dati sensibili.

- Esaurimento delle risorse del sistema: In sistemi meno robusti o mal configurati, anche un semplice Ping Flood può esaurire le risorse di sistema come CPU e memoria, portando al degrado delle prestazioni o alla completa indisponibilità del sistema.

- Impatto sulle connessioni remote: per le organizzazioni che dipendono fortemente da connessioni remote, come il telelavoro o l'accesso a risorse cloud attraverso la rete locale, un Ping Flood può rendere queste connessioni instabili o inutilizzabili, influenzando la produttività e l'efficienza operativa.

- Problemi di compliance e sicurezza: in ambienti regolamentati, come quelli finanziari o sanitari, la perdita di servizi di rete o la degradazione delle prestazioni possono portare a violazioni delle normative sulla disponibilità dei servizi e sulla protezione dei dati, con conseguenti sanzioni e danni alla reputazione.

## Esercizio 3: Simulazione e difesa da un SYN Flood

### Scenario di attacco

- **Setup**: apri un terminale, ottieni i privilegi di amministratore.
- **Installazione e attacco**: Installa `hping3` usando il comando `apt-get install hping3`. Prepara un attacco SYN flood specificando i dettagli del pacchetto, come segue: Esegui l'attacco su un host target nella tua rete locale con il comando `hping3 -c 10000 -d 120 -S -w 64 -p 80 --flood --rand-source [indirizzo-IP-target]`.
- **Monitoraggio attacco**: Utilizza `tcpdump` per monitorare i pacchetti SYN inviati al server e osserva l'effetto sull'host target, specificamente guardando l'aumento del traffico verso la porta 80.

## Scenario di difesa

- **Monitoraggio difensivo**: Utilizza `tcpdump` o `Wireshark` per monitorare il traffico in ingresso sul dispositivo target. Imposta un filtro per catturare solo il traffico TCP diretto alla porta 80 per vedere l'effetto dell'attacco.
- **Identificazione e mitigazione**: Rileva l'aumento insolito dei pacchetti SYN diretti alla porta 80. Implementa regole di rate limiting sul firewall `iptables` per bloccare o limitare il traffico da IP sospetti. Per gestire un SYN flood, puoi utilizzare regole `iptables` come:

### Approfondimento

Un attacco SYN Flood è una forma di attacco **Distributed Denial of Service (DDoS)** che può essere particolarmente dannoso in vari scenari, sfruttando il meccanismo di stabilimento delle connessioni TCP. Durante un attacco SYN Flood, l'attaccante invia rapidamente una grande quantità di pacchetti SYN verso un server target, senza completare la procedura di handshake TCP. Questo può portare a vari problemi significativi:

- Sovraccarico delle risorse del server: i server hanno una capacità limitata per gestire le connessioni simultanee. In un attacco SYN Flood, il server prova a tenere traccia di ogni richiesta di connessione incompleta allocando risorse per ciascuna di esse. Questo consumo di risorse può esaurire rapidamente la memoria disponibile, portando al sovraccarico del server e impedendogli di processare richieste legittime.

- Indisponibilità dei servizi: l'obiettivo principale di un attacco SYN Flood è rendere un servizio o un'applicazione inaccessibile agli utenti legittimi. Questo tipo di attacco può causare significative interruzioni operative, particolarmente dannose in ambienti aziendali dove servizi critici come server di database, applicazioni web e servizi di posta elettronica diventano irraggiungibili.

- Impatto sulle attività commerciali e finanziarie: per le aziende che dipendono dalla disponibilità online per le transazioni o la comunicazione con i clienti, un attacco SYN Flood può avere un impatto economico diretto. Interruzioni prolungate possono portare a perdita di vendite, danneggiamento della reputazione dell'azienda, e potenziale perdita di clienti.

- Debolezze di infrastruttura critica: organizzazioni che gestiscono infrastrutture critiche, come servizi sanitari, istituzioni finanziarie, e servizi di emergenza, possono essere particolarmente vulnerabili agli attacchi SYN Flood. L'interruzione di questi servizi può avere conseguenze gravi non solo per l'organizzazione stessa, ma anche per la sicurezza e il benessere della popolazione che dipende da questi servizi essenziali.

- Distrazione da altri attacchi: gli attacchi SYN Flood possono essere utilizzati come distrazione per deviare l'attenzione del personale di sicurezza da attacchi più sofisticati. Mentre il team di sicurezza è impegnato a mitigare l'attacco DDoS, gli attaccanti possono sfruttare altre vulnerabilità per infiltrarsi nella rete e rubare dati sensibili o causare altri danni.

## Esercizio 4: Scansione della rete e protezione delle porte

### Scenario di attacco

- **Setup**: apri un terminale, ottieni privilegi di amministratore.
- **Tool setup**: installa `nmap` usando `apt-get install nmap`.
- **Scansione**: utilizza `nmap` per eseguire una scansione delle porte sull'host da attaccato.
- **Analisi**: analizza quali servizi e porte sono aperti e pianifica teoricamente come potresti sfruttarli.

### Scenario di difesa

- **Monitoraggio difensivo**: utilizzando `tcpdump` o `Wireshark`, monitora il traffico in ingresso sul dispositivo target.
- **Preparazione difensiva**: utilizzando i risultati della scansione di `nmap` forniti dall'attaccante, identifica le vulnerabilità.
- **Hardening**: chiudi le porte non necessarie, rafforza le configurazioni dei servizi esposti, filtra l'accesso ai servizi definendo opportune regole di firewalling con `iptables`.

## Esercizio 5: Simulazione di un Server DHCP malevolo

### Scenario di attacco

- **Setup**: apri un terminale, ottieni privilegi di amministratore.
- **Installazione**: Installa `isc-dhcp-server` con `apt-get install isc-dhcp-server`. Configura il server DHCP.
- **Configurazione del server malevolo**: modifica il file `/etc/dhcp/dhcpd.conf` per creare una configurazione malevola che assegna gateway errati o DNS *spoofati*.
- **Avvio del server**: avvia il server DHCP con `service isc-dhcp-server start`.

### Scenario di difesa

- **Rilevamento**: Configura un altro dispositivo per monitorare le richieste DHCP nella rete usando `tcpdump` con il filtro `tcpdump -i eth0 port 67 or port 68 -e -n`.
- **Analisi e Risposta**: Identifica configurazioni sospette come gateway o DNS inusuali nei pacchetti DHCP Offer. Implementa filtri sul gateway per bloccare risposte DHCP non autorizzate.
- **Misure Preventive**: Configura gli switch di rete per permettere risposte DHCP solo dai server conosciuti e autorizzati.

### Approfondimento

L'uso di un server DHCP malevolo è un esempio di attacco man-in-the-middle che sfrutta la fiducia dei dispositivi nella rete per ottenere o alterare informazioni tramite l'assegnazione di configurazioni di rete errate. Un attaccante può utilizzare questo tipo di server per:

- **Deviazione del traffico**: Redirigendo tutto il traffico attraverso un dispositivo controllato dall'attaccante, è possibile intercettare, monitorare o manipolare i dati in transito.
- **Phishing e altri schemi di frode**: Redirigendo gli utenti a siti malevoli che imitano siti legittimi, l'attaccante può rubare credenziali o installare malware.
- **Denial of Service (DoS)**: Assegnando configurazioni di rete non funzionali, un attaccante può rendere una parte della rete inaccessibile.

#### Prevenzione di attacchi DHCP malevoli

Prevenire questo tipo di attacchi richiede una combinazione di misure tecniche e di policy:

- **Autenticazione del server DHCP**: Alcune reti implementano protocolli che richiedono l'autenticazione dei server DHCP prima che possano assegnare indirizzi IP.
- **Isolamento dei segmenti di rete**: Limitare la portata dei server DHCP a segmenti di rete specifici può prevenire la diffusione di configurazioni malevole a tutta la rete.
- **Monitoraggio continuo**: L'uso di strumenti come `tcpdump` per monitorare le risposte DHCP sulla rete può aiutare a identificare attività sospette.
- **Formazione e consapevolezza degli utenti**: Educare gli utenti sulla sicurezza della rete e sui potenziali segnali di un attacco DHCP può aiutare a riconoscere e segnalare anomalie.

## Esercizio 6: Man-In-The-Middle (MITM) attack

### Scenario di attacco

- **Setup**: Configura una macchina per agire come un gateway malevolo utilizzando `arpspoof` per deviare il traffico attraverso di essa.
- **Attacco**: Avvia l'arpspoofing con `arpspoof -i [interface] -t [target-IP] [gateway-IP]`.
- **Intercezione**: utilizza `tcpdump` per catturare e analizzare il traffico che passa attraverso il dispositivo attaccante.

### Scenario di difesa

- **Rilevazione di ARP Spoofing**: monitora la tabella ARP con `arp -a` per rilevare cambiamenti sospetti.
- **Misure di protezione**: configura il software IDS/IPS per rilevare e prevenire attacchi MITM.
- **Educazione e politiche**: conduci sessioni formative sulla sicurezza per educare gli utenti su come riconoscere e segnalare attività di rete sospette.
