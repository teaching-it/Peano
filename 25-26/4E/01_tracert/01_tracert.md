# Analisi tecnica di TRACERT (Traceroute)

## Obiettivo
Comprendere e interpretare l’output del comando `tracert` per analizzare:
- percorso dei pacchetti
- latenza (RTT)
- attraversamento di rete (AS)
- eventuali anomalie (timeout, variazioni RTT)

---

# Cos’è TRACERT
`tracert` (Windows) / `traceroute` (Linux) è un comando che mostra il percorso dei pacchetti IP verso una destinazione.

Funzionamento:
- invia pacchetti con TTL crescente
- ogni router decrementa il TTL
- quando TTL = 0 → invia risposta ICMP Time Exceeded

---

# Struttura dell’output

Esempio:

| Hop | RTT 1 | RTT 2 | RTT 3 | Indirizzo / Note        |
|-----|------|------|------|--------------------------|
| 1   | <1 ms | <1 ms | <1 ms | 192.168.1.1             |
| 2   | 10 ms | 12 ms | 11 ms | 10.0.0.1                |
| 3   | 25 ms | 30 ms | 28 ms | 151.6.1.254             |
| 4   | *     | *     | *     | Request timed out       |
| 5   | 40 ms | 42 ms | 39 ms | 8.8.8.8                 |


---

# Elementi da analizzare

## 1. Hop (salti)
- ogni riga = un router attraversato
- numero iniziale = ordine del percorso

Esempio: il pacchetto attraversa 5 hop prima di arrivare a destinazione.

---

## 2. RTT (Round Trip Time)
- tempo di andata e ritorno (ms)
- 3 misurazioni per ogni hop

Valori indicativi:
- <1 ms → rete locale  
- 10–30 ms → rete nazionale  
- \>50 ms → tratte lunghe  
- \>100 ms → rete internazionale  

---

## 3. Andamento della latenza

- normalmente cresce con la distanza  
  (maggiore distanza fisica → aumento del tempo di propagazione del segnale)

- aumenti improvvisi possono indicare:  
  - collegamenti WAN  
    (passaggio da rete locale/nazionale a rete geografica con maggiore latenza) 
  - attraversamento AS  
    (cambio di operatore/rete con possibili instradamenti meno diretti o politiche diverse)  
  - congestione  
    (saturazione temporanea dei link con aumento dei tempi di attraversamento)

---

## 4. Indirizzi IP
- IP privati → rete locale  
  - 192.168.x.x  
  - 10.x.x.x  
- IP pubblici → ISP / Internet  

---

## 5. Autonomous Systems (AS)
Un AS è una rete gestita da un unico operatore.

Indicatori:
- cambio di dominio (DNS)  
- cambio prefisso IP  

Strumenti di verifica:
- whois  
  (consente di identificare a quale organizzazione/ISP appartiene un indirizzo IP e quindi individuare il relativo AS)

Esempio: passaggio da rete locale a ISP e successivamente a backbone internazionale, verificabile anche tramite interrogazioni whois sugli IP intermedi.

---

## 6. Request timed out

Request timed out


Significato:
- il router NON risponde a ICMP  

Possibili cause:
- firewall  
- filtraggio ICMP  
- limitazione risposte  
- congestione

Importante:
- se gli hop successivi rispondono → rete OK  

---

## 7. Valori "*"
- perdita di risposta ICMP  
- non sempre indica errore  

---

# RTT NON monotono (caso importante)

Esempio:

| Hop | RTT 1 | RTT 2 | RTT 3 |
|-----|------|------|------|
| 3   | 20 ms | 22 ms | 21 ms |
| 4   | 80 ms | 85 ms | 82 ms |
| 5   | 25 ms | 27 ms | 26 ms |

Interpretazione:
- non è necessariamente congestione  
- il router 4 potrebbe rispondere lentamente ma inoltrare i pacchetti rapidamente (le risposte ICMP Time Exceeded possono avere priorità inferiore rispetto al forwarding)

Cause:
- ICMP non prioritario  
- CPU router  
- rate limiting  
- routing asimmetrico  

Regola: se il valore torna basso è improbabile che si tratti di congestione reale della rete.

---

# Congestione di rete

## Caso reale di congestione o distanza

| Hop | RTT 1 | RTT 2 | RTT 3 |
|-----|------|------|------|
| 6   | 30 ms | 32 ms | 31 ms |
| 7   | 120 ms | 125 ms | 123 ms |
| 8   | 118 ms | 121 ms | 119 ms |
| 9   | 122 ms | 124 ms | 123 ms |

Interpretazione:
- aumento stabile → reale incremento RTT  

Possibili cause:
- distanza geografica  
- collegamento WAN  
- congestione
- attraversamento AS

---

## Distinzione fondamentale

