# Sistemi e Reti 2025/2026 - Fac-simile traccia d'esame

## Scenario

Una azienda ospedaliera di medie dimensioni è costituita da tre reparti:

-   Reparto A
-   Reparto B
-   Reparto C

In ciascun reparto sono presenti almeno 45 Postazioni di Lavoro (PDL)
tra PC del personale sanitario, amministrativo e postazioni di
consultazione.

L'ospedale dispone di:

-   Connettività Internet in fibra ottica simmetrica a 10 Gbps
-   Un centro stella ubicato in un locale dedicato
-   Un'infrastruttura server che eroga servizi di file server

I medici necessitano inoltre di uno spazio di archiviazione
centralizzato, efficiente e affidabile per la condivisione dei referti
clinici, con accesso controllato, privilegi differenziati, ad alta
disponibilità.

L'obiettivo è progettare l'infrastruttura di rete garantendo
scalabilità, sicurezza, continuità operativa e protezione dei dati.

------------------------------------------------------------------------

## Richieste

Il candidato, dopo aver eventualmente formulato ipotesi aggiuntive
ritenute utili, sviluppi i seguenti punti.

### 1. Progettazione logica e fisica della rete

-   Definire l'architettura complessiva
-   Realizzare uno schema di rete che includa:
    -   Centro stella/core
    -   Switch di accesso dei reparti
    -   Server e sistema di storage
    -   Collegamento a Internet
-   Indicare la topologia adottata e motivarne la scelta in termini di:
    -   Scalabilità
    -   Prestazioni
    -   Affidabilità

------------------------------------------------------------------------

### 2. Piano di indirizzamento IP

Progettare un piano IPv4 privato che includa:

-   Una sottorete per ciascun reparto
-   Una rete server
-   Una rete per lo storage/servizi di archiviazione

Per ogni rete indicare:

-   Indirizzo di rete
-   Prefisso
-   Range host
-   Gateway
-   Altro

------------------------------------------------------------------------

### 3. Scelta tecnica dei dispositivi

Indicare tipologia e caratteristiche di:

-   Switch di accesso
-   Switch di core
-   Router/Firewall
-   Server e storage

Specificare almeno:

-   Livello OSI
-   Numero e tipo di porte
-   Supporto VLAN
-   Capacità di throughput (Gbps)

------------------------------------------------------------------------

### 5. Mezzi trasmissivi e velocità

Definire:

-   Mezzi trasmissivi tra core e reparti
-   Mezzi tra switch e PDL
-   Collegamento server-core
-   Collegamento Internet

Specificare:

-   Tipologia di cavo
-   Standard
-   Velocità
-   Motivazioni tecniche

------------------------------------------------------------------------

### 6. Ridondanza e continuità del servizio

Analizzare le soluzioni per garantire alta disponibilità e resilienza:

-   Ridondanza dei collegamenti di rete
-   Ridondanza degli apparati (core, storage, alimentazioni)
-   Tecniche di failover
-   Backup dei dati e disaster recover

Valutare i benefici in termini di:

-   Riduzione dei tempi di fermo
-   Integrità dei dati
-   Continuità delle attività sanitarie

------------------------------------------------------------------------

## Output richiesto

L'elaborato dovrà contenere:

-   Schema logico/fisico della rete
-   Tabelle del piano di indirizzamento
-   Descrizione della soluzione di storage
-   Analisi della continuità del servizio
-   Motivazioni tecniche delle scelte

------------------------------------------------------------------------

**Ovviamente... CALMA E SANGUE FREDDO ;-)**

Non tutte le informazioni sono fornite in modo completo: è normale.\
Lo scopo della prova è valutare la capacità di usare le conoscenze
acquisite e applicarle a un contesto nuovo.

Non esiste un'unica soluzione corretta: conta la coerenza tecnica delle scelte e la loro giustificazione!
