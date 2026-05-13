# Verifica di laboratorio di Sistemi e Reti

## Scenario

Un’azienda è suddivisa in 3 reparti:

- Reparto 1: 25 postazioni di lavoro
- Reparto 2: 45 postazioni di lavoro
- Reparto 3: 70 postazioni di lavoro

La rete utilizza un router-on-a-stick per la gestione dei gateway delle VLAN.

Il router dispone inoltre di:

- una interfaccia verso la WAN con NAPT
- una subnet pubblica /30
- una terza interfaccia collegata a una rete server

Nella rete server è presente un server che offre i seguenti servizi:

- HTTP
- HTTPS
- DNS
- FTP

## Regole di accesso

Utilizzando il tool già presentato durante le precedenti attività di laboratorio, esplicitare le ACL rispetto al seguente scenario, con sintassi *Cisco IOS like*:

- Gli ultimi 2 IP utilizzabili del Reparto 1 possono accedere a tutti i servizi del server.
- Tutto il Reparto 2 può accedere unicamente al servizio FTP.
- Tutto il Reparto 3 può accedere ai servizi HTTP e HTTPS, ad eccezione del primo IP utilizzabile.
- Unicamente i reparti 2 e 3 devono poter accedere a Internet tramite NAPT.

---

## Richieste

1. Disegnare lo schema generale della rete.
2. Definire un piano di indirizzamento IPv4, usando la tecnica VLSM o altro approccio risolutivo, esplicitando in maniera chiara e convincente le motivazioni alla base della scelta progettuale.
3. Indicare VLAN, gateway e subnet mask.
4. Definire le ACL necessarie per rispettare le regole di accesso al server.
5. Descrivere discorsivamente la configurazione logica del NAPT verso la WAN.

## EXTRA
Si richiede, inoltre, di descrivere possibili strategie di tolleranza ai guasti e ridondanza relative al server che eroga i servizi di rete nella subnet dedicata, valutando soluzioni a livello hardware, rete e/o servizi applicativi.