| Situazione | Interpretazione |
|-----------|----------------|
| RTT alto in un solo hop | Probabile risposta ICMP lenta del router (non rappresenta il reale tempo di attraversamento dei pacchetti) |
| RTT alto poi basso | Non indica congestione: il ritardo è locale al router che risponde lentamente, mentre il traffico prosegue normalmente |
| RTT alto persistente | Indica un reale aumento della latenza: può essere dovuto a distanza geografica, collegamenti WAN o possibile congestione |
| RTT alto + packet loss | Forte indicatore di congestione o saturazione del link, con impatto reale sul traffico |

---

# Confronto TRACERT vs PING

## Obiettivo
Capire se:
- il forwarding è lento  
- oppure solo le risposte ICMP  

---
## Caso 1: tracert alto, ping basso

tracert:

| Hop | RTT 1 | RTT 2 | RTT 3 |
|-----|------|------|------|
| 7   | 120 ms | 125 ms | 123 ms |
| 8   | 30 ms  | 32 ms  | 31 ms  |

ping:

| RTT 1 | RTT 2 | RTT 3 | Media |
|------|------|------|-------|
| 30 ms | 31 ms | 29 ms | ~30 ms |

Interpretazione:
- forwarding veloce  
- ICMP lento  

Motivazioni:
- il valore elevato all’hop 7 riguarda la risposta ICMP Time Exceeded, non il traffico reale  
- i router inoltrano i pacchetti (forwarding) in hardware e con alta priorità  
- le risposte ICMP sono gestite dalla CPU e possono avere priorità inferiore  
- il router può applicare limitazioni (rate limiting) alle risposte ICMP  
- il ritorno a valori normali all’hop successivo e nel ping conferma che il percorso reale non è lento  

Ricapitolando: l’anomalia è legata alla risposta del router, non alla qualità del collegamento di rete.

---

## Caso 2: tracert alto persistente + ping alto

tracert:

| Hop | RTT 1 | RTT 2 | RTT 3 |
|-----|------|------|------|
| 7   | 120 ms | 125 ms | 123 ms |
| 8   | 125 ms | 127 ms | 124 ms |

ping:

| RTT 1 | RTT 2 | RTT 3 | Media |
|------|------|------|-------|
| 122 ms | 124 ms | 121 ms | ~122 ms |

Interpretazione:
- latenza reale elevata  

Motivazioni:
- l’aumento della latenza è persistente nei vari hop e confermato dal ping verso la destinazione  
- il valore dell’RTT riflette il reale tempo di attraversamento end-to-end dei pacchetti  
- il problema non è legato alle risposte ICMP ma al percorso effettivo del traffico  
- possibile presenza di un collegamento WAN ad alta distanza (es. tratte internazionali)  
- possibile attraversamento di più Autonomous Systems con instradamenti non ottimali  
- possibile congestione su uno o più link intermedi  

Ricapitolando: la latenza elevata è reale e dipende dalle caratteristiche del percorso di rete (distanza, instradamento o congestione), non dal comportamento ICMP dei router.

---
## Caso 3: tracert variabile, ping stabile

tracert:

| Hop | RTT 1 | RTT 2 | RTT 3 |
|-----|------|------|------|
| 6   | 40 ms  | 42 ms  | 41 ms  |
| 7   | 150 ms | 155 ms | 152 ms |
| 8   | 45 ms  | 47 ms  | 44 ms  |

ping:

| RTT 1 | RTT 2 | RTT 3 | Media |
|------|------|------|-------|
| 42 ms | 43 ms | 41 ms | ~42 ms |

Interpretazione:
- rete stabile (latenza reale ~42 ms confermata dal ping)  
- RTT elevato all’hop 7 dovuto a risposta ICMP lenta  

Spiegazione:
- il router al hop 7 inoltra i pacchetti normalmente (come dimostrato dall’hop 8 e dal ping)  
- ma risponde lentamente ai messaggi ICMP Time Exceeded  
- ciò può essere dovuto a:
  - bassa priorità ICMP  
  - limitazione (rate limiting)  
  - carico della CPU del router 

---

## Caso 4: ping con perdita

ping:

| RTT 1 | RTT 2 | RTT 3 | Packet Loss |
|------|------|------|-------------|
| 120 ms | 135 ms | 110 ms | 10% |

Interpretazione:
- congestione reale  

Motivazioni:
- la perdita di pacchetti (packet loss) indica che alcuni pacchetti vengono scartati lungo il percorso  
- ciò avviene tipicamente quando i buffer dei router o dei link sono saturi  
- l’aumento e la variabilità dell’RTT indicano ritardi dovuti a code (queueing delay)  
- la congestione può verificarsi su collegamenti WAN o su link tra Autonomous Systems  
- a differenza dei casi precedenti, il problema impatta direttamente il traffico reale (non solo ICMP)  

Ricapitolando: la presenza di packet loss insieme a RTT elevato è un forte indicatore di congestione o saturazione della rete.

