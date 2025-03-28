# Verifica Sistemi e Reti - Classe IVE  Informatico

## Esercizio 1 [50 punti]: esecuzione e analisi output comando `tracert`

Dal prompt dei comandi di Windows, esegui personalmente il seguente comando:

```batch
tracert 8.8.8.8
```

**Domande:**

1. **[6 punti]** Quali sono le specifiche di configurazione IP assegnate al tuo PC (indirizzo IP e subnet mask)? L'indirizzo IP del tuo PC compare nell'output del comando `tracert`? Motiva chiaramente la tua risposta.
2. **[4 punti]** Qual è l'indirizzo IP del gateway della tua rete locale? E la sua subnet mask?
3. **[6 punti]** Osservando i vari hop del percorso, gli indirizzi IP visualizzati sono pubblici o privati? Motiva la risposta indicando chiaramente il criterio utilizzato per distinguerli.
4. **[5 punti]** Perché ciascun hop viene visualizzato con tre diversi valori di tempo (latenza, espressa in `ms`)?
5. **[7 punti]** Quanti router intermedi sono stati attraversati prima di raggiungere la destinazione finale? Giustifica chiaramente la tua risposta indicando il criterio di identificazione dei router nell'output.
6. **[10 punti]** Il comando tracert utilizza il `TTL` (Time To Live) per funzionare correttamente:
    - Spiega dettagliatamente il ruolo del `TTL` nel funzionamento del comando tracert.
    - È possibile conoscere esattamente il valore di TTL impostato nel datagramma IP ricevuto, ad esempio, al 4° hop del percorso? Motiva in modo preciso la tua risposta.
7. **[12 punti]** Analizzando l'output, individua un punto (hop) in cui si nota un significativo aumento della latenza rispetto agli hop precedenti:
    - A cosa potrebbe essere dovuto questo aumento improvviso della latenza?
    - Esegui `whois` sugli indirizzi IP dell'hop precedente e successivo al punto identificato. Questi due indirizzi IP appartengono a compagnie (provider) diverse?
    - Quali conclusioni puoi trarre riguardo al percorso seguito dai pacchetti e al modo in cui i diversi provider influiscono sul valore di latenza?

---

## Esercizio 2 [50 punti]: implementazione schema in Cisco Packet Tracer

Dall'output del comando `tracert 8.8.8.8` ottenuto nell'Esercizio 1, seleziona **gli ultimi 3 router** e la destinazione finale (server DNS Google - `8.8.8.8`).

In Cisco Packet Tracer, realizza uno schema di rete che rappresenti esclusivamente questo ultimo tratto del percorso. In particolare devi:

- Inserire un dispositivo di destinazione finale (edge router finale) con indirizzo IP `8.8.8.8/29`.
- Inserire gli ultimi tre router rilevati nell'output del comando `tracert`.
- Collegare correttamente i router tra loro utilizzando collegamenti Point-to-Point con subnet `/30`.
- Ogni router avrà indirizzi IP coerenti con quelli visualizzati nell'output del tuo comando `tracert`. Dovrai quindi:
  - Indicare chiaramente a quale interfaccia di ciascun router è assegnato l'indirizzo IP che hai osservato nell'output.
  - Calcolare e assegnare correttamente anche l'altro indirizzo IP del collegamento Point-to-Point, che non appare nel risultato del comando ma che risulta necessario alla configurazione dello schema.

**Domanda BONUS [max +5 punti]:**  
Al punto precedente è stato richiesto l'utilizzo di `/30` per i collegamenti Point-to-Point tra router. Tuttavia, nella realtà operativa, sempre più spesso si preferisce utilizzare subnet `/31`.  

- Per quale motivo nella realtà si sceglie di utilizzare subnet `/31` invece che `/30`?  
- Quali vantaggi concreti offre questa scelta rispetto a una subnet `/30`?

## Consegna finale della verifica [eventuali penalità fino a -3 punti]

Al termine degli esercizi, procedi alla consegna nel seguente modo:

- **Esercizio 1**:  
  Produci un documento di testo (`.docx`, `.odt` o `.pdf`) contenente:
  - il risultato completo (screenshot) del tuo comando `tracert 8.8.8.8`.
  - le risposte chiare e numerate alle domande poste nell'Esercizio 1.

- **Esercizio 2** (Schema Cisco Packet Tracer):  
  Realizza e salva un file Cisco Packet Tracer (`.pkt`) con lo schema di rete richiesto.

- Inserisci entrambi i files in una cartella denominata `Cognome-Nome`. Comprimi la cartella generando un unico archivio ZIP denominato `Cognome-Nome.zip`

**Buon lavoro!**
___

## Valutazione

### Esercizio 1 [50 punti]: esecuzione e analisi output comando `tracert`

| Domanda | Punteggio |
|---------|-----------|
| 1       | 6 punti   |
| 2       | 4 punti   |
| 3       | 6 punti   |
| 4       | 5 punti   |
| 5       | 7 punti   |
| 6       | 10 punti  |
| 7       | 12 punti  |
| **Totale** | **50 punti** |

### Esercizio 2 [50 punti]: implementazione schema in Cisco Packet Tracer

| Descrizione | Punteggio |
|-------------|-----------|
| Inserimento e corretto posizionamento degli ultimi 3 router con IP coerenti al tracert | 15 punti |
| Corretto calcolo degli indirizzi IP secondari e relativa subnet mask (`/30`) nei collegamenti Point-to-Point | 20 punti |
| Corretta configurazione del dispositivo finale (router/server con IP `8.8.8.8`) | 10 punti |
| Chiarezza e precisione generale dello schema di rete realizzato | 5 punti |
| **Totale** | **50 punti** |

### Domanda bonus (facoltativa, max +5 punti)

| Descrizione | Punti aggiuntivi |
|---------------|------------------|
| Chiarezza tecnica e vantaggi utilizzo subnet `/31` rispetto `/30` | fino a +5 punti |

### Penalità sulla consegna (max -3 punti)

| Descrizione | Penalità |
|-------------|----------|
| Mancato rispetto delle prescrizioni di consegna (formato file, denominazione archivio ZIP, ecc.) | fino a -3 punti |