---

# Concetti chiave

- tracert → analizza il percorso  
- ping → misura prestazioni reali  
- ICMP non è prioritario  
- RTT degli hop intermedi NON sempre affidabile  
- conta soprattutto l’ultimo hop  

---

# Esercizio: Analisi reale di traceroute

## Testo

Analizzare il seguente output del comando `tracert aruba.it` e rispondere alle domande.

    traceroute to aruba.it (62.149.188.200), 30 hops max, 60 byte packets
    1 _gateway (10.0.40.1) 1.490 ms 1.883 ms 1.875 ms
    2 host-213-82-199-209.business.telecomitalia.it (213.82.199.209) 3.368 ms 6.255 ms 6.249 ms
    3 host-151-99-76-210.business.telecomitalia.it (151.99.76.210) 4.154 ms 6.519 ms 6.513 ms
    4 * * *
    5 * * *
    6 * * *
    7 151.6.0.17 (151.6.0.17) 15.801 ms 7.874 ms 7.988 ms
    8 151.6.7.146 (151.6.7.146) 15.612 ms 16.228 ms 16.516 ms
    9 151.6.6.235 (151.6.6.235) 22.939 ms 22.551 ms 24.487 ms
    10 151.7.32.17 (151.7.32.17) 23.052 ms 21.310 ms 25.548 ms
    11 151.7.32.111 (151.7.32.111) 22.544 ms 21.729 ms 21.668 ms
    12 151.14.36.38 (151.14.36.38) 13.617 ms 13.502 ms 13.618 ms
    13 cr2-be99.it1.aruba.it (62.149.185.240) 15.591 ms 17.690 ms 18.895 ms
    14 er2-hu0-0-0-21.it1.aruba.it (62.149.185.163) 16.853 ms 15.027 ms 16.607 ms
    15 host180-189-149-62.serverdedicati.aruba.it (62.149.189.180) 14.467 ms 12.924 ms 13.312 ms
    16 62.149.188.200 (62.149.188.200) 13.862 ms 15.546 ms 14.835 ms

---

## Domande

1. Identificare:
   - rete locale
   - rete ISP
   - rete di destinazione

2. Spiegare il significato degli hop 4, 5, 6 (* * *)

3. Analizzare l’andamento della latenza lungo il percorso

4. Individuare eventuali anomalie nei valori RTT

5. Stabilire se sono presenti fenomeni di congestione

---

# Soluzione guidata

## 1. Identificazione delle reti

- Hop 1 → rete locale (10.0.40.1, indirizzo privato)
- Hop 2–12 → rete ISP (Telecom Italia / TIM)
- Hop 13–16 → rete Aruba (destinazione)

Il traffico passa dalla LAN all’ISP e successivamente alla rete del provider di destinazione (Aruba), attraversando più Autonomous Systems.

---

## 2. Hop 4–5–6: Request timed out

    4 * * *
    5 * * *
    6 * * *

Interpretazione:
- i router non rispondono a ICMP
- il traffico però continua (hop 7 risponde)

Possibili cause:
- filtraggio ICMP
- firewall
- rate limiting

Non è un errore: i router inoltrano i pacchetti ma non inviano risposta ICMP.

---

## 3. Andamento della latenza

Sintesi:

| Zona | RTT medio |
|------|----------|
| LAN (hop 1) | ~1–2 ms |
| ISP iniziale | ~3–6 ms |
| Backbone ISP | ~15–25 ms |
| Destinazione | ~13–17 ms |

Commento:
- aumento progressivo iniziale → normale
- valori contenuti → rete nazionale
- nessun salto drastico → assenza di tratte internazionali

---

## 4. Anomalie RTT

Caso interessante:


    7 15.801 ms 7.874 ms 7.988 ms


Interpretazione:
- RTT non monotono
- possibile risposta ICMP lenta in una delle misurazioni

Altro caso:

    12 13.6 ms (più basso dei precedenti)

Interpretazione:
- riduzione RTT → NON indica miglioramento reale
- possibile routing differente o risposta ICMP più veloce

Le variazioni non indicano problemi di rete ma comportamento dei router ICMP.

---

## 5. Presenza di congestione

Analisi:
- RTT finale ~14–15 ms → basso e stabile
- nessun packet loss visibile
- nessun RTT elevato persistente

Commento: non ci sono evidenze di congestione. La rete appare stabile ed efficiente.

---

# Conclusione generale

- Il percorso è composto da 16 hop
- Il traffico attraversa:
  - rete locale
  - ISP (Telecom Italia)
  - rete Aruba
- I timeout intermedi sono dovuti a filtraggio ICMP
- La latenza è bassa e stabile
- Non sono presenti fenomeni di congestione

Il traceroute mostra una rete correttamente funzionante, con eventuali anomalie legate esclusivamente alla gestione delle risposte ICMP.